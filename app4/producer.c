#include <stdio.h>
#include "../shared/shared.h"
#include "common.h"

int main(void)
{
    void *mem = getmem(SEED_ID);
    volatile int *lock = (volatile int *)mem;
    char *buf = (char *)(lock + 1);

    *lock = 0;
    buf[0] = 0;

    for (char c = START; c <= END; c++)
    {
        while (testandset(lock));
        buf[0] = c;
        printf("Произведено: %c\n", c);
        *lock = 0;
    }

    return 0;
}
