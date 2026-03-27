#include <stdio.h>
#include "common.h"

int main(void)
{
    char *buf = (char *)getmem(SEED_ID);
    sem_t sem_empty = sem_init(0);
    sem_t sem_produced = sem_init(1);
    sem_t sem_capitalized = sem_init(2);

    for (char c = START; c <= END; c++)
    {
        PS(sem_capitalized);
        printf("Консумирано: %c\n", buf[0]);
        VS(sem_empty);
    }

    sem_remove(sem_empty);
    sem_remove(sem_produced);
    sem_remove(sem_capitalized);
    return 0;
}
