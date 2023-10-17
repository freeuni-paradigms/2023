#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int x;
  char* s;
} Foo;

/* void NoOpFree(void* ptr) { */
/* } */

void StackInt() {
  Stack s;
  StackInit(&s, sizeof(int), NULL);
  for (int i = 0; i < 5; ++i) {
	StackPush(&s, &i);
  }
  assert(StackSize(&s) == 5);
  // void* value = malloc(sizeof(int));
  // int value;
  for (int i = 0; i < 3; ++i) {
	int value;
	StackPop(&s, &value);
	printf("%d\n", value);
  }
  // free(value);
  assert(StackSize(&s) == 2);
  StackDestroy(&s);
}

/* void StackDouble() { */
/*   Stack s; */
/*   StackInit(&s, sizeof(double)); */
/*   for (int i = 0; i < 5; ++i) { */
/* 	double x = i * i * 2.5; */
/* 	StackPush(&s, &x); */
/*   } */
/*   assert(StackSize(&s) == 5); */
/*   // void* value = malloc(sizeof(int)); */
/*   // int value; */
/*   for (int i = 0; i < 5; ++i) { */
/* 	double value; */
/* 	StackPop(&s, &value); */
/* 	printf("%f\n", value); */
/*   } */
/*   // free(value); */
/*   assert(StackSize(&s) == 0); */
/*   StackDestroy(&s); */
/* } */

void StrFree(void* ptr) {
  free(*(char**)ptr);
}

void StackString() {
  Stack s;
  StackInit(&s, sizeof(char*), StrFree);
  for (int i = 0; i < 150; ++i) {
	char* str = malloc(10);
	sprintf(str, "hi %d", i);
	StackPush(&s, &str);
  }
  assert(StackSize(&s) == 150);
  // void* value = malloc(sizeof(int));
  // int value;
  for (int i = 0; i < 100; ++i) {
	char* str;
	StackPop(&s, &str);
	printf("%s\n", str);
	// free(str);
	StrFree(&str);
  }
  // free(value);
  assert(StackSize(&s) == 50);
  StackDestroy(&s);
}

void FooFree(void* ptr) {
  // IMPLEMENT
}

int main(int argc, char** argv) {
  // StackString();
  // StackInt();
  Foo f;
  f.x = 5;
  f.s = strdup("123123");
  Stack s;
  StackInit(&s, sizeof(Foo), FooFree);
  StackPush(&s, &f);
  StackDestroy(&s);
  return 0;
}
