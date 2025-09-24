#include "dtst.h"

/**************************************************
 * Singly linked list
 **************************************************/

void slist_init(slist_t *list, void (*destroy)(void *data)) {
    list->head = list->tail = NULL;
    list->size = 0;
    list->destroy = destroy;
}

bool slist_head_ins(slist_t *list, void *data) {
    slist_node_t *new = malloc(sizeof(slist_node_t));
    if (!new) return false;

    new->data = data;
    new->next = list->head;
    list->head = new;

    if (!list->tail) list->tail = new;
    list->size++;
    return true;
}

bool slist_tail_rem(slist_t *list, void **data) {
    if (!list->head) return false;

    if (data) *data = list->tail->data;

    if (list->head == list->tail) {
        free(list->tail);
        list->head = list->tail = NULL;
    } else {
        slist_node_t *curr = list->head;
        while (curr->next != list->tail) curr = curr->next;

        free(list->tail);
        curr->next = NULL;
        list->tail = curr;
    }
    list->size--;
    return true;
}

void slist_rem(slist_t *list) {
    slist_node_t *curr = list->head;

    while (curr) {
        slist_node_t *next = curr->next;
        if (list->destroy) list->destroy(curr->data);
        free(curr);
        curr = next;
    }
    list->head = list->tail = NULL;
    list->size = 0;
}

/**************************************************
 * Doubly linked list
 **************************************************/

void dlist_init(dlist_t *list, void (*destroy)(void *data)) {
    list->head = list->tail = NULL;
    list->size = 0;
    list->destroy = destroy;
}

bool dlist_head_ins(dlist_t *list, void *data) {
    dlist_node_t *new = malloc(sizeof(dlist_node_t));
    if (!new) return false;

    new->data = data;
    new->prev = NULL;
    new->next = list->head;

    if (list->head) list->head->prev = new;
    list->head = new;

    if (!list->tail) list->tail = new;
    list->size++;
    return true;
}

bool dlist_tail_rem(dlist_t *list, void **data) {
    if (!list->tail) return false;

    dlist_node_t *old = list->tail;
    if (data) *data = old->data;

    if (list->head == list->tail) {
        list->head = list->tail = NULL;
    } else {
        list->tail = old->prev;
        list->tail->next = NULL;
    }
    free(old);
    list->size--;
    return true;
}

void dlist_rem(dlist_t *list) {
    dlist_node_t *curr = list->head;

    while (curr) {
        dlist_node_t *next = curr->next;
        if (list->destroy) list->destroy(curr->data);
        free(curr);
        curr = next;
    }
    list->head = list->tail = NULL;
    list->size = 0;
}
