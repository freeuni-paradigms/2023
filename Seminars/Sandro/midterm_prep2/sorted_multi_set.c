#include "sorted_multi_set.h"
#include "vector.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void VectorItemFreeFn(void *elem) {
  VectorItem *item = elem;
  if (item->free_fn) {
    item->free_fn(item->elem);
  }
  free(item->elem);
}

void SortedMultiSetInit(SortedMultiSet *s, int elem_size, CmpFn cmp_fn,
                        FreeFn free_fn) {
  s->elem_size = elem_size;
  s->cmp_fn = cmp_fn;
  s->free_fn = free_fn;
  VectorInit(&s->v, sizeof(VectorItem), VectorItemFreeFn);
}

void SortedMultiSetDestroy(SortedMultiSet *s) {
	VectorDestroy(&s->v);
}

typedef struct {
  int target_idx;
  void *user_elem;
  bool found_match;
  CmpFn cmp_fn;
} InsertAux;

void insert_map_fn(int index, void *elem, void *aux) {
  InsertAux *auxdata = aux;
  VectorItem *item = elem;
  // cur < elem -> -1
  // cur == elem -> 0
  // cur > elem -> +1
  int cmp_res = auxdata->cmp_fn(item->elem, auxdata->user_elem);

  if (cmp_res > 0) {
    if (auxdata->target_idx == -1) {
      auxdata->target_idx = index;
    }
  } else if (cmp_res == 0) { // found same elem
    item->count++;
    auxdata->target_idx = index;
    auxdata->found_match = true;
  }
}

int SortedMultiSetInsert(SortedMultiSet *s, void *elem) {
  InsertAux auxdata;
  auxdata.target_idx = -1;
  auxdata.found_match = false;
  auxdata.user_elem = elem;
  auxdata.cmp_fn = s->cmp_fn;
  VectorMap(&s->v, insert_map_fn, &auxdata);
  if (auxdata.found_match == true) {
    return auxdata.target_idx;
  }
  // target_idx == i | -1
  int target_idx = auxdata.target_idx;
  if (target_idx == -1) {
    target_idx = VectorSize(&s->v);
  }
  VectorItem item;
  item.elem = malloc(s->elem_size);
  memcpy(item.elem, elem, s->elem_size);
  item.free_fn = s->free_fn;
  item.count = 1;
  VectorInsert(&s->v, target_idx, &item);
  return target_idx;
}

typedef struct {
  int index;
  void *elem;
} GetAux;

void get_map_fn(int index, void *elem, void *aux) {
  GetAux *auxdata = aux;
  VectorItem *item = elem;
  if (index == auxdata->index) {
    auxdata->elem = item->elem;
  }
}

void *SortedMultiSetGet(SortedMultiSet *s, int index) {
  GetAux aux;
  aux.index = index;
  aux.elem = NULL;
  VectorMap(&s->v, get_map_fn, &aux);
  return aux.elem;
}

typedef struct {
  CmpFn cmp_fn;
  void *elem;
  int cnt;
} CountAux;

void count_map_fn(int index, void *elem, void *aux) {
  CountAux *auxdata = aux;
  VectorItem *item = elem;
  if (auxdata->cmp_fn(item->elem, auxdata->elem) == 0) {
    auxdata->cnt = item->count;
  }
}

int SortedMultiSetGetCount(SortedMultiSet *s, void *elem) {
  CountAux aux;
  aux.elem = elem;
  aux.cmp_fn = s->cmp_fn;
  aux.cnt = 0;
  VectorMap(&s->v, count_map_fn, &aux);
  return aux.cnt;
}
