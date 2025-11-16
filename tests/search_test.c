#include "../src/algo/algo.h"
#include <stdio.h>
#include <assert.h>

int arr[] = {8, 4, 5, 2, 7, 1, 6, 9, 0};
int linarr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(void) {
    int idx = srchlin(5, arr, 10);
    int binidx = srchbin(5, linarr, 10);

    printf("Search Algorithms:\n");
    printf("----------------------------------\n");

    assert(idx == 2);
    printf("✓ Linear search, Index: %d\n", idx);

    assert(binidx == 5);
    printf("✓ Binary search, Index: %d\n", binidx);
    printf("\n");
    return 0;
}
