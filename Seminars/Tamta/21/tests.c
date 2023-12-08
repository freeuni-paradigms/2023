#include "dj_school.h"

void TestOneStudentOneTeacher() {
  StartSchool(1, 1);
}

void TestFiveStudentsOneTeacher() {
  StartSchool(3, 5);
}

int main() {
  TestOneStudentOneTeacher();
  TestFiveStudentsOneTeacher();
}
