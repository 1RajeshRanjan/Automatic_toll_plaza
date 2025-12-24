#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void* producer(void* arg) {
    int vehicle = 1;
    while (vehicle <= 10) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = vehicle;
        printf("Vehicle %d entered toll plaza\n", vehicle);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        vehicle++;
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    int data;
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        data = buffer[out];
        printf("Toll processed for vehicle %d\n", data);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
