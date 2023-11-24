#ifndef PARADIGMS_PROBLEMS_MAPSET_SORTED_MULTI_SET_H_
#define PARADIGMS_PROBLEMS_MAPSET_SORTED_MULTI_SET_H_

#include "vector.h"

typedef int(*CmpFn)(void* a, void* b);

typedef struct {
	void *elem; // copied user elem 
	int count;
	FreeFn free_fn; // (void*)
} VectorItem;

typedef struct {
  Vector v; 
  int elem_size;
  CmpFn cmp_fn; // (void*, void*) -> int  <0 0 >0
  FreeFn free_fn; // (void*)
} SortedMultiSet;

// უკეთებს სიმრავლეს ინიციალიზაციას.
void SortedMultiSetInit(SortedMultiSet* s, int elem_size, CmpFn cmp_fn, FreeFn free_fn);
// ათავისუფლებს სიმრავლის მიერ გამოყენებულ მეხსიერებას.
void SortedMultiSetDestroy(SortedMultiSet* s);
// ამატებს მოცემულ ელემენტს სიმრავლეში და უკან აბრუნებს თუ რა პოზიციაზე დაემატა იგი.
// იღებს მფლობელობას გადმოცემულ ელემენტზე.
int SortedMultiSetInsert(SortedMultiSet* s, void* elem);
// აბრუნებს მოცემულ ინდექსზე მყოფ ელემენტზე მიმთითებელს.
void* SortedMultiSetGet(SortedMultiSet* s, int index);
// აბრუნებს თუ რამდენჯერ გვხვდება მოცემული ელემენტი სიმრავლეში.
int SortedMultiSetGetCount(SortedMultiSet* s, void* elem);

#endif  // PARADIGMS_PROBLEMS_MAPSET_SORTED_MULTI_SET_H_
