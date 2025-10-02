#ifndef DTST_H
#define DTST_H

/**************************************************
 * - Singly linked list / Linked list
 **************************************************/

typedef struct slnode {
    void *data;
    struct slnode *next;
} slnode_t;

typedef struct {
    slnode_t *head;
    slnode_t *tail;
    size_t size;
    void (*destroy)(void *data);
} slist_t;

void slist_init(slist_t *list, void (*destroy)(void *data));
int slist_head_ins(slist_t *list, void *data);
int slist_tail_rem(slist_t *list, void **data);
void slist_rem(slist_t *list);

/**************************************************
 * - Doubly linked list
 **************************************************/

typedef struct dlnode {
    void *data;
    struct dlnode *prev;
    struct dlnode *next;
} dlnode_t;

typedef struct dlist {
    dlnode_t *head;
    dlnode_t *tail;
    size_t size;
    void (*destroy)(void *data);
} dlist_t;

void dlist_init(dlist_t *list, void (*destroy)(void *data));
int dlist_head_ins(dlist_t *list, void *data);
int dlist_tail_rem(dlist_t *list, void **data);
void dlist_rem(dlist_t *list);

/**************************************************
 * - Stack
 **************************************************/

typedef struct {
    int *stack;
    int top;
    int size;
} stck_t;

stck_t *stack_new(int size);
void stack_push(stck_t *s, int elm);
int stack_pop(stck_t *s);
int stack_peek(stck_t *s);
int stack_is_empty(stck_t *s);

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

void queue_enqueue(que_t *q, int elm);
int queue_dequeue(que_t *q);
int queue_peek(que_t *q);
int queue_is_empty(que_t *q);
int queue_size(que_t *q);
void queue_print(que_t *q);

/**************************************************
 * - Trie
 **************************************************/

#define TRIE_SIZE 26

typedef struct trie {
    int is_end;
    struct trie *child[TRIE_SIZE];
} trie_t;

trie_t *trie_node_new(void);
void trie_ins(trie_t *root, const char *word);
int trie_find(trie_t *root, const char *word);
void trie_free(trie_t *root);

/**************************************************
 * - Graph
 **************************************************/

/** - Array Implementation ======================**/

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

void agr_dfs(const agr_t *g, char start_vdata);
void agr_bfs(const agr_t *g, char start_vdata);
int agr_has_cycle(const agr_t *g);

/** - Sparse Graph Implementation ================**/

// Adjacency list node type
typedef struct alnode {
    int vertex;
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
void sgr_vdata_set(sgr_t *g, int vertex, char data);
void sgr_print(const sgr_t *g);
void sgr_free(sgr_t *g);

#endif
