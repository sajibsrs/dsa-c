#ifndef _DTST_H
#define _DTST_H

/**************************************************
 * - Linked List
 **************************************************/

// Defines linked list element
typedef struct ListElem_ {
    void             *data;
    struct ListElem_ *next;
} ListElem;

typedef int  (*MatchFP)(const void *key1, const void *key2);
typedef void (*DestroyFP)(void *data);

// Defines linked list
typedef struct List_ {
    int size;

    MatchFP   match;
    DestroyFP destroy;

    ListElem *head;
    ListElem *tail;
} List;

/**
 * @brief Initializes a linked list.
 * @param list Linked list.
 * @param destroy Linked list destroy callback function.
 */
void list_init(List *list, DestroyFP destroy);

/**
 * @brief Deallocates a Linked list.
 * @param list Linked list.
 */
void list_destroy(List *list);

/**
 * @brief Inserts an element just after `elem`. If `elem` is `NULL`, the new element is inserted at
 * the head of the list.
 * @param list Linked list pointer.
 * @param elem Element, after which the new element would be inserted.
 * @param data Element data pointer. It is callers responsibility to manage storage for `data`.
 * @return `0` on Success, `-1` on failure.
 */
int list_ins_next(List *list, ListElem *elem, const void *data);

/**
 * @brief Removes an element just after `elem`. If `elem` is `NULL`, the element at the head of the
 * list gets removed.
 * @param list Linked list pointer.
 * @param elem Element, after which the element would be removed.
 * @param data Element data pointer. It is callers responsibility to manage storage for `data`.
 * @return `0` on Success, `-1` on failure.
 */
int list_rem_next(List *list, ListElem *elem, void **data);

/**
 * @brief Returns the size of the list.
 * @param list Linked list pointer.
 */
#define list_size(list) ((list)->size)

/**
 * @brief Returns the head of the list.
 * @param list Linked list pointer.
 */
#define list_head(list) ((list)->head)

/**
 * @brief Returns the tail of the list.
 * @param list Linked list pointer.
 */
#define list_tail(list) ((list)->tail)
#define list_is_head(list, elem) ((elem) == (list)->head ? 1 : 0)
#define list_is_tail(list, elem) ((elem) == (list)->tail ? 1 : 0)
#define list_data(elem) ((elem)->data)
#define list_next(elem) ((elem)->next)

/**************************************************
 * - Chained Hash Table
 **************************************************/

typedef int (*HashFP)(const void *key);

// Defines chained hash table.
typedef struct CHTbl_ {
    int buckets;

    HashFP    h;
    MatchFP   match;
    DestroyFP destroy;

    int   size;
    List *table;
} CHTbl;

/**
 * @brief Initializes the chained hash table specified by `htbl`.
 * @param htbl The chained hash table pointer, that being initialized.
 * @param buckets Number of buckets.
 * @param h Hash function.
 * @param match Function to match two keys.
 * @param destroy Function to free dynamically allocated memory.
 * @return `0` if initializing the hash table is successful, or `–1` otherwise.
 */
int  chtbl_init(CHTbl *htbl, int buckets, HashFP h, MatchFP match, DestroyFP destroy);

/**
 * @brief Destroys the chained hash table specified by `htbl`.
 * @param htbl The chained hash table, that being destroyed.
 */
void chtbl_destroy(CHTbl *htbl);
int  chtbl_insert(CHTbl *htbl, const void *data);
int  chtbl_remove(CHTbl *htbl, void **data);
int  chtbl_lookup(const CHTbl *htbl, void **data);

#define chtbl_size(htbl) ((htbl)->size)

#endif
