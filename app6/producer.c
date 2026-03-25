#include <stdio.h>
#include "common.h"

int main(void)
{
    char *buf = (char *)getmem(SEED_ID);
    sem_t sem_empty = sem_init(0);
    sem_t sem_produced = sem_init(1);
    sem_t sem_capitalized = sem_init(2);
    sem_set(sem_empty, 1);
    sem_set(sem_produced, 0);
    sem_set(sem_capitalized, 0);

    for (char c = START; c <= END; c++)
    {
        PS(sem_empty);
        buf[0] = c;
        printf("Произведено: %c\n", c);
        VS(sem_produced);
    }

    sem_remove(sem_empty);
    sem_remove(sem_produced);
    sem_remove(sem_capitalized);
    return 0;
}
