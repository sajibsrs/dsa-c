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
bool slist_head_ins(slist_t *list, void *data);
bool slist_tail_rem(slist_t *list, void **data);
void slist_rem(slist_t *list);

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
bool dlist_head_ins(dlist_t *list, void *data);
bool dlist_tail_rem(dlist_t *list, void **data);
void dlist_rem(dlist_t *list);

/*-------------------------------------------------
 * Trie
 *-------------------------------------------------*/

#define TRIE_SIZE 26

typedef struct trie {
    bool         is_end;
    struct trie *child[TRIE_SIZE];
} trie_t;

trie_t *trie_node_new(void);
void    trie_ins(trie_t *root, const char *word);
bool    trie_find(trie_t *root, const char *word);
void    trie_free(trie_t *root);

#endif
