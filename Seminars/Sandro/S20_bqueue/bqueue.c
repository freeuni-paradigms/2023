#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "vector.h"

#define QUEUESIZE 50

typedef struct
{
	vector v;
	pthread_mutex_t lock;
	sem_t n;
	sem_t n_free;
	int elemSize;

} Queue;

void init_queue(Queue *q, int elemSize, VectorFreeFunction freefn)
{
	q->elemSize = elemSize;
	VectorNew(&q->v, elemSize, freefn, QUEUESIZE);
	pthread_mutex_init(&q->lock, 0);
	sem_init(&q->n, 0, 0);
	sem_init(&q->n_free, 0, QUEUESIZE);
}

void enqueue(Queue *q, void *elem)
{
	sem_wait(&q->n_free);
	pthread_mutex_lock(&q->lock);
	VectorAppend(&q->v, elem);
	pthread_mutex_unlock(&q->lock);
	sem_post(&q->n);
}

void dequeue(Queue *q, void **ptr)
{
	sem_wait(&q->n);
	pthread_mutex_lock(&q->lock); // n= 0 
	void* ret_value = malloc(q->elemSize);
	void* elem=  VectorNth(&q->v, 0);
	memcpy(ret_value, elem, q->elemSize);
	*ptr = ret_value;
	VectorDelete(&q->v, 0);
	pthread_mutex_unlock(&q->lock);
	sem_post(&q->n_free);
}

void destroy_queue(Queue *q)
{
	VectorDispose(&q->v);
}
