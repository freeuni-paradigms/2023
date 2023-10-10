#include "Scheme.h"
#include <assert.h>

char *ConcatStrings(const char *first, const char *second)
{
    char* result = malloc(strlen(first) + strlen(second) + 1);
    assert(result != NULL);
    strcpy(result, first);
    strcat(result, second);
    return result;
}

char *ConcatAll(nodeType *root)
{
    if(*root == Nil) {
        return strdup("");
    } else if (*root == Integer) {
        return strdup("");
    } else if (*root == String) {
        return strdup((char*)(root + 1));
    }

    nodeType* first = *((nodeType**)(root + 1));
    nodeType* second = *((nodeType**)(root + 1) + 1); // (root + 1)-ით გადავახტით NodeType ცვლადს, ((nodeType**)(root + 1) + 1)-ით გადავახტით ელემენტზე მიმთითებელს

    char* first_str = ConcatAll(first);
    char* second_str = ConcatAll(second);

    char* result = ConcatStrings(first_str, second_str);

    free(first_str);
    free(second_str);
    return result;
}

struct __attribute__((__packed__)) Node {
	nodeType t;
	union {
		struct {
			struct Node* child;
			struct Node* next;
		} list;
		int i;
		char s[0];
	} v;
};

int main() {
	struct Node *list1 = malloc(sizeof(nodeType) + 2*sizeof(nodeType*));
	list1->t = List;
	struct Node *list2 = malloc(sizeof(nodeType) + 2*sizeof(nodeType*));
	list2->t = List;
	struct Node *list3 = malloc(sizeof(nodeType) + 2*sizeof(nodeType*));
	list3->t = List;
	struct Node *nil   = malloc(sizeof(nodeType));
	nil->t = Nil;

	struct Node *astr  = malloc(sizeof(nodeType) + 10);
	astr->t = String;
	struct Node *bint  = malloc(sizeof(nodeType) + sizeof(int));
	bint->t = Integer;
	struct Node *cstr  = malloc(sizeof(nodeType) + 10);
	cstr->t = String;

	// prepare values
	strcpy(astr->v.s, "Hello, ");
	bint->v.i = 1234;
	strcpy(cstr->v.s, "World!");

	list1->v.list.next = list2;
	list2->v.list.next = list3;
	list3->v.list.next = nil;

	list1->v.list.child = astr;
	list2->v.list.child = bint;
	list3->v.list.child = cstr;


	char * res = ConcatAll((nodeType*)list1);
	printf("res: %s\n", res);

	return 0;
}