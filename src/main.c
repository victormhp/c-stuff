#include "algorithms.h"
#include "cmd.h"
#include "problems.h"
#include "utils.h"
#include <stdio.h>

int main() {
    int a[] = {32, 12, 14, 45, 2};
    int size = sizeof(a) / sizeof(a[0]);
    mergeSortIterative(a, size);
    printArray(a, size);

    return 0;
}
