#include "../helper.h"
#include "dtst.h"

static listn_t *node_new(int data) {
    listn_t *node = _malloc(sizeof(listn_t));
    node->data = data;
    node->next = NULL;

    return node;
}

list_t *list_new() {
    list_t *list = _malloc(sizeof(list_t));
    list->size = 0;
    list->head = NULL;

    return list;
}

void list_ins(list_t *list, int data) {
    listn_t *node = node_new(data);
    node->next = list->head;
    list->head = node;

    list->size++;
}

void list_rem(list_t *list, int data) {
    if (list->head == NULL) return;

    listn_t *node = list->head;
    listn_t *prev = NULL;

    while (node) {
        if (node->data == data) {
            if (prev == NULL) {
                list->head = node->next;
            } else {
                prev->next = node->next;
            }
            _free(node);
            list->size--;
            return;
        }
        prev = node;
        node = node->next;
    }
}

void list_free(list_t *list) {
    if (list == NULL) return;

    listn_t *node = list->head;

    while (node) {
        listn_t *next = node->next;
        _free(node);
        node = next;
    }
    _free(list);
}
