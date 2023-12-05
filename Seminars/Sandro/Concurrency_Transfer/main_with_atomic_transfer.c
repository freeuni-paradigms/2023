#include <pthread.h>
#include <stdio.h>

typedef struct {
  int balance;
  int id;
  pthread_mutex_t lock;
  pthread_cond_t cond;
} Account;

void tryTransfer(Account *fromAccount, Account *toAccount, int amount) {
  if (amount < 0)
    return;
  if (fromAccount->id < toAccount->id) {
    pthread_mutex_lock(&fromAccount->lock);
    pthread_mutex_lock(&toAccount->lock);
  } else {
    pthread_mutex_lock(&toAccount->lock);
    pthread_mutex_lock(&fromAccount->lock);
  }
  if (fromAccount->balance >= amount) {
    fromAccount->balance -= amount;
    toAccount->balance += amount;
    pthread_cond_broadcast(&toAccount->cond);
  }
  pthread_mutex_unlock(&fromAccount->lock);
  pthread_mutex_unlock(&toAccount->lock);
}

void transfer(Account *fromAccount, Account *toAccount, int amount) {
  if (fromAccount->id < toAccount->id) {
    pthread_mutex_lock(&fromAccount->lock);
    pthread_mutex_lock(&toAccount->lock);
  } else {
    pthread_mutex_lock(&toAccount->lock);
    pthread_mutex_lock(&fromAccount->lock);
  }
  while (fromAccount->balance < amount) {
    pthread_mutex_unlock(&toAccount->lock);

    pthread_cond_wait(&fromAccount->cond, &fromAccount->lock); // 7
    pthread_mutex_unlock(&fromAccount->lock);
	 // BOTH UNLOCKED

    if (fromAccount->id < toAccount->id) {
      pthread_mutex_lock(&fromAccount->lock);
      pthread_mutex_lock(&toAccount->lock);
    } else {
      pthread_mutex_lock(&toAccount->lock);
      pthread_mutex_lock(&fromAccount->lock);
    }
  }
  fromAccount->balance -= amount;

  toAccount->balance += amount;
  pthread_cond_broadcast(&toAccount->cond);
  pthread_mutex_unlock(&toAccount->lock);
  pthread_mutex_unlock(&fromAccount->lock);
}

Account accs[5];

void *work(void *arg) {

  for (int i = 0; i < 10000; i++) {
    transfer(&accs[0], &accs[1], 100);
    transfer(&accs[1], &accs[0], 100);
  }
  return 0;
}

int main() {
  for (int i = 0; i < 5; i++) {
    pthread_mutex_init(&accs[i].lock, 0);
    pthread_cond_init(&accs[i].cond, 0);
    accs[i].id = i;
  }
  accs[0].balance = 100;
  pthread_t th[100];
  for (int i = 0; i < 100; i++) {
    pthread_create(&th[i], 0, work, 0);
  }

  for (int i = 0; i < 100; i++) {
    pthread_join(th[i], 0);
  }

  printf("%d\n", accs[0].balance);
  printf("%d\n", accs[1].balance);
}
