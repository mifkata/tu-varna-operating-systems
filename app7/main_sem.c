#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define START 'a'
#define END 'z'

char buf;

sem_t sem_empty;
sem_t sem_full;

void *Producer(void *arg)
{
    for (char c = START; c <= END; c++)
    {
        sem_wait(&sem_empty);
        buf = c;
        printf("Произведено: %c\n", c);
        sem_post(&sem_full);
    }
    return NULL;
}

void *Consumer(void *arg)
{
    for (char c = START; c <= END; c++)
    {
        sem_wait(&sem_full);
        printf("Консумирано: %c\n", buf);
        sem_post(&sem_empty);
    }
    return NULL;
}

int main(void)
{
    pthread_t producer, consumer;

    sem_init(&sem_empty, 0, 1);
    sem_init(&sem_full, 0, 0);

    pthread_create(&producer, NULL, Producer, NULL);
    pthread_create(&consumer, NULL, Consumer, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    sem_destroy(&sem_empty);
    sem_destroy(&sem_full);

    return 0;
}
