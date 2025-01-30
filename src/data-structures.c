#include "data-structures.h"

// Min Binary Heap
MinHeap *createMinHeap() {
	MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
	heap->arr = (int *)malloc(HEAP_CAPACITY * sizeof(int));
	heap->capacity = HEAP_CAPACITY;
	heap->size = 0;
	return heap;
}

void heapifyDown(MinHeap *heap, int i) {
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < heap->size && heap->arr[l] < heap->arr[smallest]) {
		smallest = l;
	}

	if (r < heap->size && heap->arr[r] < heap->arr[smallest]) {
		smallest = r;
	}

	if (smallest != i) {
		swap(&heap->arr[i], &heap->arr[smallest]);
		heapifyDown(heap, smallest);
	}
}

void heapifyUp(MinHeap *heap, int i) {
	int parent = (i - 1) / 2;

	if (i > 0 && heap->arr[i] < heap->arr[parent]) {
		swap(&heap->arr[i], &heap->arr[parent]);
		heapifyUp(heap, parent);
	}
}

void insertHeap(MinHeap *heap, int value) {
	if (heap->size == heap->capacity) {
		heap->capacity *= 2;
		heap->arr = (int *)realloc(heap->arr, heap->capacity * sizeof(int));
	}

	heap->arr[heap->size] = value;
	heap->size++;

	heapifyUp(heap, heap->size - 1);
}

int extractMinHeap(MinHeap *heap) {
	if (heap->size == 0) {
		return -1;
	}

	int min = heap->arr[0];
	heap->arr[0] = heap->arr[heap->size - 1];
	heap->size--;

	heapifyDown(heap, 0);
	return min;
}

int peekHeap(MinHeap *heap) {
	if (heap->size == 0) {
		return -1;
	}
	return heap->arr[0];
}

void deleteAtIndexHeap(MinHeap *heap, int i) {
	if (i >= heap->size) {
		return;
	}

	heap->arr[i] = heap->arr[heap->size - 1];
	heap->size--;

	heapifyDown(heap, i);
}

void buildHeap(MinHeap *heap, int *arr, int size) {
	if (size > heap->capacity) {
		heap->capacity = size;
		heap->arr = (int *)realloc(heap->arr, heap->capacity * sizeof(int));
	}

	for (int i = 0; i < size; i++) {
		heap->arr[i] = arr[i];
	}
	heap->size = size;

	for (int i = (size / 2) - 1; i >= 0; i--) {
		heapifyDown(heap, i);
	}
}
