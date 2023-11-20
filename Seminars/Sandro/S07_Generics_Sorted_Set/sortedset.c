#include "sortedset.h"


int BaseSize(sortedset *set) {
	return set->alloc_n*(set->elemSize + 2*sizeof(int)) + sizeof(int);
}

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
static const int kInitialCapacity = 5;
void SetNew(sortedset *set, int elemSize, 
		int (*cmpfn)(const void *, const void *), 
		void (*freefn)(const void *))
{
	set->elemSize = elemSize;
	set->cmpfn = cmpfn;
	set->freefn = freefn;
	set->logic_n = 0;
	set->alloc_n = kInitialCapacity;
	set->base = malloc(BaseSize(set));
	*(int*)set->base = -1;
}


// sortedset ss;
// SetNew(&ss)


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
	int *index_ptr = FindNode(set, elemPtr); // &1
	if(*index_ptr != -1){ // alrady in set
		int found_idx = *index_ptr; // 1
		return set->base + sizeof(int) + found_idx*(set->elemSize + 2*sizeof(int));
	} else {
		return NULL;
	}
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
	int *index_ptr = FindNode(set, elemPtr);
	if(*index_ptr != -1){ // alrady in set
		return false;
	}
	if(set->logic_n == set->alloc_n) { // no space for new node
		set->alloc_n*=2;
		set->base = realloc(set->base, BaseSize(set));
	}
	int new_idx = set->logic_n;
	set->logic_n++;
	// TODO: check if there is space
	// create new node
	char *new_node_ptr = set->base + sizeof(int) + new_idx*(set->elemSize + 2*sizeof(int));
	memcpy(new_node_ptr, elemPtr, set->elemSize); // copy T
	int *child_idxs = new_node_ptr + set->elemSize;
	child_idxs[0] = -1;
	child_idxs[1] = -1;

	// set node as child
	*index_ptr = new_idx;
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
	int cur_idx = *(int*)set->base; //0 -1
	int *last_idx_ptr = set->base;
	while(true){
		if(cur_idx == -1){ // root
			return last_idx_ptr;
		}
		char *cur = ((char*)set->base) + sizeof(int) + (set->elemSize + 2*sizeof(int))*(cur_idx);
		int res= set->cmpfn(cur, elem);
		// if < -1
		// if == 0
		// if > +1
		if(res==0){
			return last_idx_ptr;
		}
		if(res<0){ // right
			cur+=set->elemSize + sizeof(int);
			cur_idx = *(int*)cur;
			last_idx_ptr = cur;
		}
		if(res>0){ // left
			cur+=set->elemSize;
			cur_idx = *(int*)cur;
			last_idx_ptr = cur;
		}
	}
	assert(0);
}

void destruct(sortedset *set)
{
	if(set->freefn) {
		for(int i=0; i<set->logic_n; i++){
			set->freefn(set->base + sizeof(int) + i*(set->elemSize + 8));
		}
	}
	free(set->base);
}
