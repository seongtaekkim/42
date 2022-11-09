#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define true 1
#define BUFFER_SIZE 1

int buffer[BUFFER_SIZE];

pthread_mutex_t mutex;
sem_t *empty, *full;
int in = 0, out = 0;

void insert_item(int item)
{
    sem_wait(empty);
    pthread_mutex_lock(&mutex);

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    printf("producer : inserted $%d\n", item);

    pthread_mutex_unlock(&mutex);
    sem_post(full);    
}

void remove_item(int *item)
{
    sem_wait(full);
    pthread_mutex_lock(&mutex);
    *item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    printf("customer: removed $%d$\n", *item);

    pthread_mutex_unlock(&mutex);
    sem_post(empty);
}

void *producer(void *param) {
    int item;
    while (true) {
        usleep((1 + rand() % 5) * 100000);
        item = 1000 + rand() % 1000;
        insert_item(item); // critical section
    }
}

void *consumer(void *param) {
    int item;
    while (true) {
        usleep((1 + rand() % 5) * 100000);
        remove_item(&item); // critical section
    }
}

int main(int argc, char *argv[])
{
    int i, numOfProducers = 1, numOfConsumers = 1;
    pthread_t tid;

    pthread_mutex_init(&mutex, NULL);
    empty = sem_open("empty", O_CREAT | O_EXCL, 0644, BUFFER_SIZE); 
    full = sem_open("full", O_CREAT | O_EXCL, 0644, 0); 
    srand(time(0));
    // create the producers
    for (i = 0; i < numOfProducers ; i++)
        pthread_create(&tid, NULL, producer, NULL);
    for (i = 0; i < numOfConsumers ; i++)
        pthread_create(&tid, NULL, consumer, NULL);

    sleep(5);
    sem_close(empty); 
	sem_unlink("empty"); 
    sem_close(full); 
	sem_unlink("full"); 
    return(0);
}