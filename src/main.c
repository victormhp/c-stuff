#include "algorithms.h"
#include "cmd.h"
#include "data-structures.h"
#include "problems.h"
#include "utils.h"
#include <stdio.h>

void testMinHeap();

int main() {
	int arr[] = {10, 8, 9, 3, 2, 4, 7};
	int size = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, size);
	printArray(arr, size);
	return 0;
}

void testMinHeap() {
	MinHeap *heap = createMinHeap();

	// Insert to heap
	insertHeap(heap, 12);
	insertHeap(heap, 5);
	insertHeap(heap, 3);
	insertHeap(heap, 32);
	insertHeap(heap, 8);

	printArray(heap->arr, heap->size);

	// Extract minimum
	int min = extractMinHeap(heap);
	printf("Min: %d\n", min);
	printArray(heap->arr, heap->size);

	// Delete at index
	deleteAtIndexHeap(heap, 0);
	printArray(heap->arr, heap->size);

	// Build from array
	int arr[] = {22, 11, 33, 44, 55, 12, 25};
	int size = sizeof(arr) / sizeof(arr[0]);
	buildHeap(heap, arr, size);
	printArray(heap->arr, heap->size);

	free(heap->arr);
	free(heap);
}
