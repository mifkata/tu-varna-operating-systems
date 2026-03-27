#include <stdio.h>
#include "producer.h"

void producer(char *buf, sem_t sem_empty, sem_t sem_produced)
{
    for (char c = START; c <= END; c++)
    {
        PS(sem_empty);
        buf[0] = c;
        printf("Произведено: %c\n", c);
        VS(sem_produced);
    }
}
