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

void freefnstr(void* s){ // T = char*
	char*my_s = *(char**)s;


}

int main()
{
    // sortedset set;
    sortedset *set = malloc(sizeof(sortedset));

    SetNew(set, sizeof(int), &cmpfn, NULL);
    int a = 21;
    int b = 0;
    SetAdd(set, &a);
    SetAdd(set, &b);
	 for(int i=0; i<100; i++){
		 int x = 100+i;
		 SetAdd(set, &x);
	 }
    printf("Length: %d\n", set->logic_n);
    int *result = SetSearch(set, &b);
    if (result == NULL)
        printf("Elem not found \n");
    printf("Element: %d\n", *result);

    int *newResult = (int *)SetSearch(set, &a);
    printf("Element: %d\n", *newResult);
}
