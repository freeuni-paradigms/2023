#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdbool.h>

struct Args
{
    int agent;
    int* num_tickets;
    sem_t* lock;
} typedef Args;


void* sell_tickets(void* args){
    Args* data = args;
    // printf("Num tickets %d\n", *data->num_tickets);
    while (true) {
        sem_wait(data->lock);
        printf("Num tickets %d\n", *data->num_tickets); // printfs could be outside sem logic to increase parallelism
        if (*data->num_tickets == 0) break;
        *(data->num_tickets) = *(data->num_tickets) - 1;
        printf("Agent %d sold a ticket\n", data->agent);
        sem_post(data->lock);
    }
    sem_post(data->lock);
}

int main(){
    int num_agents = 10;
    int num_tickets = 150;
    sem_t lock;
    sem_init(&lock, 0, 1);
    pthread_t threads[num_agents];
    Args args [num_agents]; 
    for (int i = 0; i < num_agents; i++) {
        args[i].agent = i;
        args[i].num_tickets = &num_tickets;
        args[i].lock = &lock;
        pthread_create(&threads[i], NULL, sell_tickets, &args[i]);
    }
    for (int i = 0; i < num_agents; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Num tickets %d\n", num_tickets);
    
}