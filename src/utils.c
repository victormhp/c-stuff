#include "utils.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int *generateRandomArray(int size, int min, int max) {
	int *arr = (int *)malloc(size * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % (max - min + 1)) + min;
	}

	return arr;
}

int sumArray(int arr[], int size) {
	int res = 0;
	for (int i = 0; i < size; i++) {
		res += arr[i];
	}
	return res;
}

int productArray(int arr[], int size) {
	int res = 1;
	for (int i = 0; i < size; i++) {
		res *= arr[i];
	}
	return res;
}

void printRandomNumbers(int min, int max, int count) {
	printf("Random numbers between %d and %d: ", min, max);

	srand(time(NULL));

	for (int i = 0; i < count; i++) {
		int r_num = rand() % (max - min + 1) + min;
		printf("%d ", r_num);
	}

	printf("\n");
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int min(int a, int b) { return (a > b) ? b : a; }

int findMinElement(int a[], int size) {
	int min = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] < a[min]) {
			min = i;
		}
	}
	return min;
}

int findMaxElement(int a[], int size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] > a[max]) {
			max = i;
		}
	}
	return max;

}
