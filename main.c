#include "algorithms.h"
#include "utils.h"
#include <stdlib.h>


int main()
{
    int size = 10;
    int* arr = generateRandomArray(size, 1, 100);
    printArray(arr, size);
    shellSort(arr, size);
    printArray(arr, size);
    free(arr);
}
