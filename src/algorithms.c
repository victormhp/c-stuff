#include "algorithms.h"
#include "utils.h"

void insertionSort(int nums[], int size) {
	for (int i = 1; i < size; i++) {
		int key = nums[i];
		int j = i - 1;

		while (key < nums[j] && j >= 0) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = key;
	}
}

void insertionSortRecursive(int nums[], int size) {
	if (size <= 1) {
		return;
	}

	insertionSortRecursive(nums, size - 1);

	int key = nums[size - 1];
	int j = size - 2;
	while (j >= 0 && key < nums[j]) {
		nums[j + 1] = nums[j];
		j--;
	}

	nums[j + 1] = key;
}

void shellSort(int nums[], int size) {
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i++) {
			int key = nums[i];
			int j;
			for (j = i; j >= gap && nums[j - gap] > key; j -= gap) {
				nums[j] = nums[j - gap];
			}

			nums[j] = key;
		}
	}
}

void bubbleSort(int nums[], int size) {
	bool swapped;
	for (int i = 0; i < size - 1; i++) {
		swapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
				swapped = true;
			}
		}

		if (swapped == false) {
			break;
		}
	}
}

void selectionSort(int nums[], int size) {
	for (int i = 0; i < size; i++) {
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (nums[min_index] > nums[j]) {
				int temp = nums[min_index];
				nums[min_index] = nums[j];
				nums[j] = temp;
			}
		}
	}
}

void mergeSort(int nums[], int l, int r) {
	if (l >= r)
		return;

	int m = l + (r - l) / 2;
	mergeSort(nums, l, m);
	mergeSort(nums, m + 1, r);
	merge(nums, l, m, r);
}

void mergeSortIterative(int nums[], int size) {
	for (int curr_size = 1; curr_size < size; curr_size *= 2) {
		for (int l = 0; l < size; l += curr_size * 2) {
			int mid = l + curr_size - 1;
			int r = min(l + 2 * curr_size - 1, size - 1);
			merge(nums, l, mid, r);
		}
	}
}

void merge(int nums[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = nums[l + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = nums[m + 1 + i];
	}

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			nums[k] = L[i];
			i++;
		} else {
			nums[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		nums[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		nums[k] = R[j];
		j++;
		k++;
	}
}

void heapify(int nums[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	printf("largest: %d l: %d r: %d\n", nums[largest], nums[l], nums[r]);

	if (l < n && nums[l] > nums[largest]) {
		largest = l;
	}

	if (r < n && nums[r] > nums[largest]) {
		largest = r;
	}

	if (largest != i) {
		printf("Heapify Swap: %d - %d\n\n", nums[largest], nums[i]);
		int temp = nums[largest];
		nums[largest] = nums[i];
		nums[i] = temp;
		heapify(nums, n, largest);
	}
}

void heapSort(int nums[], int size) {
	for (int i = (size / 2) - 1; i >= 0; i--) {
		heapify(nums, size, i);
	}

	printArray(nums, size);

	for (int i = size - 1; i > 0; i--) {
		printf("Iteration: %d Swap: %d - %d\n", i, nums[0], nums[i]);
		int temp = nums[0];
		nums[0] = nums[i];
		nums[i] = temp;

		heapify(nums, i, 0);
	}
}

int linearSearch(int nums[], int size, int value) {
	for (int i = 0; i < size; i++) {
		if (nums[i] == value) {
			return i;
		}
	}
	return -1;
}

int binarySearch(int nums[], int low, int high, int value) {
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (nums[mid] == value) {
			return mid;
		} else if (nums[mid] > value) {
			high = mid - 1;
		} else if (nums[mid] < value) {
			low = mid + 1;
		}
	}

	return -1;
}

int binarySearchRecursive(int nums[], int low, int high, int value) {
	if (low <= high) {
		int mid = low + (high - low) / 2;
		if (nums[mid] == value) {
			return mid;
		} else if (nums[mid] > value) {
			return binarySearchRecursive(nums, low, mid - 1, value);
		} else {
			return binarySearchRecursive(nums, mid + 1, high, value);
		}
	}

	return -1;
}
