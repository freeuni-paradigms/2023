#include "helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool TeacherEvaluateStudent(int teacher_id, int student_id) {
  sleep(rand() % 5);
  bool good = (rand() % 10) > 6;
  printf("Teacher %d is evaluating student %d with result %s\n", teacher_id, student_id, good ? "GOOD" : "BAD");
  return good;
}

void TeacherDone(int teacher_id) {
  sleep(rand() % 5);
  printf("Teacher %d: DONE\n", teacher_id);
}

void StudentRecordSet(int student_id) {
  sleep(rand() % 5);
  printf("Student %d recorded new set\n", student_id);
}

void StudentDone(int student_id) {
  sleep(rand() % 5);
  printf("Student %d: DONE\n", student_id);
}

void StudentWasEvaluatedByTeacher(int student_id, int teacher_id, bool set_was_good) {
  sleep(rand() % 5);
  printf("Student %d got evaluation result from teacher %d: %s\n", student_id, teacher_id, set_was_good ? "GOOD" : "BAD");
}

void SchoolEnd() {
  printf("School finished.\n");
}
