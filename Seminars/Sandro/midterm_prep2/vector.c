#include "vector.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define NTH(v, i) (void*)((char*)(v)->_base + (i) * (v)->_elem_size)

void VectorInit(Vector* v, int elem_size, FreeFn free_fn) {
  v->_log_len = 0;
  v->_alloc_len = 4;
  v->_base = malloc(v->_alloc_len * elem_size);
  assert(v->_base != NULL);
  v->_elem_size = elem_size;
  v->_free_fn = free_fn;
}

void VectorDestroy(Vector* v) {
  if (v->_free_fn != NULL) {
    for (int i = 0; i < v->_log_len; ++i) {
      v->_free_fn(NTH(v, i));
    }
  }
  free(v->_base);
}

int VectorSize(Vector* v) {
  return v->_log_len;
}

void VectorInsert(Vector* v, int index, void* elem) {
  assert(0 <= index && index <= v->_log_len);
  if (v->_log_len == v->_alloc_len) {
    v->_alloc_len *= 2;
    v->_base = realloc(v->_base, v->_alloc_len * v->_elem_size);
    assert(v->_base != NULL);
  }
  memmove(NTH(v, index + 1), NTH(v, index), (v->_log_len - index) * v->_elem_size);
  memcpy(NTH(v, index), elem, v->_elem_size);
  ++v->_log_len;
}

void VectorMap(Vector* v, MapFn map_fn, void* aux) {
  for (int i = 0; i < v->_log_len; ++i) {
    map_fn(i, NTH(v, i), aux);
  }
}
