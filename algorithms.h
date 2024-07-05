#ifndef ALGORITHMS
#define ALGORITHMS

#include <stdbool.h>
#include <math.h>

// Sorting
void insertionSort(int arr[], int size);
void insertionSortRecursive(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void mergeSort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);

// Searching
int linearSearch(int arr[], int size, int value);
int binarySearch(int arr[], int low, int high, int value);
int binarySearchRecursive(int arr[], int low, int high, int value);

#endif
