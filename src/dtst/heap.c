#include "../helper.h"
#include "./dtst.h"

heap_t *heap_new(const int size) {
    heap_t *heap = _malloc(sizeof(heap_t));
    heap->array = _malloc((size + 1) * sizeof(int)); // +1 for 1-based indexing
    heap->size = size;
    heap->last = 0;
    return heap;
}

int heapmax_ins(heap_t *heap, int value) {
    if (heap->last == heap->size - 1) return -1;

    heap->last++;
    heap->array[heap->last] = value;

    int current = heap->last;
    int parent = current / 2;

    // Bubble up
    while (parent >= 1 && (heap->array[parent] < heap->array[current])) {
        int temp = heap->array[parent];

        heap->array[parent] = heap->array[current];
        heap->array[current] = temp;

        current = parent;
        parent = current / 2;
    }
    return 0;
}

int heapmax_rem(heap_t *heap) {
    if (heap->last == 0) return -1;

    // Swap root and last
    int max = heap->array[1];
    heap->array[1] = heap->array[heap->last];
    heap->last--;

    // Bubble down
    int idx = 1;
    while (idx <= heap->last) {
        int parent = idx;
        int left = 2 * idx;
        int right = 2 * idx + 1;

        if (left <= heap->last && (heap->array[parent] < heap->array[left])) parent = left;
        if (right <= heap->last && (heap->array[parent] < heap->array[right])) parent = right;

        if (idx == parent) break;

        int temp = heap->array[idx];
        heap->array[idx] = heap->array[parent];
        heap->array[parent] = temp;
        idx = parent;
    }
    return max;
}

heap_t *heapmax_heapify(int *arr, int size) {
    heap_t *heap = heap_new(size); // allocates size+1 internally
    heap->last = size;

    // Copy elements (1-based)
    for (int i = 1; i <= size; i++) {
        heap->array[i] = arr[i];
    }

    // Heapify
    for (int i = size / 2; i >= 1; i--) {
        int idx = i;
        while (1) {
            int parent = idx;
            int left = 2 * idx;
            int right = 2 * idx + 1;

            if (left <= size && heap->array[left] > heap->array[parent]) parent = left;
            if (right <= size && heap->array[right] > heap->array[parent]) parent = right;

            if (idx == parent) break;

            int temp = heap->array[idx];
            heap->array[idx] = heap->array[parent];
            heap->array[parent] = temp;

            idx = parent;
        }
    }

    return heap;
}

void heap_free(heap_t *heap) {
    _free(heap->array);
    _free(heap);
}
