#include "utils.h"

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
