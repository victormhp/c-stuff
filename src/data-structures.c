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

// Static Stack
void initStack(Stack *s) {
	s->top = -1;
	s->capacity = MAX_SIZE;
}

bool isStackEmpty(Stack *s) { return s->top == -1; }

bool isStackFull(Stack *s) { return s->top == s->capacity - 1; }

void pushStack(Stack *s, int value) {
	if (isStackFull(s)) {
		return;
	}
	s->arr[++s->top] = value;
}

int popStack(Stack *s) {
	if (isStackEmpty(s)) {
		return -1;
	}
	int value = s->arr[s->top];
	s->top--;
	return value;
}

int peekStack(Stack *s) {
	if (isStackEmpty(s)) {
		return -1;
	}
	int value = s->arr[s->top];
	return value;
}

// Static Circular Queue
void initQueue(Queue *q) {
	q->curr = 0;
	q->front = q->back = -1;
	q->capacity = MAX_SIZE;
}

bool isQueueEmpty(Queue *q) { return q->curr == 0; }

bool isQueueFull(Queue *q) { return q->curr == q->capacity; }

void enqueue(Queue *q, int value) {
	if (isQueueFull(q)) {
		return;
	}

	if (isQueueEmpty(q)) {
		q->front = 0;
	}

	q->back = (q->back + 1) % q->capacity;
	q->arr[q->back] = value;
	q->curr++;
}

int dequeue(Queue *q) {
	if (isQueueEmpty(q)) {
		return -1;
	}

	int item = q->arr[q->front];

	if (q->front == q->back) {
		q->front = q->back = -1;
	} else {
		q->front = (q->front + 1) % q->capacity;
	}

	q->curr--;
	return item;
}

int peekQueue(Queue *q) {
	if (isQueueEmpty(q)) {
		return -1;
	}
	int item = q->arr[q->front];
	return item;
}

void testQueue() {
	Queue q;
	initQueue(&q);

	for (int i = 1; i <= 10; i++) {
		enqueue(&q, i);
	}

	for (int i = 1; i <= 5; i++) {
		dequeue(&q);
	}

	for (int i = q.front; i <= q.back; i++) {
		printf("Queue %d element: %d\n", i, q.arr[i]);
	}
}
