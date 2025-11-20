#include "../src/dtst/dtst.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    printf("Testing fixed-size array queue...\n");

    aque_t *queue = aque_new(3);
    assert(queue->size == 0);
    assert(queue->front == 0);
    assert(queue->back == -1);
    printf("✓ Queue created\n");

    // Fill queue
    assert(aque_enq(queue, 10) == 1);
    assert(aque_enq(queue, 20) == 1);
    assert(aque_enq(queue, 30) == 1);

    assert(queue->size == 3);
    printf("✓ Enqueued 10, 20, 30\n");

    // Enqueue when full → should fail
    assert(aque_enq(queue, 40) == 0);
    assert(queue->size == 3);
    printf("✓ Enqueue on full returns 0\n");

    // Dequeue in order
    assert(aque_deq(queue) == 10);
    assert(aque_deq(queue) == 20);
    printf("✓ Dequeued 10, 20\n");

    // Wrap-around works
    assert(aque_enq(queue, 40) == 1);
    assert(aque_enq(queue, 50) == 1);
    printf("✓ Wrap-around enqueue works\n");

    // Now queue is full again
    assert(aque_enq(queue, 60) == 0);
    printf("✓ Full queue detected again\n");

    // Dequeue remaining
    assert(aque_deq(queue) == 30);
    assert(aque_deq(queue) == 40);
    assert(aque_deq(queue) == 50);
    printf("✓ Remaining dequeued\n");

    // Empty queue returns -1
    assert(aque_deq(queue) == -1);
    printf("✓ Dequeue empty returns -1\n");

    // Works again after empty
    assert(aque_enq(queue, 99) == 1);
    assert(aque_deq(queue) == 99);
    printf("✓ Enqueue/dequeue after empty works\n");

    aque_free(queue);
    printf("✓ Queue freed\n");

    printf("\n🎉 All fixed-size queue tests passed!\n");
    return 0;
}
