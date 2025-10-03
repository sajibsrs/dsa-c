#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/dtst/dtst.h"

void destroy_int(void *data) {
    free(data);
}

int main(void) {
    slist_t list;
    slist_init(&list, destroy_int);

    // Test 1: Insert at head
    for (int i = 1; i <= 3; i++) {
        int *val = malloc(sizeof(int));
        *val = i * 10;
        slist_head_ins(&list, val);
    }

    assert(list.size == 3);
    assert(*(int *)list.head->data == 30); // Last inserted at head
    assert(*(int *)list.tail->data == 10); // First inserted at tail
    printf("✓ All inserts successful\n");

    // Test 2: Remove from tail
    void *data;
    slist_tail_rem(&list, &data);
    assert(*(int *)data == 10);
    assert(list.size == 2);
    assert(*(int *)list.tail->data == 20); // New tail
    free(data);
    printf("✓ Tail removal works\n");

    // Test 3: Remove another tail
    slist_tail_rem(&list, &data);
    assert(*(int *)data == 20);
    assert(list.size == 1);
    assert(*(int *)list.tail->data == 30); // Only one item left
    assert(list.head == list.tail);        // Head and tail should be same
    free(data);
    printf("✓ Single item removal works\n");

    // Test 4: Remove last item (empty list)
    slist_tail_rem(&list, &data);
    assert(*(int *)data == 30);
    assert(list.size == 0);
    assert(list.head == NULL);
    assert(list.tail == NULL);
    free(data);
    printf("✓ Empty list creation works\n");

    // Test 5: Remove from empty list (should fail)
    assert(slist_tail_rem(&list, &data) == 0);
    printf("✓ Empty list removal fails correctly\n");

    // Test 6: Insert after empty
    int *val = malloc(sizeof(int));
    *val = 100;
    slist_head_ins(&list, val);
    assert(list.size == 1);
    assert(*(int *)list.head->data == 100);
    assert(list.head == list.tail);
    printf("✓ Insert after empty works\n");

    // Cleanup
    slist_rem(&list);
    assert(list.size == 0);
    assert(list.head == NULL);
    assert(list.tail == NULL);
    printf("✓ Complete cleanup successful\n");

    printf("\nAll singly linked list tests passed! 🎉\n");
    return 0;
}
