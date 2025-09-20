#include <stdlib.h>
#include <string.h>

#include "dtst.h"

void list_init(List *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    list->destroy = destroy;
}

void list_destroy(List *list) {
    void *data;

    while (list_size(list) > 0) {
        if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(List));
}

bool list_ins_next(List *list, ListElem *elem, const void *data) {
    ListElem *new_elem;

    if ((new_elem = malloc(sizeof(ListElem))) == NULL) return false;

    new_elem->data = (void *)data;

    if (elem == NULL) {
        if (list_size(list) == 0) {
            list->tail = new_elem;
        }
        new_elem->next = list->head;
        list->head = new_elem;
    } else {
        if (elem->next == NULL) {
            list->tail = new_elem;
        }
        new_elem->next = elem->next;
        elem->next = new_elem;
    }
    list->size++;
    return true;
}

bool list_rem_next(List *list, ListElem *elem, void **data) {
    ListElem *old_elem;

    if (list_size(list) == 0) return false;

    if (elem == NULL) {
        *data = list->head->data;
        old_elem = list->head;
        list->head = list->head->next;

        if (list_size(list) == 1) list->tail = NULL;
    } else {
        if (elem->next == NULL) return false;

        *data = elem->next->data;
        old_elem = elem->next;
        elem->next = elem->next->next;

        if (elem->next == NULL) {
            list->tail = elem;
        }
    }
    free(old_elem);
    list->size--;
    return true;
}
