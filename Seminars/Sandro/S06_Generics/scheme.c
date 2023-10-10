#include "scheme.h"


// result is on heap
char *ConcatAll(nodeType *node)
{
	nodeType type = *node;
	// printf("%d", sizeof(nodeType));
	if(type == Nil) {
		return strdup("");
	}
	if(type == String) {
		return strdup((char*)(node+1));
	}
	if(type == Integer) {
		return strdup("");
	}
	if(type == List) {
		// val
		// next
		nodeType* val = *(nodeType**)(node+1);
		nodeType* next = *((nodeType**)(node+1)+1);
		char *a = ConcatAll(val); 
		char *b = ConcatAll(next); 
		char *res = malloc(strlen(a) + strlen(b) + 1);
		strcpy(res, a);
		// strcpy(res+strlen(a), b);
		strcat(res, b);
		free(a);
		free(b);
		return res;
	}
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

	struct Node *astr  = malloc(sizeof(nodeType) + 100);
	astr->t = String;
	struct Node *bint  = malloc(sizeof(nodeType) + sizeof(int));
	bint->t = Integer;
	struct Node *cstr  = malloc(sizeof(nodeType) + 100);
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
