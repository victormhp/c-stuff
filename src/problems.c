#include "problems.h"

// You are given two arrays a and b sorted in non-decreasing order.
// Determine if there is a number that occurs in both arrays. Time O(n)
int findCommonElement(int a[], int a_len, int b[], int b_len) {
	int i = 0, j = 0;

	while (i < a_len && j < b_len) {
		if (a[i] < b[j]) {
			i++;
		} else if (a[i] > b[j]) {
			j++;
		} else {
			return 1;
		}
	}

	return 0;
}

// You are given two arrays a and b sorted in non-decreasing order.
// Find i and j such that the difference |ai − bj | is minimal. Time O(n).
void minimalDifference(int a[], int a_len, int b[], int b_len) {
	int i = 0, j = 0, n1 = 0, n2 = 0;
	int diff = INT_MAX;

	while (i < a_len && j < b_len) {
		int currDiff = abs(a[i] - b[j]);
		if (currDiff < diff) {
			n1 = a[i];
			n2 = b[j];
			diff = currDiff;
		}

		if (a[i] < b[j]) {
			i++;
		} else {
			j++;
		}
	}

	printf("Difference between %d and %d: %d\n", n1, n2, diff);
}

// You are given two arrays a and b sorted in non-decreasing order and a number S.
// Find such i and j such that the sum ai + bj = S. Time O(n).
void twoSum(int a[], int a_len, int b[], int b_len, int S) {
	int i = 0, j = b_len - 1;
	while (i < a_len && j > 0) {
		int sum = a[i] + b[j];
		if (sum < S) {
			i++;
		} else if (sum > S) {
			j--;
		} else {
			printf("Sum: %d + %d = %d\n", a[i], b[j], S);
			return;
		}
	}
	printf("NO!\n");
}

// You are given two arrays a and b sorted in non-decreasing order. 
// Find the number of pairs (i, j) such that ai = bj. Time O(n)
int countEqualPairs(int a[], int a_len, int b[], int b_len) {
	int i = 0, j= 0, count = 0;

	while (i < a_len && j < b_len) {
		if (a[i] < b[j]) {
			i++;
		} else if (a[i] > b[j]) {
			j++;
		} else {
			int a_count = 0, b_count = 0, a_curr = a[i], b_curr = b[j];

			while (i < a_len && a[i] == a_curr) {
				a_count++;
				i++;
			}

			while (j < b_len && b[j] == b_curr) {
				b_count++;
				j++;
			}

			count += a_count * b_count;
		}
	}

	return count;
}

// You are given two arrays a and b sorted in non-decreasing order. 
// Find the number of pairs (i, j) such that ai > bj. Time O(n).
int countGreaterPairs(int a[], int a_len, int b[], int b_len) {
	int i = 0, j= 0, count = 0;

	while (i < a_len && j < b_len) {
		if (a[i] > b[j]) {
			count += a_len - i;
			j++;
		} else {
			i++;
		}
	}

	return count;
}

// Given an array a. The pair (i, j) such that i < j and ai > aj is called inversion. 
// Find the number of inversions in array a. Time O(n log n).
//
// Show that, with the correct implementation, merge sort is stable 
// (that is, does not change the order of equal elements).
//
// Show how to implement merge sort with a single additional array of size n 
// (without constructing new arrays in each recursive call.
int countInversions(Element a[], Element temp[], int l, int r) {
	if (l >= r) return 0;

	int m = (r - l) / 2 + l;
	int inversions = 0;

	inversions += countInversions(a, temp, l, m);
	inversions += countInversions(a, temp, m + 1, r);
	inversions += countInversionsMerge(a, temp, l, m ,r);

	return inversions;
}

int countInversionsMerge(Element a[], Element temp[], int l, int m, int r) {
	// int n1 = m - l + 1;
	// int n2 = r - m;
	
	// Element L[n1], R[n2];
	// for (int i = 0; i < n1; i++) {
	// 	L[i] = a[l + i];
	// }
	// for (int i = 0; i < n2; i++) {
	// 	R[i] = a[m + 1 + i];
	// }

	int i = l, j = m + 1, k = l;
	int inversions = 0;

	while (i <= m && j <= r) {
		if (a[i].value <= a[j].value) {
			temp[k] = a[i];
			i++;
		} else {
			temp[k] = a[j];
			j++;
			inversions += (m - i);
		}
		k++;
	}

	while (i <= m) {
		temp[k] = a[i];
		i++;
		k++;
	}

	while (j <= r) {
		temp[k] = a[j];
		j++;
		k++;
	}

	for (int i = l; i <= r; i++) {
		a[i] = temp[i];
	}

	return inversions;
}
