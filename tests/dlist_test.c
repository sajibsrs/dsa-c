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

    // Insert at head
    for (int i = 1; i <= 3; i++) {
        int *val = malloc(sizeof(int));
        *val = i * 10;
        dlist_ins_head(&list, val);
    }

    // Verify insertions (should be 30->20->10)
    assert(list.size == 3);
    assert(*(int *)list.head->data == 30);
    assert(*(int *)list.tail->data == 10);

    // Remove from tail
    void *data;
    dlist_rem_tail(&list, &data);
    assert(*(int *)data == 10);
    free(data);

    assert(list.size == 2);
    assert(*(int *)list.tail->data == 20);

    // Cleanup
    dlist_rem_all(&list);
    assert(list.size == 0);

    printf("All doubly linked list tests passed!\n");
    return 0;
}
