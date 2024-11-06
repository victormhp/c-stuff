#include "algorithms.h"
#include "cmd.h"
#include "utils.h"
#include <stdlib.h>

int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
    prefixSum(arr, size);
    printArray(arr, size);
    return 0;
}
