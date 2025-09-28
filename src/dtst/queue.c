#include <stdio.h>
#include "dtst.h"

void queue_enqueue(iqueue_t *q, int elm) {
    if (q->size == QUEUE_SIZE) {
        printf("Queue is full\n");
        return;
    }
    q->queue[(q->front + q->size) % QUEUE_SIZE] = elm;
    q->size++;
}

int queue_dequeue(iqueue_t *q) {
    if (queue_is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->queue[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->size--;
    return item;
}

int queue_peek(iqueue_t *q) {
    if (queue_is_empty(q)) {
        printf("Queue is empty");
        return -1;
    }
    return q->queue[q->front];
}

int queue_is_empty(iqueue_t *q) {
    return q->size == 0;
}

int queue_size(iqueue_t *q) {
    return q->size;
}

void queue_print(iqueue_t *q) {
    printf("Queue: ");
    for (int i = 0; i < q->size; ++i) {
        printf("%c ", q->queue[(q->front + i) % QUEUE_SIZE]);
    }
    printf("\n");
}
