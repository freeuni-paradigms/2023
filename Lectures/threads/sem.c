#include "sem.h"

void SemaphoreInit(Semaphore* s, int value) {
  s->value = value;
  pthread_mutex_init(&s->m, NULL);
  pthread_cond_init(&s->c, NULL);
}

void SemaphoreDestroy(Semaphore* s) {
  pthread_mutex_destroy(&s->m);
  pthread_cond_destroy(&s->c);
}

void SemaphoreWait(Semaphore* s) {
  pthread_mutex_lock(&s->m);
  if (s->value > 0) {
	s->value--;
  } else {
	pthread_cond_wait(&s->c, &s->m);
	s->value--;
  }
  /* while (s->value == 0) { */
  /* 	pthread_cond_wait(&s->c, &s->m); */
  /* } */
  /* s->value--; */
  pthread_mutex_unlock(&s->m);
}

void SemaphorePost(Semaphore* s) {
  pthread_mutex_lock(&s->m);
  s->value++;
  if (s->value == 1) {
	/* pthread_cond_broadcast(&s->c); */
	pthread_cond_signal(&s->c);
  }
  pthread_mutex_unlock(&s->m);
}
