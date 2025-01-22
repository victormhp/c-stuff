#include "algorithms.h"
#include "cmd.h"
#include "utils.h"
#include <stdlib.h>

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Sum: %d\n", sumArray(arr, size));
	return 0;
}
