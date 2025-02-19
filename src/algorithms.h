#ifndef ALGORITHMS
#define ALGORITHMS

#include "utils.h"
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

// Sorting
void insertionSort(int nums[], int size);
void insertionSortRecursive(int nums[], int size);
void shellSort(int nums[], int size);
void bubbleSort(int nums[], int size);
void selectionSort(int nums[], int size);
void mergeSort(int nums[], int l, int r);
void mergeSortIterative(int nums[], int size);
void merge(int nums[], int l, int m, int r);
void heapify(int nums[], int size, int i);
void heapSort(int nums[], int size);
void quickSort(int nums[], int size);

// Searching
int linearSearch(int nums[], int size, int value);
int binarySearch(int nums[], int low, int high, int value);
int binarySearchRecursive(int nums[], int low, int high, int value);

// DFS
typedef struct {
	int x, y;
} Node;

typedef struct {
	Node *data;
	int top, capacity;
} Stack;

Stack *createNewStack(int capacity);
void pushToStack(Stack *stack, int x, int y);
Node popStack(Stack *stack);
bool isStackEmpty(Stack *stack);
void freeStack(Stack *stack);

void depthFirstSearch(int grid[ROWS][COLS], int x, int y);

#endif
