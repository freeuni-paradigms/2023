#include "stack.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

void StackInit(Stack* s, int elem_size, FreeFn free_fn) {
  s->elem_size = elem_size;
  s->free_fn = free_fn;
  s->log_len = 0;
  s->alloc_len = 4;
  s->base = malloc(s->alloc_len * s->elem_size);
  assert(s->base != NULL);
}

void StackDestroy(Stack* s) {
  if (s->free_fn != NULL) {
	for (int i = 0; i < s->log_len; ++i) {
	  s->free_fn((char*)s->base + s->elem_size * i);
	}
  }
  free(s->base);
}

void StackPush(Stack* s, void* value) {
  if (s->log_len == s->alloc_len) {
	s->alloc_len *= 2;
	s->base = realloc(s->base, s->alloc_len * s->elem_size);
	assert(s->base != NULL);
  }
  memcpy((char*)s->base + s->elem_size * s->log_len, value, s->elem_size);
  s->log_len++;
}

void StackPop(Stack* s, void* value) {
  assert(s->log_len > 0);
  s->log_len--;
  // void* value = malloc(s->elem_size);
  assert(value != NULL);
  memcpy(value, (char*)s->base + s->elem_size * s->log_len, s->elem_size);
}

int StackSize(Stack* s) {
  return s->log_len;
}
