#include <stdbool.h>
#include <stdio.h>

// 47000 47000

bool HaveDifferentSigns(int x, int y)
{
  return (x * y) < 0;
  // return (x < 0 && y > 0) || (x > 0 && y < 0);
}

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