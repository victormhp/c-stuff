#include "algorithms.h"

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void insertionSortRecursive(int arr[], int size)
{
    if (size <= 1)
        return;

    insertionSortRecursive(arr, size - 1);

    int key = arr[size - 1];
    int j = size - 2;
    while (j >= 0 && key < arr[j]) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}

void bubbleSort(int arr[], int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min_index] > arr[j]) {
                int temp = arr[min_index];
                arr[min_index] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r) {
        return;
    }

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void merge(int* arr, int l, int m, int r)
{
    int nl = m - l + 1;
    int nr = r - m;
    int L[nl], R[nr];

    for (int i = 0; i < nl; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < nr; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < nl && j < nr) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nl) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < nr) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int linearSearch(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int value)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else if (arr[mid] < value) {
            low = mid + 1;
        }
    }

    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int value)
{
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] > value) {
            return binarySearchRecursive(arr, low, mid - 1, value);
        } else {
            return binarySearchRecursive(arr, mid + 1, high, value);
        }
    }

    return -1;
}


