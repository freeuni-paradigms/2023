#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdlib.h>


#define NUM_THREADS 10
#define ARR_SIZE 100000
#define MAX_NUM 10000

void generateArray(int *arr)
{
    int sum = 0;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = rand() % MAX_NUM;
        sum += arr[i];
    }
    printf("Sum of array is %d\n", sum);
}

typedef struct
{
    int start_index;
    int step_size;
    int* arr;
    int* sum;
    pthread_mutex_t* lock;
} Args;


void* calculate_sum(void * args){
    Args* data = args;
    // calcualte local sum
    int sum = 0;
    for (int i = data->start_index; i < data->start_index + data->step_size; i++) {
        sum += data->arr[i];
        if (i >= ARR_SIZE) break;
    }
    // update shared sum with the local
    pthread_mutex_lock(data->lock);
    *data->sum += sum;
    pthread_mutex_unlock(data->lock);
}


int main(){

    // array generation
    int arr[ARR_SIZE];
    generateArray(arr);

    // declare and init vars
    pthread_t threads[NUM_THREADS];
    pthread_mutex_t lock;
    Args args_arr[NUM_THREADS];

    int sum = 0;
    int curr_index = 0;
    int step_size = ARR_SIZE / NUM_THREADS;
    pthread_mutex_init(&lock, NULL);

    // init args and start threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        args_arr[i].arr = arr;
        args_arr[i].start_index = i*step_size;
        args_arr[i].sum = &sum;
        args_arr[i].lock = &lock;
        args_arr[i].step_size = step_size;
        if (i == NUM_THREADS-1) args_arr[i].step_size += ARR_SIZE % NUM_THREADS;
        pthread_create(&threads[i], NULL, calculate_sum, &args_arr[i]);
    }

    // wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    printf("%d\n", sum);
    
    return 0;
}