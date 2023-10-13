#include "sortedset.h"
#include <stdio.h>

int cmpfn(const void *aPtr, const void *bPtr)
{
    int a = *(int *)aPtr;
    int b = *(int *)bPtr;

    // if (a == b)
    //     return 0;
    // if (a < b)
    //     return -1;
    // return 1;
    return a - b;
}

int main()
{
    // sortedset set;
    sortedset *set = malloc(sizeof(sortedset));

    SetNew(set, sizeof(int), &cmpfn, NULL);
    int a = 21;
    int b = 0;
    SetAdd(set, &a);
    printf("Length: %d\n", set->logLen);
    void *result = SetSearch(set, &b);
    if (result == NULL)
        printf("Elem not found \n");

    int *newResult = (int *)SetSearch(set, &a);
    printf("Element: %d\n", *newResult);
}