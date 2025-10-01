#include <stdio.h>
#include <assert.h>
#include "../src/dtst/dtst.h"

int main(void) {
    que_t q = {0};

    // Basic operations
    assert(queue_is_empty(&q) && queue_size(&q) == 0);

    queue_enqueue(&q, 10);
    queue_enqueue(&q, 20);
    queue_enqueue(&q, 30);

    assert(!queue_is_empty(&q) && queue_size(&q) == 3);
    assert(queue_peek(&q) == 10);
    assert(queue_dequeue(&q) == 10 && queue_peek(&q) == 20);
    assert(queue_dequeue(&q) == 20 && queue_dequeue(&q) == 30);
    assert(queue_is_empty(&q));
    printf("✓ Basic operations passed\n");

    // Circular behavior
    for (int i = 0; i < QUEUE_SIZE; i++) queue_enqueue(&q, i * 10);
    assert(queue_size(&q) == QUEUE_SIZE);
    queue_dequeue(&q);
    queue_dequeue(&q);
    queue_enqueue(&q, 100);
    queue_enqueue(&q, 200);
    assert(queue_peek(&q) == 20);

    for (int i = 2; i < QUEUE_SIZE; i++) queue_dequeue(&q);
    assert(queue_dequeue(&q) == 100 && queue_dequeue(&q) == 200);
    assert(queue_is_empty(&q));
    printf("✓ Circular behavior passed\n");

    // Edge cases
    assert(queue_dequeue(&q) == -1 && queue_peek(&q) == -1);

    for (int i = 0; i < QUEUE_SIZE; i++) queue_enqueue(&q, i);
    queue_enqueue(&q, 999);
    assert(queue_size(&q) == QUEUE_SIZE);

    while (!queue_is_empty(&q)) queue_dequeue(&q);
    assert(queue_is_empty(&q));
    printf("✓ Edge cases passed\n");

    printf("🎉 All queue tests passed!\n");
    return 0;
}
