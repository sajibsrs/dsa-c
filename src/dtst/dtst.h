#ifndef DTST_H
#define DTST_H

#include <stdbool.h>

/**************************************************
 * - Linked Lists
 * -- Singly linked list / Linked list
 * -- Doubly linked list
 **************************************************/

// Defines structure for linked list element.
typedef struct ListElem_ {
    void             *data;
    struct ListElem_ *next;
} ListElem;

// Defines structure for linked list.
typedef struct List_ {
    int       size;
    int       (*match)(const void *key1, const void *key2);
    void      (*destroy)(void *data);
    ListElem *head;
    ListElem *tail;
} List;

/**
 * @brief Initializes a linked list. Provide a callback function to handle what happens
 * to the dynamically allocated `data`.
 * @param list Linked list.
 * @param destroy Linked list destroy callback function.
 */
void list_init(List *list, void (*destroy)(void *data));

/**
 * @brief Resets a Linked list. It doesn't "fee" the memory held by the list itself.
 * Freeing memory is the callers responsibility.
 * @param list Linked list.
 */
void list_destroy(List *list);

/**
 * @brief Inserts an element just after `elem`. If `elem` is `NULL`, the new element is inserted at
 * the head of the list.
 * @param list Linked list pointer.
 * @param elem Element, after which the new element would be inserted.
 * @param data Element data pointer. It is callers responsibility to manage storage for `data`.
 * @return boolean true on success and false on failure.
 */
bool list_ins_next(List *list, ListElem *elem, const void *data);

/**
 * @brief Removes an element just after `elem`. If `elem` is `NULL`, the element at the head of the
 * list gets removed.
 * @param list Linked list pointer.
 * @param elem Element, after which the element would be removed.
 * @param data Element data pointer. It is callers responsibility to manage storage for `data`.
 * @return boolean true on success and false on failure.
 */
bool list_rem_next(List *list, ListElem *elem, void **data);

/**
 * @brief Macro: Returns the size of the list.
 * @param list Linked list pointer.
 */
#define list_size(list) ((list)->size)

/**
 * @brief Macro: Returns the head of the list.
 * @param list Linked list pointer.
 */
#define list_head(list) ((list)->head)

/**
 * @brief Macro: Returns the tail of the list.
 * @param list Linked list pointer.
 */
#define list_tail(list) ((list)->tail)

/**
 * @brief Macro: Determines if the `elem` is head of the list.
 * @param list List pointer.
 * @param elem Element pointer.
 */
#define list_is_head(list, elem) ((elem) == (list)->head ? true : false)

/**
 * @brief Macro: Determines if the `elem` is tail of the list.
 * @param list List pointer.
 * @param elem Element pointer.
 */
#define list_is_tail(list, elem) ((elem) == (list)->tail ? true : false)

/**
 * @brief Macro: Returns the data stored in the list element.
 * @param elem List element pointer.
 */
#define list_data(elem) ((elem)->data)

/**
 * @brief Macro: Returns the next element in the list.
 * @param elem List element pointer.
 */
#define list_next(elem) ((elem)->next)

/**************************************************
 * - Chained Hash Table
 **************************************************/

#endif
