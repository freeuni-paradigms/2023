#include "sparsestringarray.h"

void SSANew(sparsestringarray *ssa, int arrayLength, int groupSize)
{
	ssa->groupSize = groupSize;
	ssa->arrayLength = arrayLength;
	ssa->numGroups = (ssa->arrayLength - 1) / ssa->groupSize + 1;
	ssa->groups = malloc(ssa->numGroups * sizeof(group));
	memset(ssa->groups, 0, ssa->numGroups * sizeof(group));
}

void SSADispose(sparsestringarray *ssa)
{
	for(int gi=0; gi<ssa->numGroups; gi++){
		group *g = ssa->groups + gi;
		if(g->bitmap == NULL) continue;
		free(g->bitmap);
		VectorDispose(&g->vector);
	}
	free(ssa->groups);
}


// void VectorNew(vector *v, int elemSize, VectorFreeFunction freefn, int initialAllocation);

void strfree(void *elemPtr) {
	char **s  = elemPtr;
	free(*s);
}

bool SSAInsert(sparsestringarray *ssa, int index, const char *str)
{
	int gi = index / ssa->groupSize;
	group *g = ssa->groups + gi;
	if(g->bitmap == NULL){
		g->bitmap = malloc(ssa->groupSize * sizeof(bool));
		memset(g->bitmap, 0, ssa->groupSize * sizeof(bool));
		VectorNew(&g->vector, sizeof(char*), strfree, 1);
	}
	
	int i = index % ssa->groupSize;
	int vi=0;
	for(int j=0; j<i; j++){
		vi+=g->bitmap[j];
	}
	char *s = strdup(str);
	if(g->bitmap[i]) {
		// exists
		VectorReplace(&g->vector, &s, vi);
	} else {
		// new
		VectorInsert(&g->vector, &s, vi);
	}
	bool did_exist = g->bitmap[i];
	g->bitmap[i] = 1;
	return !did_exist;
}

void SSAMap(sparsestringarray *ssa, SSAMapFunction mapfn, void *auxData)
{
	
	char *emptys = strdup("");
	for(int gi=0; gi<ssa->numGroups; gi++){
		group *g = ssa->groups + gi;
		if(g->bitmap == NULL) {
			for(int i=0; i<ssa->groupSize; i++)
				mapfn(gi * ssa->groupSize + i, emptys, auxData);
		} else {
			int vi=0;
			for(int i=0; i<ssa->groupSize; i++) {
				if(g->bitmap[i]){
					// non-empty
					char *s = *(char **)VectorNth(&g->vector, vi);
					mapfn(gi * ssa->groupSize + i, s, auxData);
					vi++;
				} else {
					mapfn(gi * ssa->groupSize + i, emptys, auxData);
				}
			}
		}
	}
	free(emptys);
}
