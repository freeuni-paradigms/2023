#include "helper.h"

#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_NUM_TEACHERS 10
#define MAX_NUM_STUDENTS 100

int students_left;
sem_t teacher_done_sem;
int teachers_num;
sem_t wait_for_teacher;
pthread_mutex_t students_left_lock;

typedef struct {
  int teacher_id;
  bool available;
  pthread_mutex_t lock;
  sem_t start_work;
  sem_t end_work;
  int cur_student_id;
  bool cur_student_mark;
} TeacherArgs;

TeacherArgs teacher_args[MAX_NUM_TEACHERS];

void* Teacher(void* args) {
  int id = *(int*)args;
  // IMPLEMENT
  while (true) {
    // wait for student to signal
    sem_wait(&teacher_args[id].start_work);

    // check if all students are done and we should end
    pthread_mutex_lock(&students_left_lock);
    if (students_left == 0) {
      pthread_mutex_unlock(&students_left_lock);
      break;
    }
    pthread_mutex_unlock(&students_left_lock);

    bool mark = TeacherEvaluateStudent(id, teacher_args[id].cur_student_id);
    teacher_args[id].cur_student_mark = mark;

    // signal student that mark is written
    sem_post(&teacher_args[id].end_work);
  }
  TeacherDone(id);
  sem_post(&teacher_done_sem);
  return NULL;
}

void* Student(void* args) {
  int id = *(int*)args;
  bool mark = false;
  while (!mark) {
    int teacher_id = -1;
    StudentRecordSet(id);

    // if no teachers are available wait for them
    sem_wait(&wait_for_teacher);
    // search for an available teacher
    for (size_t i = 0; i < teachers_num; i++)
    {
      pthread_mutex_lock(&teacher_args[i].lock);
      if(!teacher_args[i].available){
        pthread_mutex_unlock(&teacher_args[i].lock);
        continue;
      }
      teacher_args[i].available = false;
      pthread_mutex_unlock(&teacher_args[i].lock);
      teacher_args[i].cur_student_id = id;
      teacher_id = i;
      break;
    }

    // signal for teacher to evaluate me and wait
    sem_post(&teacher_args[teacher_id].start_work);
    sem_wait(&teacher_args[teacher_id].end_work);
    
    // update mark and make teacher available
    mark = teacher_args[teacher_id].cur_student_mark;
    pthread_mutex_lock(&teacher_args[teacher_id].lock);
    teacher_args[teacher_id].available = true;
    pthread_mutex_unlock(&teacher_args[teacher_id].lock);

    // one more teacher is available
    sem_post(&wait_for_teacher);

    StudentWasEvaluatedByTeacher(id, teacher_id, mark);
  }
  StudentDone(id);

  pthread_mutex_lock(&students_left_lock);
  students_left--;
  if(students_left == 0) {
    // signal all teachers to start work, they'll check that no more students are left and end
    for(int i = 0; i < teachers_num; i++){
      sem_post(&teacher_args[i].start_work);
    }
  }
  pthread_mutex_unlock(&students_left_lock);

  return NULL;
}

void StartSchool(int num_students, int num_teachers) {
  // IMPLEMENT: Initialize semaphores and mutexes if needed.
  int teacher_id[MAX_NUM_TEACHERS];
  int student_id[MAX_NUM_STUDENTS];
  teachers_num = num_teachers;
  students_left = num_students;
  sem_init(&teacher_done_sem, 0, 0);
  sem_init(&wait_for_teacher, 0, num_teachers);
  pthread_mutex_init(&students_left_lock, NULL);
  for (int i = 0; i < num_teachers; ++i) {
    teacher_id[i] = i;
    pthread_t tid;
    teacher_args[i].teacher_id = tid;
    teacher_args[i].available = true;
    pthread_mutex_init(&teacher_args[i].lock, NULL);
    sem_init(&teacher_args[i].start_work, 0, 0);
    sem_init(&teacher_args[i].end_work, 0, 0);
    pthread_create(&tid, NULL, Teacher, &teacher_id[i]);
    pthread_detach(tid);
  }
  for (int i = 0; i < num_students; ++i) {
    student_id[i] = i;
    pthread_t tid;
    pthread_create(&tid, NULL, Student, &student_id[i]);
    pthread_detach(tid);
  }

  // Wait for all students and teachers to finish.
  for (size_t i = 0; i < num_teachers; i++)
  {
    sem_wait(&teacher_done_sem);
  }
  
  SchoolEnd();
}
