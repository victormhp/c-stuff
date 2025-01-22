#include "utils.h"

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
