#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "common.h"
#include "producer.h"
#include "capitalizer.h"
#include "consumer.h"

int main(void)
{
    char *buf = (char *)getmem(SEED_ID);
    sem_t sem_empty = sem_init(0);
    sem_t sem_produced = sem_init(1);
    sem_t sem_capitalized = sem_init(2);
    sem_set(sem_empty, 1);
    sem_set(sem_produced, 0);
    sem_set(sem_capitalized, 0);

    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        producer(buf, sem_empty, sem_produced);
        exit(0);
    }

    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        capitalizer(buf, sem_produced, sem_capitalized);
        exit(0);
    }

    pid_t pid3 = fork();
    if (pid3 == 0)
    {
        consumer(buf, sem_capitalized, sem_empty);
        exit(0);
    }

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    sem_remove(sem_empty);
    sem_remove(sem_produced);
    sem_remove(sem_capitalized);

    return 0;
}
