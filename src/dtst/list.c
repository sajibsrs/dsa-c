#include "dtst.h"

/**************************************************
 * Singly linked list
 **************************************************/

void slist_init(slist_t *list, void (*destroy)(void *data)) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->destroy = destroy;
}

bool slist_ins_head(slist_t *list, void *data) {
    slist_node_t *new_node = malloc(sizeof(slist_node_t));
    if (!new_node) return false;

    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node;
    }

    list->size++;
    return true;
}

bool slist_rem_tail(slist_t *list, void **data) {
    if (list->head == NULL) {
        return false;
    }

    if (data) {
        *data = list->tail->data;
    }

    // Single node case
    if (list->head == list->tail) {
        free(list->tail);
        list->head = NULL;
        list->tail = NULL;
    } else {
        // Find node before tail
        slist_node_t *curr = list->head;
        while (curr->next != list->tail) {
            curr = curr->next;
        }

        free(list->tail);
        curr->next = NULL;
        list->tail = curr;
    }

    list->size--;
    return true;
}

void slist_rem_all(slist_t *list) {
    slist_node_t *curr = list->head;

    while (curr != NULL) {
        slist_node_t *next = curr->next;

        if (list->destroy) {
            list->destroy(curr->data);
        }

        free(curr);
        curr = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/**************************************************
 * Doubly linked list
 **************************************************/

void dlist_init(dlist_t *list, void (*destroy)(void *data)) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->destroy = destroy;
}

bool dlist_ins_head(dlist_t *list, void *data) {
    dlist_node_t *new_node = malloc(sizeof(dlist_node_t));
    if (!new_node) return false;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = list->head;

    if (list->head != NULL) {
        list->head->prev = new_node;
    }

    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node;
    }

    list->size++;
    return true;
}

bool dlist_rem_tail(dlist_t *list, void **data) {
    if (list->tail == NULL) {
        return false;
    }

    dlist_node_t *old_tail = list->tail;

    if (data) {
        *data = old_tail->data;
    }

    if (list->head == list->tail) {
        // Only one node in the list
        list->head = NULL;
        list->tail = NULL;
    } else {
        // Multiple nodes, update tail and next pointers
        list->tail = old_tail->prev;
        list->tail->next = NULL;
    }

    free(old_tail);
    list->size--;
    return true;
}

void dlist_rem_all(dlist_t *list) {
    dlist_node_t *curr = list->head;

    while (curr != NULL) {
        dlist_node_t *next = curr->next;

        if (list->destroy) {
            list->destroy(curr->data);
        }

        free(curr);
        curr = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
