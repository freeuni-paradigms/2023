typedef struct {
  int value; // 0 ....
  pthread_mutex_t m;
  pthread_cond_t c;
} Semaphore;

void SemaphoreInit(Semaphore* s, int value);
void SemaphoreDestroy(Semaphore* s);
void SemaphoreWait(Semaphore* s); // --
void SemaphorePost(Semaphore* s); // ++
