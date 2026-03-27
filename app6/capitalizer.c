#include <stdio.h>
#include <ctype.h>
#include "capitalizer.h"

void capitalizer(char *buf, sem_t sem_produced, sem_t sem_capitalized)
{
    for (char c = START; c <= END; c++)
    {
        PS(sem_produced);
        buf[0] = toupper(buf[0]);
        printf("Капитализирано: %c\n", buf[0]);
        VS(sem_capitalized);
    }
}
