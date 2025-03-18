#ifndef DATA_STRUCTURES
#define DATA_STRUCTURES

#include <stdbool.h>
#include "utils.h"

#define HEAP_CAPACITY 10
#define MAX_SIZE 100

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
void buildHeap(MinHeap *heap, int *arr, int size);
void testMinHeap();

// Static Stack
typedef struct {
	int arr[MAX_SIZE];
	int top;
	int capacity;
} Stack;

void initStack(Stack *s);
bool isNodeStackEmpty(Stack *s);
bool isStackFull(Stack *s);
void pushStack(Stack *s, int value);
int popStack(Stack *s);
int peekStack(Stack *s);
void testStack();

// Static Queue
typedef struct {
	int arr[MAX_SIZE];
	int back, front;
	int capacity;
} Queue;

void initQueue(Queue *q);
bool isQueueEmpty(Queue *q);
bool isQueueFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peekQueue(Queue *q);
void testQueue();

#endif
