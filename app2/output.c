#include <stdio.h>
#include "functions.h"

void output(const int *arr, int n) {
    printf("Сортирани числа:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
