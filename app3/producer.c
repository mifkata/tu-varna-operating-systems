#include <stdio.h>
#include "../shared/shared.h"
#include "common.h"

int main(void)
{
    char *buf = (char *)getmem(SEED_ID);

    for (char c = 'a'; c <= 'z'; c++)
    {
        buf[0] = c;
        printf("Произведено: %c\n", c);
    }

    return 0;
}
