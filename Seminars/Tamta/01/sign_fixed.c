#include <stdbool.h>
#include <stdio.h>

bool HaveDifferentSigns(int x, int y) { return (x ^ y) < 0; }

int main(int argc, char **argv)
{
  printf("Enter two integers:\n");
  int x, y;
  scanf("%d %d", &x, &y);
  if (HaveDifferentSigns(x, y))
  {
    printf("Given integers have different signs.\n");
  }
  else
  {
    printf("Given integers have same sign.\n");
  }
  return 0;
}