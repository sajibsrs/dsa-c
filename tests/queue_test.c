#include "../src/dtst/dtst.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    printf("Testing array queue...\n");

    // Create queue
    aque_t *queue = aque_new(3);
    assert(queue->size == 0);
    assert(queue->front == 0);
    assert(queue->back == -1);
    printf("✓ Queue created\n");

    // Simple enqueue
    aque_enq(queue, 10);
    aque_enq(queue, 20);
    aque_enq(queue, 30);
    assert(queue->size == 3);
    assert(queue->front == 0);
    assert(queue->back == 2);
    printf("✓ Enqueued 10, 20, 30\n");

    // Trigger resize
    aque_enq(queue, 40);
    assert(queue->capacity >= 4);
    assert(queue->size == 4);
    assert(queue->front == 0);
    assert(queue->back == 3);
    printf("✓ Resize triggered and 40 enqueued\n");

    // Dequeue in order
    int val = aque_deq(queue);
    assert(val == 10);
    val = aque_deq(queue);
    assert(val == 20);
    printf("✓ Dequeued values 10, 20\n");

    // Wrap-around test
    aque_enq(queue, 50);
    aque_enq(queue, 60);
    val = aque_deq(queue); // 30
    assert(val == 30);
    val = aque_deq(queue); // 40
    assert(val == 40);
    printf("✓ Wrap-around enqueue/dequeue works\n");

    // Dequeue remaining
    val = aque_deq(queue);
    assert(val == 50);
    val = aque_deq(queue);
    assert(val == 60);
    printf("✓ Remaining elements dequeued\n");

    // Dequeue empty
    val = aque_deq(queue);
    assert(val == -1);
    printf("✓ Dequeue on empty returns -1\n");

    // Enqueue after empty
    aque_enq(queue, 70);
    val = aque_deq(queue);
    assert(val == 70);
    printf("✓ Enqueue/dequeue after empty works\n");

    // Clean up
    aque_free(queue);
    printf("✓ Queue freed successfully\n");

    printf("\n🎉 All array queue tests passed!\n");
    return 0;
}
