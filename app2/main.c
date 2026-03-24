#include "functions.h"

int main(void) {
    int arr[SIZE];

    input(arr, SIZE);
    sort(arr, SIZE);
    output(arr, SIZE);

    return 0;
}
