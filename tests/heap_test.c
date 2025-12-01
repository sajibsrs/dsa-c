#include "../src/dtst/dtst.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ---------- CREATE HEAP ----------
    heap_t *heap = heap_new(10); // 1-based, last = 0
    printf("✓ Heap created\n");
    assert(heap->last == 0 && heap->size == 10);

    // ---------- INSERT ELEMENTS ----------
    int vals[] = {0, 5, 3, 8, 1, 9}; // 1-based array
    for (int i = 1; i <= 5; i++) {
        int res = heapmax_ins(heap, vals[i]);
        assert(res == 0);
    }
    printf("✓ Elements inserted\n");
    assert(heap->last == 5);

    // ---------- CHECK HEAP PROPERTY ----------
    for (int i = 1; i <= heap->last / 2; i++) {
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left <= heap->last) assert(heap->array[i] >= heap->array[left]);
        if (right <= heap->last) assert(heap->array[i] >= heap->array[right]);
    }
    printf("✓ Heap property valid after insertion\n");

    // ---------- REMOVE MAX ----------
    int max = heapmax_rem(heap);
    printf("Removed max: %d\n", max);
    assert(max == 9);
    assert(heap->last == 4);

    // ---------- CHECK HEAP PROPERTY AFTER REMOVAL ----------
    for (int i = 1; i <= heap->last / 2; i++) {
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left <= heap->last) assert(heap->array[i] >= heap->array[left]);
        if (right <= heap->last) assert(heap->array[i] >= heap->array[right]);
    }
    printf("✓ Heap property valid after removal\n");

    // ---------- HEAPIFY TEST ----------
    int arr[] = {0, 3, 1, 6, 5, 2, 4}; // 1-based
    int len = 6;
    heap_t *heap2 = heapmax_heapify(arr, len); // create heap from array

    // Validate heap property
    for (int i = 1; i <= heap2->last / 2; i++) {
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left <= heap2->last) assert(heap2->array[i] >= heap2->array[left]);
        if (right <= heap2->last) assert(heap2->array[i] >= heap2->array[right]);
    }
    printf("✓ Heapify test passed\n");

    // ---------- CLEANUP ----------
    heap_free(heap);
    heap_free(heap2);
    printf("✓ Heaps freed successfully\n");

    printf("\nAll heap tests passed! 🎉\n");
    return 0;
}
