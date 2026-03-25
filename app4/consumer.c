#include <stdio.h>
#include "../shared/shared.h"
#include "common.h"

int main(void)
{
    void *mem = getmem(SEED_ID);
    volatile int *lock = (volatile int *)mem;
    char *buf = (char *)(lock + 1);

    for (char c = START; c <= END; c++)
    {
        while (buf[0] == 0 || testandset(lock));
        printf("Консумирано: %c\n", buf[0]);
        *lock = 0;
    }

    return 0;
}
