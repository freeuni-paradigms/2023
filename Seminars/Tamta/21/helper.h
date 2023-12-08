#include <stdbool.h>

bool TeacherEvaluateStudent(int teacher_id, int student_id);

void TeacherDone(int teacher_id);

void StudentRecordSet(int student_id);

void StudentDone(int student_id);

void StudentWasEvaluatedByTeacher(int student_id, int teacher_id, bool set_was_good);

void SchoolEnd();
