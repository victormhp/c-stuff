#ifndef ALGORITHMS
#define ALGORITHMS

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

// Sorting
void insertionSort(int nums[], int size);
void insertionSortRecursive(int nums[], int size);
void shellSort(int nums[], int size);
void bubbleSort(int nums[], int size);
void selectionSort(int nums[], int size);
void mergeSort(int nums[], int l, int r);
void merge(int nums[], int l, int m, int r);

// Searching
int linearSearch(int nums[], int size, int value);
int binarySearch(int nums[], int low, int high, int value);
int binarySearchRecursive(int nums[], int low, int high, int value);

// Problems
int* pairSum(int nums[], int size, int target); // Worst case time - O(nlog(n))
int* pairSumFast(int nums[], int size, int target); // Worst case time - O(n)
void prefixSum(int nums[], int size);

#endif
