#include "../src/dtst/dtst.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ---------- CREATE LIST ----------
    list_t *list = list_new();
    printf("✓ List created\n");
    assert(list->head == NULL && list->size == 0);

    // ---------- INSERT NODES ----------
    for (int i = 1; i <= 3; i++) {
        list_ins(list, i);
    }
    printf("✓ Nodes inserted\n");
    assert(list->size == 3);
    assert(list->head->data == 3); // head should be last inserted

    // ---------- REMOVE HEAD ----------
    list_rem(list, 3);
    printf("✓ Head removed\n");
    assert(list->size == 2);
    assert(list->head->data == 2);

    // ---------- REMOVE MIDDLE ----------
    list_rem(list, 2);
    printf("✓ Middle removed\n");
    assert(list->size == 1);
    assert(list->head->data == 1);

    // ---------- REMOVE LAST ----------
    list_rem(list, 1);
    printf("✓ Last removed\n");
    assert(list->size == 0);
    assert(list->head == NULL);

    // ---------- REMOVE NON-EXISTENT ----------
    list_rem(list, 100); // should do nothing
    printf("✓ Remove non-existent node passed\n");
    assert(list->size == 0);
    assert(list->head == NULL);

    // ---------- INSERT AFTER EMPTY ----------
    list_ins(list, 42);
    printf("✓ Insert after empty list\n");
    assert(list->size == 1);
    assert(list->head->data == 42);

    // ---------- REMOVE FROM SINGLE ELEMENT ----------
    list_rem(list, 42);
    printf("✓ Remove single element\n");
    assert(list->size == 0);
    assert(list->head == NULL);

    // ---------- MULTIPLE INSERTS ----------
    list_ins(list, 10);
    list_ins(list, 20);
    list_ins(list, 30);
    printf("✓ Multiple inserts\n");
    assert(list->size == 3);
    assert(list->head->data == 30);

    // ---------- CLEANUP ----------
    list_free(list);
    printf("✓ List freed successfully\n");

    printf("\nAll singly linked list tests passed! 🎉\n");
    return 0;
}
