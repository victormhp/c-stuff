#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);
int *generateRandomArray(int size, int min, int max);
int sumArray(int arr[], int size);
int productArray(int arr[], int size);
void printRandomNumbers(int min, int max, int count);
void printArray(int arr[], int size);
int min(int a, int b);
int findMinElement(int a[], int size); // Return the index for the min element in the array.
int findMaxElement(int a[], int size); // Return the index for the max element in the array.

#endif
