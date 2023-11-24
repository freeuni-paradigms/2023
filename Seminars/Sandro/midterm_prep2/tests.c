#include "sorted_multi_set.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

#define ASSERT(expr) {							\
    if (!(expr)) {							\
    printf("%s:%d: Assertion failed: %s\n", __FILE__, __LINE__, #expr);	\
    return false;							\
  }									\
}

#define TEST(name) bool Test##name()

#define RUN_TEST(name)                                                         \
  printf("++ RUNNING TEST: %s\n", #name);                                      \
  if (Test##name()) {                                                          \
    printf("-- TEST %s: SUCCEEDED\n", #name);                                  \
  } else {                                                                     \
    printf("-- TEST %s: FAILED\n", #name);                                     \
  }                                                                            \
  printf("\n");

int IntCmp(void* a, void* b) {
  return *(int*)a - *(int*)b;
}

TEST(Integers_Unique_Insert_Get) {
  SortedMultiSet s;
  SortedMultiSetInit(&s, sizeof(int), IntCmp, /*free_fn=*/NULL);
  int x = 1, y = 2, z = 3;

  ASSERT(0 == SortedMultiSetInsert(&s, &x));
  ASSERT(1 == *(int*)SortedMultiSetGet(&s, 0));

  ASSERT(1 == VectorSize(&s.v));

  ASSERT(1 == SortedMultiSetInsert(&s, &z));
  ASSERT(3 == *(int*)SortedMultiSetGet(&s, 1));

  ASSERT(2 == VectorSize(&s.v));

  ASSERT(1 == SortedMultiSetInsert(&s, &y));
  ASSERT(2 == *(int*)SortedMultiSetGet(&s, 1));
  ASSERT(1 == *(int*)SortedMultiSetGet(&s, 0));
  ASSERT(3 == *(int*)SortedMultiSetGet(&s, 2));

  ASSERT(3 == VectorSize(&s.v));

  SortedMultiSetDestroy(&s);
  return true;
}

TEST(Integers_Unique_GetCount) {
  SortedMultiSet s;
  SortedMultiSetInit(&s, sizeof(int), IntCmp, /*free_fn=*/NULL);
  int x = 1, y = 2, z = 3;
  int a = 1, b = 2, c = 3;

  ASSERT(0 == SortedMultiSetInsert(&s, &x));
  ASSERT(1 == *(int*)SortedMultiSetGet(&s, 0));
  ASSERT(1 == SortedMultiSetGetCount(&s, &a));

  ASSERT(1 == VectorSize(&s.v));

  ASSERT(1 == SortedMultiSetInsert(&s, &z));
  ASSERT(3 == *(int*)SortedMultiSetGet(&s, 1));
  ASSERT(1 == SortedMultiSetGetCount(&s, &c));

  ASSERT(2 == VectorSize(&s.v));

  ASSERT(1 == SortedMultiSetInsert(&s, &y));
  ASSERT(2 == *(int*)SortedMultiSetGet(&s, 1));
  ASSERT(1 == *(int*)SortedMultiSetGet(&s, 0));
  ASSERT(3 == *(int*)SortedMultiSetGet(&s, 2));

  ASSERT(1 == SortedMultiSetGetCount(&s, &a));
  ASSERT(1 == SortedMultiSetGetCount(&s, &b));
  ASSERT(1 == SortedMultiSetGetCount(&s, &c));

  ASSERT(3 == VectorSize(&s.v));

  SortedMultiSetDestroy(&s);
  return true;
}

TEST(Integers_Duplicates) {
  SortedMultiSet s;
  SortedMultiSetInit(&s, sizeof(int), IntCmp, /*free_fn=*/NULL);
  int x = 1, y = 2, z = 3;
  int a = 1, b = 2, c = 3;

  ASSERT(0 == SortedMultiSetInsert(&s, &x));
  ASSERT(1 == *(int*)SortedMultiSetGet(&s, 0));
  ASSERT(1 == SortedMultiSetGetCount(&s, &a));

  ASSERT(1 == VectorSize(&s.v));

  ASSERT(0 == SortedMultiSetInsert(&s, &x));
  ASSERT(1 == *(int*)SortedMultiSetGet(&s, 0));
  ASSERT(2 == SortedMultiSetGetCount(&s, &a));

  ASSERT(1 == VectorSize(&s.v));

  ASSERT(1 == SortedMultiSetInsert(&s, &z));
  ASSERT(3 == *(int*)SortedMultiSetGet(&s, 1));
  ASSERT(1 == SortedMultiSetGetCount(&s, &c));

  ASSERT(2 == VectorSize(&s.v));

  ASSERT(1 == SortedMultiSetInsert(&s, &y));
  ASSERT(2 == *(int*)SortedMultiSetGet(&s, 1));
  ASSERT(1 == *(int*)SortedMultiSetGet(&s, 0));
  ASSERT(3 == *(int*)SortedMultiSetGet(&s, 2));

  ASSERT(2 == SortedMultiSetInsert(&s, &z));
  ASSERT(3 == *(int*)SortedMultiSetGet(&s, 2));
  ASSERT(2 == SortedMultiSetGetCount(&s, &c));

  ASSERT(2 == SortedMultiSetInsert(&s, &z));
  ASSERT(3 == *(int*)SortedMultiSetGet(&s, 2));
  ASSERT(3 == SortedMultiSetGetCount(&s, &c));

  ASSERT(2 == SortedMultiSetGetCount(&s, &a));
  ASSERT(1 == SortedMultiSetGetCount(&s, &b));
  ASSERT(3 == SortedMultiSetGetCount(&s, &c));

  ASSERT(3 == VectorSize(&s.v));

  SortedMultiSetDestroy(&s);
  return true;
}

typedef struct {
  char x;
  short y;
} Pair;

Pair NewPair(char x, short y) {
  Pair p;
  p.x = x;
  p.y = y;
  return p;
}

int PairCmp(void* a, void* b) {
  Pair* p = a;
  Pair* q = b;
  if (p->x != q->x) {
    return p->x - q->x;
  }
  return p->y - q->y;
}

TEST(Pairs) {
  SortedMultiSet s;
  SortedMultiSetInit(&s, sizeof(Pair), PairCmp, /*free_fn=*/NULL);
  Pair p = NewPair('a', 2);
  Pair q = NewPair('b', 1);
  Pair w = NewPair('a', 1);
  Pair a = NewPair('a', 2);
  Pair b = NewPair('b', 1);
  Pair c = NewPair('a', 1);

  ASSERT(0 == SortedMultiSetInsert(&s, &q));
  ASSERT(0 == PairCmp(&b, (Pair*)SortedMultiSetGet(&s, 0)));
  ASSERT(1 == SortedMultiSetGetCount(&s, &b));
  ASSERT(1 == VectorSize(&s.v));

  ASSERT(0 == SortedMultiSetInsert(&s, &w));
  ASSERT(0 == PairCmp(&c, (Pair*)SortedMultiSetGet(&s, 0)));
  ASSERT(1 == SortedMultiSetGetCount(&s, &c));
  ASSERT(2 == VectorSize(&s.v));

  ASSERT(1 == SortedMultiSetInsert(&s, &q));
  ASSERT(0 == PairCmp(&b, (Pair*)SortedMultiSetGet(&s, 1)));
  ASSERT(2 == SortedMultiSetGetCount(&s, &b));
  ASSERT(2 == VectorSize(&s.v));

  ASSERT(1 == SortedMultiSetInsert(&s, &p));
  ASSERT(0 == PairCmp(&a, (Pair*)SortedMultiSetGet(&s, 1)));
  ASSERT(1 == SortedMultiSetGetCount(&s, &a));
  ASSERT(3 == VectorSize(&s.v));

  ASSERT(0 == SortedMultiSetInsert(&s, &w));
  ASSERT(0 == PairCmp(&c, (Pair*)SortedMultiSetGet(&s, 0)));
  ASSERT(2 == SortedMultiSetGetCount(&s, &c));
  ASSERT(3 == VectorSize(&s.v));

  Pair unknown = NewPair('u', 5);
  ASSERT(0 == SortedMultiSetGetCount(&s, &unknown));

  SortedMultiSetDestroy(&s);
  return true;
}

int StrCmp(void* a, void* b) {
  char* x = *(char**)a;
  char* y = *(char**)b;
  if (strlen(x) != strlen(y)) {
    return strlen(x) - strlen(y);
  }
  return strcmp(x, y);
}

void StrFree(void* a) {
  free(*(char**)a);
}

TEST(Strings) {
  SortedMultiSet s;
  SortedMultiSetInit(&s, sizeof(char*), StrCmp, StrFree);

  for (int i = 100; i < 1000; ++i) {
    char t[10];
    sprintf(t, "%d", i);
    char* x = strdup(t);
    ASSERT(i - 100 == SortedMultiSetInsert(&s, &x));
    ASSERT(0 == strcmp(t, *(char**)SortedMultiSetGet(&s, i - 100)));
    char* y = t;
    ASSERT(1 == SortedMultiSetGetCount(&s, &y));
    ASSERT(i - 99 == VectorSize(&s.v));
  }

  for (int i = 999; i > 99; --i) {
    char t[10];
    sprintf(t, "%d", i);
    char* x = strdup(t);
    ASSERT(i - 100 == SortedMultiSetInsert(&s, &x));
    ASSERT(0 == strcmp(t, *(char**)SortedMultiSetGet(&s, i - 100)));
    char* y = t;
    ASSERT(2 == SortedMultiSetGetCount(&s, &y));
    ASSERT(900 == VectorSize(&s.v));
  }

  char* unknown = "foo";
  ASSERT(0 == SortedMultiSetGetCount(&s, &unknown));

  SortedMultiSetDestroy(&s);
  return true;
}


int main(int argc, char **argv) {
  RUN_TEST(Integers_Unique_Insert_Get);
  RUN_TEST(Integers_Unique_GetCount);
  RUN_TEST(Integers_Duplicates);

  RUN_TEST(Pairs);

  RUN_TEST(Strings);

  return 0;
}
