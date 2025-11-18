#include "../helper.h"
#include "dtst.h"

aque_t *aque_new(int capacity) {
    aque_t *queue = _malloc(sizeof(aque_t));
    queue->capacity = capacity;
    queue->front = 0;
    queue->back = -1;
    queue->size = 0;
    queue->array = _malloc(capacity * sizeof(int));

    return queue;
}

void aque_enq(aque_t *queue, int data) {
    if (queue->size == queue->capacity) {
        int precap = queue->capacity;
        queue->capacity *= 2;

        int *newarr = _malloc(queue->capacity * sizeof(int));

        for (int i = 0; i < queue->size; i++) {
            newarr[i] = queue->array[(queue->front + i) % precap];
        }
        _free(queue->array);
        queue->array = newarr;
        queue->front = 0;
        queue->back = queue->size - 1;
    }
    queue->back = (queue->back + 1) % queue->capacity;
    queue->array[queue->back] = data;
    queue->size++;
}

int aque_deq(aque_t *queue) {
    if (queue->size == 0) return -1;

    int data = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    if (queue->size == 0) {
        queue->front = 0;
        queue->back = -1;
    }

    return data;
}

int aque_peek(aque_t *queue) {
    if (queue->size == 0) return -1;
    return queue->array[queue->front];
}

void aque_free(aque_t *queue) {
    _free(queue->array);
    _free(queue);
}
