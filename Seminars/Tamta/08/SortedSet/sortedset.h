#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int* base;
    int logLen;
    int allocLen;
    int (*cmpfn)(const void *, const void *);
    void (*freefn)(const void *);
    int elemSize;
    int nodeSize;
} sortedset;

void SetNew(sortedset *set, int elemSize, int (*cmpfn)(const void *, const void *), void (*freefn)(const void *));
bool SetAdd(sortedset *set, const void *elemPtr);
void *SetSearch(sortedset *set, const void *elemPtr);
static int *FindNode(sortedset *set, const void *elem);