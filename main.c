#include "algorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateRandomArray(int size, int min, int max)
{
    int* arr = (int*)malloc(size * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % (max - min + 1)) + min;
    }

    return arr;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size = 10;
    int* arr = generateRandomArray(size, 1, 100);
    printArray(arr, size);
    shellSort(arr, size);
    printArray(arr, size);
    free(arr);
}
