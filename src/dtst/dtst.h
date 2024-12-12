#ifndef _DTST_H
#define _DTST_H

/**************************************************
 * - Linked List
 **************************************************/

// Define linked list element
typedef struct ListElem_ {
    void             *data;
    struct ListElem_ *next;
} ListElem;

typedef int  (*MatchFP)(const void *key1, const void *key2);
typedef void (*DestroyFP)(void *data);

// Define linked list
typedef struct List_ {
    int size;

    MatchFP   match;
    DestroyFP destroy;

    ListElem *head;
    ListElem *tail;
} List;

/**
 * @brief Initialize a linked list.
 * @param list Linked list.
 * @param destroy Linked list destroy callback function.
 */
void list_init(List *list, DestroyFP destroy);

/**
 * @brief Deallocate a Linked list.
 * @param list Linked list.
 */
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

/**************************************************
 * - Chained Hash Table
 **************************************************/

typedef int (*HashFP)(const void *key);

typedef struct CHTbl_ {
    int buckets;

    HashFP    h;
    MatchFP   match;
    DestroyFP destroy;

    int   size;
    List *table;
} CHTbl;

int  chtbl_init(CHTbl *htbl, int buckets, HashFP h, MatchFP match, DestroyFP destroy);
void chtbl_destroy(CHTbl *htbl);
int  chtbl_insert(CHTbl *htbl, const void *data);
int  chtbl_remove(CHTbl *htbl, void **data);

#define chtbl_size(htbl) ((htbl)->size)

#endif
