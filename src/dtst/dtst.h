#ifndef _DTST_H
#define _DTST_H

/**************************************************
 * - Linked List
 **************************************************/

// Define linked-list element
typedef struct ListElem_ {
    void             *data;
    struct ListElem_ *next;
} ListElem;

// Define linked-list
typedef struct List_ {
    int size;

    int  (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    ListElem *head;
    ListElem *tail;
} List;

/**
 * @brief Initialize a linked-list.
 * @param list Linked-list.
 * @param destroy Supplied linked-list destroy callback function.
 */
void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int  list_ins_next(List *list, ListElem *elem, const void *data);
int  list_rem_next(List *list, ListElem *elem, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, elem) ((elem) == (list)->head ? 1 : 0)
#define list_is_tail(list, elem) ((elem) == (list)->tail ? 1 : 0)
#define list_data(elem) ((elem)->data)
#define list_next(elem) ((elem)->next)

#endif
