#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct {
	pthread_mutex_t lock;
	pthread_cond_t cond;
	int val;
} sem;


void init(sem *s, int orig) {
	pthread_mutex_init(&s->lock, 0);
	pthread_cond_init(&s->cond, 0);
	s->val = orig;
}

// x+=1
void post(sem *s) {
	pthread_mutex_lock(&s->lock);
	s->val = s->val + 1;
	pthread_cond_broadcast(&s->cond);
	pthread_mutex_unlock(&s->lock);

}


// ATOMIC
// if 0 -> wait for nonzero
// x-=1
void wait(sem *s) {
	pthread_mutex_lock(&s->lock);
	if(s->val == 0){
		// pthread_mutex_unlock(&s->lock);
		//////////////////// SCHEDULER //////
		pthread_cond_wait(&s->cond, &s->lock);
		// let someone else run
		// pthread_mutex_lock(&s->lock);
	}
	s->val-=1;
	if(s->val<0){
		printf("ERRRORRRR");
		exit(0);
	}
	pthread_mutex_unlock(&s->lock);
}

sem s;

void* f1(void *a){
	for(int i=0; i<1000000000; i++){
		post(&s);
		usleep(100);
	}
	return 0;
}

void* f2(void *a){
	for(int i=0; i<2000000000; i++){
		wait(&s);
		printf("%d\n", i);
	}
	return 0;
}


int main() {
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	init(&s, 0);
	pthread_create(&t1, 0, f1, 0);
	pthread_create(&t2, 0, f2, 0);
	pthread_create(&t3, 0, f2, 0);
	pthread_join(t1, 0);
	pthread_join(t2, 0);
	pthread_join(t3, 0);
}



