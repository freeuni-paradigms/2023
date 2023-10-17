#include "sortedset.h"
#include "stdio.h"
/*
* Function: SetNew
* Usage: SetNew(&stringSet, sizeof(char *), StringPtrCompare);
*
SetNew(&constellations, sizeof(pointT), DistanceCompare);
* ----------------
* SetNew allocates the requisite space needed to manage what
* will initially be an empty sorted set. More specifically, the
* routine allocates space to hold up to 'kInitialCapacity' (currently 4)
* client elements.
*/
static const int kInitialCapacity = 4;
void SetNew(sortedset *set, int elemSize, int (*cmpfn)(const void *, const void *), void (*freefn)(const void *))
{
    assert(elemSize > 0);
    assert(cmpfn != NULL);

    set->elemSize = elemSize;
    set->logLen = 0;
    set->allocLen = kInitialCapacity;
    set->cmpfn = cmpfn;
    set->freefn = freefn;
    set->nodeSize = elemSize + 2 * sizeof(int);
    
    set->base = malloc(set->allocLen * set->nodeSize + sizeof(int));
    assert(set->base != NULL);
    *set->base = -1;
}

/*
* Function: SetSearch
* Usage: if (SetSearch(&staffSet, &lecturer) == NULL)
*
printf("musta been fired");
* -------------------
* SetSearch searches for the specified client element according
* the whatever comparison function was provided at the time the
* set was created. A pointer to the matching element is returned
* for successful searches, and NULL is returned to denote failure.
*/
void *SetSearch(sortedset *set, const void *elemPtr)
{
    int* idx_ptr = FindNode(set, elemPtr);
    if(*idx_ptr == -1) 
        return NULL;
    
    void* found_elem = (void*)((char*)set->base + sizeof(int) + *idx_ptr * set->nodeSize);
    return found_elem;
}
/*
* Function: SetAdd
* Usage: if (!SetAdd(&friendsSet, &name)) free(name);
* ----------------
* Adds the specified element to the set if not already present.
* present, the client element is not copied into the set. true
* is returned if and only if the element at address elemPtr
* was copied into the set.
*/
bool SetAdd(sortedset *set, const void *elemPtr)
{
    int* idx_ptr = FindNode(set, elemPtr);

    if(*idx_ptr != -1) {
        return false;
    }

    if (set->logLen >= set->allocLen) {
        set->allocLen *= 2;
        set->base = realloc(set->base, set->allocLen * set->nodeSize + sizeof(int));
        assert(set->base != NULL);
    }
    void* dest = (void*)((char*)set->base + sizeof(int) + set->logLen * set->nodeSize);
    memcpy(dest, elemPtr, set->elemSize);

    *idx_ptr = set->logLen;
    set->logLen++;

    int* left_child = (int*) ((char*)dest + set->elemSize);
    int* right_child = (int*) ((char*)dest + set->elemSize + sizeof(int));
    *left_child = -1;
    *right_child = -1;

    return true;
}

/**
* Function: FindNode
* Usage: ip = FindNode(set, elem);
*
if (*ip == -1) printf("ip points where this element belongs!");
* ------------------
* FindNode descends through the underlying binary search tree of the
* specified set and returns the address of the offset into raw storage
* where the specified element resides. If the specified element isn't
* in the set, FindNode returns the address of the –1 that would be updated
* to contain the index of the element being sought if it were the
* element to be inserted——that is, the address of the –1 that ended
* the search.
*/
static int *FindNode(sortedset *set, const void *elem)
{
    int* cur_idx = set->base;
    
    while(*cur_idx != -1) {
        char* cur_elem = (char*)set->base + sizeof(int) + *cur_idx * set->nodeSize;
        int result = set->cmpfn(cur_elem, elem);

        if (result < 0) {
            // go to right tree
            cur_idx = cur_elem + set->elemSize + sizeof(int);
        } else if (result == 0) {
            return cur_idx;
        } else if (result > 0) {
            // go to left tree
            cur_idx = cur_elem + set->elemSize;
        }
    }    

    return cur_idx;
}

void destruct(sortedset *set)
{
    if (set->freefn != NULL) {
        for(int i = 0; i < set->logLen; i++) {
            char* elem = (char*)set->base + sizeof(int) + i*set->nodeSize;
            set->freefn(elem);
        }
    }
    free(set->base);
}