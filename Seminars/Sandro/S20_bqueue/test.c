#include "bqueue.c"
#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  Queue q;
} state;

void *popper(void *arg) {
  state *data = arg;
  for (int i = 0; i < 1000; i++) {
    int *res;
    dequeue(&data->q, (void **)&res);
    printf("POP  %d\n", *res);
  }
  return 0;
}

void *pusher(void *arg) {
  state *data = arg;
  for (int i = 0; i < 1000; i++) {
    printf("PUSH %d\n", i);
    enqueue(&data->q, &i);
  }
  return 0;
}

int main() {
  pthread_t tpusher;
  pthread_t tpopper;
  state s;
  init_queue(&s.q, sizeof(int), NULL);
  pthread_create(&tpusher, 0, pusher, &s);
  pthread_create(&tpopper, 0, popper, &s);
  pthread_join(tpusher, 0);
  pthread_join(tpopper, 0);
  return 0;
}
