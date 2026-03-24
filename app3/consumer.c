#include <stdio.h>
#include "../shared/shared.h"
#include "common.h"

int main(void)
{
    char *buf = (char *)getmem(SEED_ID);

    for (char c = 'a'; c <= 'z'; c++)
    {
        printf("Консумирано: %c\n", buf[0]);
    }

    return 0;
}
