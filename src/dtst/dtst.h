#ifndef DTST_H
#define DTST_H

/**************************************************
 * - Singly linked list / Linked list
 **************************************************/

typedef struct slist_node {
    void              *data;
    struct slist_node *next;
} slist_node_t;

typedef struct {
    slist_node_t *head;
    slist_node_t *tail;
    size_t        size;
    void          (*destroy)(void *data);
} slist_t;

void slist_init(slist_t *list, void (*destroy)(void *data));
int  slist_head_ins(slist_t *list, void *data);
int  slist_tail_rem(slist_t *list, void **data);
void slist_rem(slist_t *list);

/**************************************************
 * - Doubly linked list
 **************************************************/

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
int  dlist_head_ins(dlist_t *list, void *data);
int  dlist_tail_rem(dlist_t *list, void **data);
void dlist_rem(dlist_t *list);

/**************************************************
 * - Stack
 **************************************************/

typedef struct {
    int *stack;
    int  top;
    int  size;
} istack_t;

istack_t *stack_new(int size);
void      stack_push(istack_t *s, int elm);
int       stack_pop(istack_t *s);
int       stack_peek(istack_t *s);
int       stack_is_empty(istack_t *s);

/**************************************************
 * - Queue
 **************************************************/

#define QUEUE_SIZE 10

typedef struct {
    int queue[QUEUE_SIZE];
    int front;
    int size;
} iqueue_t;

void queue_enqueue(iqueue_t *q, int elm);
int  queue_dequeue(iqueue_t *q);
int  queue_peek(iqueue_t *q);
int  queue_is_empty(iqueue_t *q);
int  queue_size(iqueue_t *q);
void queue_print(iqueue_t *q);

/**************************************************
 * - Trie
 **************************************************/

#define TRIE_SIZE 26

typedef struct trie {
    int          is_end;
    struct trie *child[TRIE_SIZE];
} trie_t;

trie_t *trie_node_new(void);
void    trie_ins(trie_t *root, const char *word);
int     trie_find(trie_t *root, const char *word);
void    trie_free(trie_t *root);

/**************************************************
 * - Graph
 **************************************************/

#define GRAPH_SIZE 10

typedef struct graph {
    int  adj_matrix[GRAPH_SIZE][GRAPH_SIZE];
    char vertex_data[GRAPH_SIZE];
} graph_t;

void graph_init(graph_t *g);
void graph_add_edge(graph_t *g, int u, int v, int weight);
void graph_set_vertex_data(graph_t *g, int vertex, char data);
void graph_print(const graph_t *g);

void graph_dfs(const graph_t *g, char start_vertex);
void graph_bfs(const graph_t *g, char start_vertex);

#endif
