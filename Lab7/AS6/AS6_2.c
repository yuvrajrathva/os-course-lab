#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int produced_items = 0;  

sem_t empty, full;
pthread_mutex_t mutex;

void* producer(void* arg) {
    int item = 1;
    while (1) {

        if (produced_items >= 20) {
            break;
        }
        sem_wait(&empty);   
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        item++;
        produced_items++;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);   
    }
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&full);   
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);  
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

   
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

   
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

     
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
