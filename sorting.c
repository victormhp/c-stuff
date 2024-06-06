#include "sorting.h"

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

void mergeSort(int arr[], int p, int r)
{
    if (p >= r) {
        return;
    }

    int q = p + (r - p) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q + 1, r);
    merge(arr, p, q, r);
}

void merge(int *arr, int p, int q, int r)
{
    // Merge
    int nl = q - p + 1;
    int nr = r - q;
    int L[nl], R[nr];

    for (int i = 0; i < nl; i++) {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < nr; j++) {
        R[j] = arr[q + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = p;

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
