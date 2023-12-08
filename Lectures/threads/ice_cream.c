#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_CUSTOMERS 10

void Sleep() {
  sleep(1 + rand() % 2);
}

int MakeOrder() {
  return 1 + rand() % 4;
}

void MakeCone() {
  Sleep();
}

bool CheckCone() {
  Sleep();
  return rand() & 1;
}

void Pay() {
  Sleep();
}

typedef struct {
  int num_cones;
  bool passed;
  sem_t req;
  sem_t resp;
  sem_t lock;
} ManagerState;

typedef struct {
  int count;
  sem_t lock;
  sem_t customers[NUM_CUSTOMERS];
  sem_t customerPayed;
} LineState;

// GLOBAL STATE -- NOT GOOD :(
ManagerState mgr;
LineState line;

void* Manager(void* args) {
  printf("MANAGER: starting\n");
  int num_checked = 0;
  int num_passed = 0;
  while (num_passed < mgr.num_cones) {
	sem_wait(&mgr.req);
	mgr.passed = CheckCone();
	sem_post(&mgr.resp);
	++num_checked;
	num_passed += mgr.passed;
	printf("MANAGER: checked new cone\n");
  }
  printf("MANAGER: checked %d cones in total\n", num_checked);
  return NULL;
}

void* Clerk(void* args) {
  char* id = args;
  printf("CLERK %s: staring\n", id);
  bool passed = false;
  while (!passed) {
	MakeCone();
	sem_wait(&mgr.lock);
	sem_post(&mgr.req);
	sem_wait(&mgr.resp);
	passed = mgr.passed;
	sem_post(&mgr.lock);
	if (!passed) {
	  printf("CLERK %s: not good enough, retrying\n", id);
	} {
	  printf("CLERK %s: made good cone ^^\n", id);
	}
  }
  printf("CLERK %s: done\n", id);
  return NULL;
}

typedef struct {
  int id;
  int num_cones;
} CustomerArgs;

void* Customer(void* args) {
  CustomerArgs* a = args;
  printf("CUSTOMER %d: need %d cone(s)\n", a->id, a->num_cones);
  pthread_t clerks[a->num_cones];
  char* cids[a->num_cones];
  for (int i = 0; i < a->num_cones; ++i) {
	cids[i] = malloc(10 * sizeof(char));
	assert(cids[i] != NULL);
	sprintf(cids[i], "%d-%d", a->id, i);
	pthread_create(&clerks[i], NULL, Clerk, cids[i]);
  }
  for (int i = 0; i < a->num_cones; ++i) {
	printf("CUSTOMER %d: waiting for clerk %d\n", a->id, i);
	pthread_join(clerks[i], NULL);
	printf("CUSTOMER %d: got cone from clerk %d\n", a->id, i);
	free(cids[i]);
  }
  sem_wait(&line.lock);
  int number = line.count;
  ++line.count;
  sem_post(&line.lock);
  printf("CUSTOMER %d: waiting in line %d\n", a->id, number);
  sem_wait(&line.customers[number]);
  Pay();
  sem_post(&line.customerPayed);
  printf("CUSTOMER %d: byeeee\n", a->id);
  return NULL;
}

void* Cashier(void* args) {
  printf("CASHIER: starting\n");
  for (int i = 0; i < NUM_CUSTOMERS; ++i) {
	printf("CASHIER: calling customer in line %d\n", i);
	sem_post(&line.customers[i]);
	sem_wait(&line.customerPayed);
	printf("CASHIER: customer payed\n");
  }
  printf("CASHIER: all customers payed\n");
  return NULL;
}

int main(int argc, char** argv) {
  sem_init(&mgr.req, /*pshared=*/0, 0);
  sem_init(&mgr.resp, /*pshared=*/0, 0);
  sem_init(&mgr.lock, /*pshared=*/0, 1);
  sem_init(&line.lock, /*pshared=*/0, 1);
  sem_init(&line.customerPayed, /*pshared=*/0, 0);
  for (int i = 0; i < NUM_CUSTOMERS; ++i) {
	sem_init(&line.customers[i], /*pshared=*/0, 0);
  }
  CustomerArgs cargs[NUM_CUSTOMERS];
  pthread_t t;
  for (int i = 0; i < NUM_CUSTOMERS; ++i) {
	cargs[i].id = i;
	cargs[i].num_cones = MakeOrder();
	mgr.num_cones += cargs[i].num_cones;
	pthread_create(&t, NULL, Customer, &cargs[i]);
  }
  pthread_create(&t, NULL, Manager, NULL);
  pthread_t cashier;
  pthread_create(&cashier, NULL, Cashier, NULL);
  pthread_join(cashier, NULL);
  printf("!!! DONE !!!\n");
  return 0;
}
