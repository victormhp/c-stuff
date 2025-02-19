#include "algorithms.h"
#include "cmd.h"
#include "data-structures.h"
#include "problems.h"
#include "utils.h"
#include <stdio.h>

void testMinHeap();

int main() {
	int grid[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

	printf("DFS Traversal:\n");
	depthFirstSearch(grid, 0, 0);
	return 0;
}
