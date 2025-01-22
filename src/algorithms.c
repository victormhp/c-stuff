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
	if (l >= r) {
		return;
	}

	int m = l + (r - l) / 2;
	mergeSort(nums, l, m);
	mergeSort(nums, m + 1, r);
	merge(nums, l, m, r);
}

void merge(int *nums, int l, int m, int r) {
	int nl = m - l + 1;
	int nr = r - m;
	int L[nl], R[nr];

	for (int i = 0; i < nl; i++) {
		L[i] = nums[l + i];
	}
	for (int j = 0; j < nr; j++) {
		R[j] = nums[m + 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = l;

	while (i < nl && j < nr) {
		if (L[i] <= R[j]) {
			nums[k] = L[i];
			i++;
		} else {
			nums[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < nl) {
		nums[k] = L[i];
		i++;
		k++;
	}

	while (j < nr) {
		nums[k] = R[j];
		j++;
		k++;
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

int *pairSum(int nums[], int size, int target) {
	mergeSort(nums, 0, size - 1);

	for (int i = 0; i < size; i++) {
		int complement = target - nums[i];
		int low = 0;
		int high = size - 1;

		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] == complement) {
				int *res = (int *)malloc(2 * sizeof(int));
				res[0] = i;
				res[1] = mid;
				return res;
			} else if (mid < complement) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
	}

	return NULL;
}

int *pairSumFast(int nums[], int size, int target) {
	int *map = (int *)malloc((target + 1) * sizeof(int));
	for (int i = 0; i <= target; i++) {
		map[i] = -1;
	}

	for (int i = 0; i < size; i++) {
		int complement = target - nums[i];
		if (map[complement] != -1) {
			int *res = (int *)malloc(2 * sizeof(int));
			res[0] = map[complement];
			res[1] = i;
			free(map);
			return res;
		}
		map[nums[i]] = i;
	}

	free(map);
	return NULL;
}

void prefixSum(int nums[], int size) {
	for (int i = 1; i < size; i++) {
		nums[i] = nums[i - 1] + nums[i];
	}
}
