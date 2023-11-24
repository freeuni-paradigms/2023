#ifndef PARADIGMS_PROBLEMS_MAPSET_VECTGOR_H_
#define PARADIGMS_PROBLEMS_MAPSET_VECTGOR_H_

typedef void(*FreeFn)(void* elem);
typedef void(*MapFn)(int index, void* elem, void* aux);

typedef struct {
  void* _base;
  int _log_len;
  int _alloc_len;
  int _elem_size;
  FreeFn _free_fn;
} Vector;

void VectorInit(Vector* v, int elem_size, FreeFn free_fn);
void VectorDestroy(Vector* v);
int VectorSize(Vector* v);
void VectorInsert(Vector* v, int index, void* elem);
void VectorMap(Vector* v, MapFn map_fn, void* aux);

#endif  // PARADIGMS_PROBLEMS_MAPSET_VECTGOR_H_
