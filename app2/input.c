#include <stdio.h>
#include "functions.h"

void input(int *arr, int n) {
    printf("Въведете %d цели числа:\n", n);
    for (int i = 0; i < n; i++) {
        printf("[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
