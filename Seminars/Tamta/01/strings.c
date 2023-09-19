#include <stdio.h>

void ChangeString(char *s)
{
  s = "World";
}

int main(int argc, char **argv)
{
  char *s = "Hello";
  printf("Original string: %s\n", s);
  ChangeString(s);
  printf("Changed string: %s\n", s);
  return 0;
}