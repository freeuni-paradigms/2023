#include "sparsestringarray.h"

static void StringFree(void *elem) { free(*(char **)elem); }
void SSANew(sparsestringarray *ssa, int arrayLength, int groupSize)
{
    assert(arrayLength != 0);
    ssa->arrayLength = arrayLength;
    ssa->groupSize = groupSize;
    ssa->numGroups = (ssa->arrayLength - 1) / ssa->groupSize + 1;
    
    ssa->groups = malloc(ssa->numGroups * sizeof(group));
    for(int i = 0; i < ssa->numGroups; i++) {
        ssa->groups[i].bitmap = malloc(sizeof(bool) * ssa->groupSize);
        bzero(ssa->groups[i].bitmap, groupSize * sizeof(bool)); // init bitmap with zeros
        VectorNew(&ssa->groups[i].strings, sizeof(char*), StringFree, 1);
    }
}

void SSADispose(sparsestringarray *ssa)
{
    for(int i = 0; i < ssa->numGroups; i++) {
        group curGroup = ssa->groups[i];
        free(curGroup.bitmap);
        VectorDispose(&curGroup.strings);
    }
    free(ssa->groups);
   
}

bool SSAInsert(sparsestringarray *ssa, int index, const char *str)
{   
    assert(index > 0 && index < ssa->arrayLength);
    bool firstElem = true;
    int groupIndex = index / ssa->groupSize;
    int bitmapIndex = index % ssa->groupSize;
    
    group curGroup = ssa->groups[groupIndex];

    int elemCount = 0;
    for(int i = 0; i < bitmapIndex; i++) {
        if (curGroup.bitmap[i])
            elemCount++;
    }

    if (curGroup.bitmap[bitmapIndex]) { // index already present in array
        firstElem = false;
        VectorReplace(&curGroup.strings, &str, elemCount);
    } else {
        VectorInsert(&curGroup.strings, &str, elemCount);
    }
    curGroup.bitmap[bitmapIndex] = 1;

    return firstElem;
}

void SSAMap(sparsestringarray *ssa, SSAMapFunction mapfn, void *auxData)
{
    //pseudocode
    // for(int i = 0; i < ssa->numGroups; i++) {
    //     for(int i = 0; i < ssa->groupSize; i++) {
    //         if string is empty 
    //             mapfn("")
    //         else 
    //             mapfn(elem)
    //     }
    // }
}