typedef void(*FreeFn)(void*);

typedef struct {
  void* base;
  int log_len;
  int alloc_len;
  int elem_size;
  FreeFn free_fn;
} Stack;

void StackInit(Stack* s, int elem_size, FreeFn free_fn);
void StackDestroy(Stack* s);
void StackPush(Stack* s, void* value);
void StackPop(Stack* s, void* value);
int StackSize(Stack* s);
