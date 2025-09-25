#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/dtst/dtst.h"

void destroy_int(void *data) {
    free(data);
}

int main(void) {
    dlist_t list;
    dlist_init(&list, destroy_int);

    // Test 1: Insert at head
    for (int i = 1; i <= 3; i++) {
        int *val = malloc(sizeof(int));
        *val = i * 10;
        dlist_head_ins(&list, val);
    }

    assert(list.size == 3);
    assert(*(int *)list.head->data == 30); // Last inserted at head
    assert(*(int *)list.tail->data == 10); // First inserted at tail
    printf("✓ All inserts successful\n");

    // Test 2: Verify doubly links
    assert(list.head->next->prev == list.head); // Head's next's prev should point back to head
    assert(list.tail->prev->next == list.tail); // Tail's prev's next should point forward to tail
    printf("✓ Doubly links verified\n");

    // Test 3: Remove from tail
    void *data;
    dlist_tail_rem(&list, &data);
    assert(*(int *)data == 10);
    assert(list.size == 2);
    assert(*(int *)list.tail->data == 20); // New tail
    assert(list.tail->next == NULL);       // Tail should point to NULL
    free(data);
    printf("✓ Tail removal works\n");

    // Test 4: Remove another tail
    dlist_tail_rem(&list, &data);
    assert(*(int *)data == 20);
    assert(list.size == 1);
    assert(*(int *)list.tail->data == 30); // Only one item left
    assert(list.head == list.tail);        // Head and tail should be same
    assert(list.head->prev == NULL);       // Single item prev should be NULL
    assert(list.head->next == NULL);       // Single item next should be NULL
    free(data);
    printf("✓ Single item removal works\n");

    // Test 5: Remove last item (empty list)
    dlist_tail_rem(&list, &data);
    assert(*(int *)data == 30);
    assert(list.size == 0);
    assert(list.head == NULL);
    assert(list.tail == NULL);
    free(data);
    printf("✓ Empty list creation works\n");

    // Test 6: Remove from empty list (should fail)
    assert(dlist_tail_rem(&list, &data) == false);
    printf("✓ Empty list removal fails correctly\n");

    // Test 7: Insert after empty and test forward/backward traversal
    int *val = malloc(sizeof(int));
    *val = 100;
    dlist_head_ins(&list, val);

    val = malloc(sizeof(int));
    *val = 200;
    dlist_head_ins(&list, val); // List: 200->100

    assert(list.size == 2);
    assert(*(int *)list.head->data == 200);
    assert(*(int *)list.tail->data == 100);
    assert(list.head->next == list.tail);
    assert(list.tail->prev == list.head);
    printf("✓ Doubly links work correctly\n");

    // Test 8: Forward traversal
    dlist_node_t *node = list.head;
    assert(*(int *)node->data == 200);
    node = node->next;
    assert(*(int *)node->data == 100);
    assert(node == list.tail);
    printf("✓ Forward traversal works\n");

    // Test 9: Backward traversal
    node = list.tail;
    assert(*(int *)node->data == 100);
    node = node->prev;
    assert(*(int *)node->data == 200);
    assert(node == list.head);
    printf("✓ Backward traversal works\n");

    // Cleanup
    dlist_rem(&list);
    assert(list.size == 0);
    assert(list.head == NULL);
    assert(list.tail == NULL);
    printf("✓ Complete cleanup successful\n");

    printf("\nAll doubly linked list tests passed! 🎉\n");
    return 0;
}
