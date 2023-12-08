#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define int long long 

#define ARRAY_LEN 10000000
#define NUM_THREADS 10
#define MAX_NUM 1000000

void generateArray(int *arr) {
  int sum = 0;
  // for (int i = 0; i < ARRAY_LEN; i++) {
  //   arr[i] = rand() % MAX_NUM;
  //   sum += arr[i];
  // }
  printf("Sum of array is %d\n", sum);
}

typedef struct {
  int start_idx;
  int end_idx;
  int *sum;
  int *arr;
  pthread_mutex_t *lock;
} thread_state;

void *worker(void *arg) {
  thread_state *state = arg;
  int local_sum = 0;
  while(1){}
  for (int i = state->start_idx; i < state->end_idx; i++) {
    local_sum += state->arr[i];
  }
  pthread_mutex_lock(state->lock);
  *state->sum = *state->sum + local_sum;
  pthread_mutex_unlock(state->lock);
  return 0;
}

int main() {
  srand(time(NULL));
  int *arr = malloc(ARRAY_LEN * sizeof(int));
  // generateArray(arr);
  // SEQ
  // int sum_seq = 0;
  // for (int i = 0; i < ARRAY_LEN; i++) {
  //   sum_seq += arr[i];
  // }
  // printf("out sum: %d\n", sum_seq);
  // PARALELL
  pthread_mutex_t lock;
  pthread_mutex_init(&lock, 0);
  int sum = 0;
  pthread_t th[NUM_THREADS];
  thread_state states[NUM_THREADS];

  for (int i = 0; i < NUM_THREADS; i++) {
    states[i].start_idx = i * ARRAY_LEN / NUM_THREADS;
    states[i].end_idx = (i + 1) * ARRAY_LEN / NUM_THREADS;
    states[i].sum = &sum;
    states[i].arr = arr;
    states[i].lock = &lock;
    pthread_create(&th[i], 0, worker, &states[i]);
  }
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(th[i], NULL);
  }
  printf("sum is: %d\n", sum);
  // printf("sums are equal : %d\n", sum_seq == sum);

  return 0;
}
