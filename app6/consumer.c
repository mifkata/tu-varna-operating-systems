#include <stdio.h>
#include "consumer.h"

void consumer(char *buf, sem_t sem_capitalized, sem_t sem_empty)
{
    for (char c = START; c <= END; c++)
    {
        PS(sem_capitalized);
        printf("Консумирано: %c\n", buf[0]);
        VS(sem_empty);
    }
}
