#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t toll;
pthread_mutex_t lock;
int vehicle = 1;

void* booth(void* arg) {
    int id = *(int*)arg;
    while (1) {
        sem_wait(&toll);
        pthread_mutex_lock(&lock);

        if (vehicle > 10) {
            pthread_mutex_unlock(&lock);
            break;
        }

        printf("Booth %d processed vehicle %d\n", id, vehicle);
        vehicle++;

        pthread_mutex_unlock(&lock);
        sem_post(&toll);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t b1, b2;
    int id1 = 1, id2 = 2;

    sem_init(&toll, 0, 2);
    pthread_mutex_init(&lock, NULL);

    pthread_create(&b1, NULL, booth, &id1);
    pthread_create(&b2, NULL, booth, &id2);

    pthread_join(b1, NULL);
    pthread_join(b2, NULL);

    return 0;
}
