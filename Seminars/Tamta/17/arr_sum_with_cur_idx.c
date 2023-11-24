#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdbool.h>
#include <time.h>
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
    int* curr_idx;
    int* arr;
    int* sum;
    pthread_mutex_t* lock;
} Args;


void* calculate_sum(void * args){
    Args* data = args;
    while(true)
    {
        // try to add next value to sum (lock if some other thread got here first and hasn't finished calculating)
        pthread_mutex_lock(data->lock);
        if (*data->curr_idx >= ARR_SIZE) break;
        *data->sum += data->arr[*data->curr_idx];
        *data->curr_idx = *data->curr_idx + 1;
        pthread_mutex_unlock(data->lock);
    }
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
    pthread_mutex_init(&lock, NULL);

    // init args and start threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        args_arr[i].arr = arr;
        args_arr[i].sum = &sum;
        args_arr[i].lock = &lock;
        args_arr[i].curr_idx = &curr_index;
        pthread_create(&threads[i], NULL, calculate_sum, &args_arr[i]);
    }
    
    // wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    // print result
    printf("Result: %d\n", sum);
    
    return 0;
}