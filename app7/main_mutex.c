#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define START 'a'
#define END 'z'

char buf;
int ready = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_full = PTHREAD_COND_INITIALIZER;

void *Producer(void *arg)
{
    for (char c = START; c <= END; c++)
    {
        pthread_mutex_lock(&mutex);
        while (ready)
            pthread_cond_wait(&cond_empty, &mutex);
        buf = c;
        ready = 1;
        printf("Произведено: %c\n", c);
        pthread_cond_signal(&cond_full);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *Consumer(void *arg)
{
    for (char c = START; c <= END; c++)
    {
        pthread_mutex_lock(&mutex);
        while (!ready)
            pthread_cond_wait(&cond_full, &mutex);
        printf("Консумирано: %c\n", buf);
        ready = 0;
        pthread_cond_signal(&cond_empty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void)
{
    pthread_t producer, consumer;

    pthread_create(&producer, NULL, Producer, NULL);
    pthread_create(&consumer, NULL, Consumer, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_empty);
    pthread_cond_destroy(&cond_full);

    return 0;
}
