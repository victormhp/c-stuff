#ifndef DATA_STRUCTURES
#define DATA_STRUCTURES

#include "utils.h"

#define HEAP_CAPACITY 10

// Min Binary Heap
typedef struct {
	int *arr;
	int capacity;
	int size;
} MinHeap;

MinHeap *createMinHeap();
void heapifyDown(MinHeap *heap, int i);
void heapifyUp(MinHeap *heap, int i);
void insertHeap(MinHeap *heap, int value);
int extractMinHeap(MinHeap *heap);
int peekHeap(MinHeap *heap);
void deleteAtIndexHeap(MinHeap *heap, int i);
void buildHeap(MinHeap *heap, int* arr, int size);

#endif
