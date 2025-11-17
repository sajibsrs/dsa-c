#ifndef DTST_H
#define DTST_H

#include <stddef.h>

/**************************************************
 * - Linked list / Singly linked list
 *
 * It's a simple implementation of linked list.
 * Only the head is used for insertion and deletion.
 **************************************************/

// Linked list node
typedef struct listn {
    int data;
    struct listn *next;
} listn_t;

// Linked list
typedef struct {
    int size;
    listn_t *head;
} list_t;

/**
 * @brief Creates new linked list.
 * @return Linked list pointer.
 */
list_t *list_new();

/**
 * @brief Creates new `node` from data and inserts
 * into the linked list.
 * @param list Linked list pointer.
 * @param data Node data.
 */
void list_ins(list_t *list, int data);

/**
 * @brief Removes a `node` based on value.
 * @param list Linked list pointer.
 * @param data Node data.
 */
void list_rem(list_t *list, int data);

/**
 * @brief Deallocates a `list` and it's `nodes`
 * @param list Linked list pointer.
 */
void list_free(list_t *list);

/**************************************************
 * - Doubly linked list
 **************************************************/

typedef struct dlistn {
    void *data;
    struct dlistn *prev;
    struct dlistn *next;
} dlistn_t;

typedef struct {
    int size;
    dlistn_t *head;
    dlistn_t *tail;
} dlist_t;

/**************************************************
 * - Stack
 **************************************************/

typedef struct {
    int *arr;
    int top;
    int size;
} stck_t;

stck_t *stk_new(int size);
int stk_push(stck_t *s, int elm);
int stk_pop(stck_t *s);
int stk_peek(stck_t *s);
int stk_isempty(stck_t *s);

/**************************************************
 * - Queue
 **************************************************/

#define QUEUE_SIZE 10

// Queue type
typedef struct {
    int queue[QUEUE_SIZE];
    int front;
    int size;
} que_t;

void que_enqueue(que_t *q, int elm);
int que_dequeue(que_t *q);
int que_peek(que_t *q);
int que_isempty(que_t *q);
int que_size(que_t *q);
void que_print(que_t *q);

/**************************************************
 * - Trie
 **************************************************/

#define TRIE_SIZE 26

typedef struct trie {
    int isend;
    struct trie *child[TRIE_SIZE];
} trie_t;

trie_t *trie_node_new(void);
void trie_ins(trie_t *root, const char *word);
int trie_find(trie_t *root, const char *word);
void trie_free(trie_t *root);

/**************************************************
 * - Graph
 **************************************************/

/* - Array Implementation
 * ---------------------------------------------- */

// Array based graph type
typedef struct {
    char *vdata;
    int **adjmat;
    int size;
} agr_t;

agr_t *agr_new(int size);
void agr_edge_new(agr_t *g, int u, int v, int weight);
void agr_vdata_set(agr_t *g, int vertex, char data);
void agr_print(const agr_t *g);
void agr_free(agr_t *g);

int agr_has_cycle(const agr_t *g);

/* - Sparse Graph Implementation
 * ---------------------------------------------- */

// Adjacency list node type
typedef struct alnode {
    int vindex;
    int weight;
    struct alnode *next;
} alnode_t;

// Sparse graph type
typedef struct {
    char *vdata;
    alnode_t **alist;
    int size;
} sgr_t;

sgr_t *sgr_new(int size);
void sgr_edge_new(sgr_t *g, int u, int v, int weight);
void sgr_vdata_set(sgr_t *g, int vindex, char data);
void sgr_print(const sgr_t *g);
void sgr_free(sgr_t *g);

int sgr_has_cycle(const sgr_t *g);

#endif
