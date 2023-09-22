#include <stdio.h>

void SomeCalculation()
{
  int a[10];
  int b = 5;
  printf("Value of b: %d\n", b);
  for (int i = 9; i >= -2; --i)
  {
    a[i] = i;
  }
  printf("Value of b: %d\n", b);
  printf("Address of a: %lu\n", a);
  printf("Address of b: %lu\n", &b);
  printf("Size of int in bytes: %lu\n", sizeof(int));
}

int main(int argc, char **argv)
{
  SomeCalculation();
  return 0;
}