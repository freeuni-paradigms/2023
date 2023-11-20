#include "sparsestringarray.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ASSERT(expr) {							\
  if (!(expr)) {								\
    printf("%s:%d: Assertion failed: %s\n", __FILE__, __LINE__, #expr);	\
    return false;							\
  }									\
}


// Helper functions and structs

typedef struct {
	int index;
	char * str;
} elem;

void saveLastElem(int index, const char *str, void *auxData) {
	if (strcmp(str, "") == 0) return;

	elem * ptr = auxData;
	ptr->index = index;
	ptr->str = strdup(str);
}

void increaseCounter(int index, const char *str, void *auxData) {
	if (strcmp(str, "") == 0) return;
	
	int * ptr = auxData;
	(*ptr)++;
}

void increaseSymbolsCounter(int index, const char * str, void *auxData) {
	int * ptr = auxData;
	(*ptr) += strlen(str);
}

// Tests 

bool Create_Dispose() {
	sparsestringarray ssa;
	SSANew(&ssa, 1000, 100);
	SSADispose(&ssa);
	return true;
}

bool Insert_Same_Index() {
	sparsestringarray ssa;
	SSANew(&ssa, 1000, 100);

	ASSERT(SSAInsert(&ssa, 20, "one") == true);
	ASSERT(SSAInsert(&ssa, 20, "two") == false);

	SSADispose(&ssa);
	return true;
}

bool Insert_Different_Indexes() {
	sparsestringarray ssa;
	SSANew(&ssa, 1000, 100);

	ASSERT(SSAInsert(&ssa, 20, "one") == true);
	ASSERT(SSAInsert(&ssa, 21, "two") == true);

	ASSERT(SSAInsert(&ssa, 100, "three") == true);
	ASSERT(SSAInsert(&ssa, 102, "one") == true);

	ASSERT(SSAInsert(&ssa, 0, "first") == true);
	ASSERT(SSAInsert(&ssa, 999, "last") == true);

	SSADispose(&ssa);
	return true;
}

bool Insert_Elems() {
	sparsestringarray ssa;
	SSANew(&ssa, 100, 25);

	for (int i = 0; i < 100; i++) {
		ASSERT(SSAInsert(&ssa, i, "elem") == true);
	}

	SSADispose(&ssa);
	return true;	
}

bool Map_One_Elem() {
	sparsestringarray ssa;
	SSANew(&ssa, 1000, 100);

	int index = 20;
	char * str = "one";
	SSAInsert(&ssa, index, str);

	elem e;
	SSAMap(&ssa, saveLastElem, &e);

	ASSERT(e.index == index);
	ASSERT(strcmp(e.str, str) == 0);

	SSADispose(&ssa);
	return true;
}

bool Calculate_Num_Elems() {
	sparsestringarray ssa;
	SSANew(&ssa, 1000, 50);

	int numElems = 20;
	int index = 0;
	for (int i = 0; i < numElems; i++) {
		SSAInsert(&ssa, index, "elem");
		index += 15;
	}

	int counter = 0;
	SSAMap(&ssa, increaseCounter, &counter);
	ASSERT(counter == numElems);
	
	SSADispose(&ssa);
	return true;
}

bool Replace_Elem() {
	sparsestringarray ssa;
	SSANew(&ssa, 200, 50);

	int index = 20;
	char * lastAdded = "elem3";
	SSAInsert(&ssa, index, "elem1");
	SSAInsert(&ssa, index, "elem2");
	SSAInsert(&ssa, index, lastAdded);

	elem e;
	SSAMap(&ssa, saveLastElem, &e);

	ASSERT(e.index == index);
	ASSERT(strcmp(e.str, lastAdded) == 0);

	SSADispose(&ssa);
	return true;
}

bool Calculate_Num_Chars() {
	sparsestringarray ssa;
	SSANew(&ssa, 200, 50);

	int numChars = 15;
	SSAInsert(&ssa, 21, "one");
	SSAInsert(&ssa, 50, "two");
	SSAInsert(&ssa, 102, "three");
	SSAInsert(&ssa, 188, "four");

	int counter = 0;
	SSAMap(&ssa, increaseSymbolsCounter, &counter);

	ASSERT(counter == numChars);

	SSADispose(&ssa);
	return true;
}

bool Calculate_Num_Elems2() {
	sparsestringarray ssa;
	SSANew(&ssa, 200, 50);

	int numElems = 3;
	SSAInsert(&ssa, 21, "one");
	SSAInsert(&ssa, 50, "two");
	SSAInsert(&ssa, 21, "three");
	SSAInsert(&ssa, 21, "four");
	SSAInsert(&ssa, 50, "five");
	SSAInsert(&ssa, 102, "six");

	int counter = 0;
	SSAMap(&ssa, increaseCounter, &counter);

	ASSERT(counter == numElems);

	SSADispose(&ssa);
	return true;
}

void Test(char* name, bool(*test_fn)()) {
  printf("++ RUNNING TEST: %s\n", name);
  if (test_fn()) {
    printf("-- TEST %s: SUCCEEDED\n", name);
  } else {
    printf("-- TEST %s: FAILED\n", name);
  }
  printf("\n");
}

int main() {
	Test("Creates SSA", Create_Dispose);
	Test("Inserts two strings at the same index", Insert_Same_Index);
	Test("Inserts several strings at the different indexes", Insert_Different_Indexes);
	Test("Inserts strings at every position", Insert_Elems);
	Test("Adds one string to SSA and maps over it", Map_One_Elem);
	Test("Calculates number of strings in SSA with SSAMap function", Calculate_Num_Elems);
	Test("Adds three strings at the same index and checks if last string is saved", Replace_Elem);
	Test("Calculates overall number of symbols in SSA with SSAMap function", Calculate_Num_Chars);
	Test("Inserts strings at the same indexes and calculates number of elems in SSA", Calculate_Num_Elems2);

	return 0;
}
