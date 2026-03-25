#include <stdio.h>
#include <ctype.h>
#include "common.h"

int main(void)
{
    char *buf = (char *)getmem(SEED_ID);
    sem_t sem_produced = sem_init(1);
    sem_t sem_capitalized = sem_init(2);

    for (char c = START; c <= END; c++)
    {
        PS(sem_produced);
        buf[0] = toupper(buf[0]);
        printf("Капитализирано: %c\n", buf[0]);
        VS(sem_capitalized);
    }

    return 0;
}
