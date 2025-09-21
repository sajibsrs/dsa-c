#ifndef DTST_H
#define DTST_H

#include <stdbool.h>
#include <stdlib.h>

/**************************************************
 * - Linked Lists
 * -- Singly linked list / Linked list
 * -- Doubly linked list
 * -- Circular list
 **************************************************/

/*-------------------------------------------------
 * Singly linked list / Linked list
 *-------------------------------------------------*/

typedef struct slist_node {
    void              *data;
    struct slist_node *next;
} slist_node_t;

typedef struct slist {
    slist_node_t *head;
    slist_node_t *tail;
    size_t        size;
    void          (*destroy)(void *data);
} slist_t;

void slist_init(slist_t *list, void (*destroy)(void *data));
bool slist_ins_head(slist_t *list, void *data);
bool slist_rem_tail(slist_t *list, void **data);
void slist_rem_all(slist_t *list);

/*-------------------------------------------------
 * Doubly linked list
 *-------------------------------------------------*/

typedef struct dlist_node {
    void              *data;
    struct dlist_node *prev;
    struct dlist_node *next;
} dlist_node_t;

typedef struct dlist {
    dlist_node_t *head;
    dlist_node_t *tail;
    size_t        size;
    void          (*destroy)(void *data);
} dlist_t;

void dlist_init(dlist_t *list, void (*destroy)(void *data));
bool dlist_ins_head(dlist_t *list, void *data);
bool dlist_rem_tail(dlist_t *list, void **data);
void dlist_rem_all(dlist_t *list);

#endif
