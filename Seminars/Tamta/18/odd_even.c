#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *count;
    pthread_mutex_t *even_lock;
    pthread_mutex_t *odd_lock;
} Args;

void* even_fn(void* args) {
    Args* data = args;
    while (true)
    {
        pthread_mutex_lock(data->even_lock);
        if (*data->count >= 100) break;
        (*data->count)++;
        if (*data->count % 2 == 1) printf("ERRROOOOOOOOOOOORRRRRRRRRRR");
        printf("even: %d\n", *data->count);
        pthread_mutex_unlock(data->odd_lock);
    }
    pthread_mutex_unlock(data->odd_lock);
}

void* odd_fn(void* args) {
    Args* data = args;
    while (true)
    {
        pthread_mutex_lock(data->odd_lock);
        if (*data->count >= 100) break;
        (*data->count)++;
        if (*data->count % 2 == 0) printf("ERRROOOOOOOOOOOORRRRRRRRRRR");
        printf("odd: %d\n", *data->count);
        pthread_mutex_unlock(data->even_lock);
    }
    pthread_mutex_unlock(data->even_lock);

}

int main(){
    pthread_t even, odd;
    pthread_mutex_t even_lock;
    pthread_mutex_t odd_lock;
    pthread_mutex_init(&even_lock, NULL);
    pthread_mutex_init(&odd_lock, NULL);
    int count = 0;

    pthread_mutex_lock(&even_lock);

    Args args = {&count, &even_lock, &odd_lock};
    pthread_create(&even, NULL, even_fn, &args);
    pthread_create(&odd, NULL, odd_fn, &args);

    pthread_join(even, NULL);
    pthread_join(odd, NULL);
}