#include "../helper.h"
#include "dtst.h"

static void swapi(int *u, int *v) {
    int temp = *u;
    *u = *v;
    *v = temp;
}

pqueue_t *pqueue_new(int cap) {
    pqueue_t *pq = _malloc(sizeof(pqueue_t));
    pq->heap = _malloc(cap * sizeof(pqelem_t));
    pq->size = 0;
    pq->cap = cap;

    return pq;
}

int pqueue_push(pqueue_t *pq, void *data, int prio) {
    if (pq->size == pq->cap) return -2;

    int idx = pq->size;
    pq->heap[idx].data = data;
    pq->heap[idx].prio = prio;
    pq->size++;

    // Bubble up
    while (idx > 0) {
        int parent = (idx - 1) / 2;

        if (pq->heap[parent].prio >= pq->heap[idx].prio) break;
        swapi(&pq->heap[parent], &pq->heap[idx]);
        idx = parent;
    }
    return 0;
}

void *pqueue_pop(pqueue_t *pq) {
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
        swapi(&pq->heap[max], &pq->heap[idx]);
        idx = max;
    }
    return data;
}

// TODO: pqueue_peek

// TODO: pqueue_update

// TODO: pqueue_free
