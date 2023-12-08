#include <assert.h>
#include <pthread.h>
#include <stdio.h>

typedef struct {
	int *cnt_ptr;
	pthread_mutex_t *oddlock_ptr;
	pthread_mutex_t *evenlock_ptr;
} args;

void *odd(void *arg) {
	args* data = arg;
	for(int i=0; i<10000; i++){
		pthread_mutex_lock(data->oddlock_ptr);
		printf("odd: %d\n", *data->cnt_ptr);
		assert(*data->cnt_ptr % 2 == 1);
		*data->cnt_ptr = *data->cnt_ptr + 1;
		pthread_mutex_unlock(data->evenlock_ptr);
	}
	return 0;
}

void *even(void *arg) {
	args* data = arg;
	for(int i=0; i<10000; i++){
		pthread_mutex_lock(data->evenlock_ptr);
		printf("even: %d\n", *data->cnt_ptr);
		assert(*data->cnt_ptr % 2 == 0);
		*data->cnt_ptr = *data->cnt_ptr + 1;
		pthread_mutex_unlock(data->oddlock_ptr);
	}
	return 0;
}

int main(){

	pthread_t todd;
	pthread_t teven;
	pthread_mutex_t oddlock;
	pthread_mutex_t evenlock;

	pthread_mutex_init(&oddlock, 0);
	pthread_mutex_init(&evenlock, 0);
	pthread_mutex_lock(&evenlock);

	args args;
	int cnt = 1;
	args.cnt_ptr = &cnt;
	args.oddlock_ptr = &oddlock;
	args.evenlock_ptr = &evenlock;

	pthread_create(&todd, 0, odd, &args);
	pthread_create(&teven, 0, even, &args);

	pthread_join(todd, 0);
	pthread_join(teven, 0);

}
