#include "../helper.h"
#include "dtst.h"

static void swap(pquen_t *u, pquen_t *v) {
    pquen_t temp = *u;
    *u = *v;
    *v = temp;
}

pque_t *pque_new(int cap) {
    pque_t *pq = _malloc(sizeof(pque_t));
    pq->heap = _malloc(cap * sizeof(pquen_t));
    pq->size = 0;
    pq->cap = cap;

    return pq;
}

int pque_push(pque_t *pq, void *data, int prio) {
    if (pq->size == pq->cap) return -2;

    int idx = pq->size;
    pq->heap[idx].data = data;
    pq->heap[idx].prio = prio;
    pq->size++;

    // Bubble up
    while (idx > 0) {
        int parent = (idx - 1) / 2;

        if (pq->heap[parent].prio >= pq->heap[idx].prio) break;
        swap(&pq->heap[parent], &pq->heap[idx]);
        idx = parent;
    }
    return 0;
}

void *pque_pop(pque_t *pq) {
    if (!pq->size) return NULL;

    void *data = pq->heap[0].data;
    pq->size--;
    pq->heap[0] = pq->heap[pq->size];

    int idx = 0;
    // Bubble down
    while (1) {
        int max = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < pq->size && pq->heap[left].prio > pq->heap[max].prio) max = left;
        if (right < pq->size && pq->heap[right].prio > pq->heap[max].prio) max = right;

        if (max == idx) break;

        swap(&pq->heap[max], &pq->heap[idx]);
        idx = max;
    }
    return data;
}

// TODO: pque_peek

// TODO: pque_update

// TODO: pque_free
