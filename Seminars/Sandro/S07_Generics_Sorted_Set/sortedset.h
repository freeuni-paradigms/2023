#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
	void *base; 
	// sizeof(int) + alloc_n*(elemSize + 2*sizeof(int))
	int logic_n;
	int alloc_n;
	// user defined:
	int elemSize;
	int (*cmpfn)(const void *, const void *);
	void (*freefn)(const void *);
} sortedset;

void SetNew(sortedset *set, 
		int elemSize, 
		int (*cmpfn)(const void *, const void *), 
		void (*freefn)(const void *));
bool SetAdd(sortedset *set, const void *elemPtr);
void *SetSearch(sortedset *set, const void *elemPtr);
static int *FindNode(sortedset *set, const void *elem);
