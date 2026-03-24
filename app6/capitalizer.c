#include <stdio.h>
#include "common.h"

int main(void)
{
    char *buf = (char *)getmem(SEED_ID);
    sem_t sem_produced = sem_init(1);
    sem_t sem_capitalized = sem_init(2);

    for (char c = 'a'; c <= 'z'; c++)
    {
        PS(sem_produced);
        buf[0] = buf[0] - 32;
        printf("Капитализирано: %c\n", buf[0]);
        VS(sem_capitalized);
    }

    return 0;
}
