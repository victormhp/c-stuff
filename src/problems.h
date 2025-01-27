#ifndef PROBLEMS
#define PROBLEMS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findCommonElement(int a[], int a_len, int b[], int b_len);
void minimalDifference(int a[], int a_len, int b[], int b_len);
void twoSum(int a[], int a_len, int b[], int b_len, int S);
int countEqualPairs(int a[], int a_len, int b[], int b_len);
int countGreaterPairs(int a[], int a_len, int b[], int b_len);

typedef struct {
	int value;
	char label;
} Element;

int countInversions(Element a[], Element temp[], int l, int r);
int countInversionsMerge(Element a[], Element temp[], int l, int m, int r);

#endif
