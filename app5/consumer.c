#include <stdio.h>
#include "common.h"

int main(void)
{
    char *buf = (char *)getmem(SEED_ID);
    sem_t sem_empty = sem_init(0);
    sem_t sem_full = sem_init(1);

    for (char c = 'a'; c <= 'z'; c++)
    {
        PS(sem_full);
        printf("Консумирано: %c\n", buf[0]);
        VS(sem_empty);
    }

    return 0;
}
