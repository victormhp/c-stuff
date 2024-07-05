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

void printArray(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[1]);
    int i = binarySearch(arr, 0, size, 2);
    int j = binarySearchRecursive(arr, 0, size, 2);
    printf("Value: %d\n", i);
    printf("Value Recursive: %d\n", j);
}
