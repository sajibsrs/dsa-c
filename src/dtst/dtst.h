#ifndef DTST_H
#define DTST_H

#include <stddef.h>

/**************************************************
 * - Linked-lists
 * -- Singly linked-list
 * -- Doubly linked-list
 **************************************************/

// Linked-list node
typedef struct listn {
    int data;
    struct listn *next;
} listn_t;

// Linked-list
typedef struct {
    int size;
    listn_t *head;
} list_t;

/**
 * @brief Creates new linked-list.
 * @return Linked-list pointer.
 */
list_t *list_new();

/**
 * @brief Creates new `node` from data and inserts into the linked-list.
 * @param list Linked-list pointer.
 * @param data Node data.
 */
void list_ins(list_t *list, int data);

/**
 * @brief Removes a `node` based on data.
 * @param list Linked-list pointer.
 * @param data Node data.
 */
void list_rem(list_t *list, int data);

/**
 * @brief Deallocates a `list` and it's `nodes`
 * @param list Linked-list pointer.
 */
void list_free(list_t *list);

/**************************************************
 * - Doubly linked-list
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
 * -- Array implementation
 * -- Linked-list implementation
 **************************************************/

// Stack implementation with array.
typedef struct {
    int size;
    int top;
    int *array;
} astk_t;

/**
 * @brief Create a new array-based stack.
 * @param size  Initial capacity of the stack.
 * @return Pointer to the newly allocated stack.
 */
astk_t *astk_new(int size);

/**
 * @brief Push an integer onto the stack.
 * @param stack Pointer to the stack.
 * @param data  Integer value to push.
 */
void astk_push(astk_t *stack, int data);

/**
 * @brief Pop the top integer from the stack.
 * @param stack Pointer to the stack.
 * @return The popped value, or -1 if the stack was empty.
 */
int astk_pop(astk_t *stack);

/**
 * @brief Return the value at the top of the stack without removing it.
 * @param stack Pointer to the stack.
 * @return The value at the top of the stack.
 */
int astk_peek(astk_t *stack);

/**
 * @brief Free all memory associated with the stack.
 * @param stack Pointer to the stack to be deallocated.
 */
void astk_free(astk_t *stack);

/**************************************************
 * - Stack using linked-list
 **************************************************/

// TODO:

/**************************************************
 * - Queue
 * -- Queue implemented with array
 **************************************************/

/** Queue implementation with array.
 *
 * As array based linear queue is wasteful, this implementation
 * uses array based circular queue.
 **/
typedef struct {
    int capacity;
    int front;
    int back;
    int size;
    int *array;
} aque_t;

/**
 * @brief Creates new queue.
 * @param capacity Total capacity of the queue.
 * @return Pointer to the queue;
 */
aque_t *aque_new(int capacity);

/**
 * @brief Enqueues new data into the queue front.
 * @param queue Pointer to the queue.
 * @param data Data that being queued.
 * @return 1 on success 0 on failure.
 */
int aque_enq(aque_t *queue, int data);

/**
 * @brief Dequeues data from the queue back.
 * @param queue Pointer to the queue.
 * @return
 */
int aque_deq(aque_t *queue);

/**
 * @brief Peeks/Reads the front of the queue.
 * @param queue Pointer to the queue.
 * @return Data stored at the queue front.
 */
int aque_peek(aque_t *queue);

/**
 * @brief Deallocates all memory allocated to queue.
 * @param queue Pointer to the queue.
 */
void aque_free(aque_t *queue);

/**************************************************
 * - Trees
 * -- Binary search tree
 **************************************************/

typedef struct bintrn {
    int data;
    struct bintrn *parent;
    struct bintrn *left;
    struct bintrn *right;
} bintrn_t;

/**
 * @brief Creates new binary tree node.
 * @param parent Parent node, or `NULL` if it's root node.
 * @param value Integer value of the node.
 * @return Pointer to the node.
 */
bintrn_t *bintrn_new(bintrn_t *parent, int value);

/**
 * @brief Creates new node with value and inserts into the tree.
 * @param node Root/node under which the value should be inserted.
 * @param value Value to be inserted.
 * @return Pointer to the newly inserted node.
 */
bintrn_t *bintr_ins(bintrn_t *node, int value);

/**
 * @brief Remove node from tree by value.
 * @param node Root/node to start from.
 * @param value Value to be removed.
 * @return Pointer to the subtree node where change occured.
 */
bintrn_t *bintr_rem(bintrn_t *node, int value);

/**
 * @brief Searches for a value in the tree.
 * @param node Root/node to start from.
 * @param value Value to look for.
 * @return Pointer to the node.
 */
bintrn_t *bintr_srch(bintrn_t *node, int value);

/**
 * @brief Frees the allocated space for the whole tree.
 * @param node Root node.
 */
void bintr_free(bintrn_t *node);

/**************************************************
 * - Trie
 **************************************************/

#define TRIE_SIZE 26

// Trie node for 26 characters (a-z).
typedef struct trien {
    struct trien *cnodes[TRIE_SIZE];
    int is_end;
} trien_t;

/**
 * @brief Creates new trie node.
 * @return Pointer to that node.
 */
trien_t *trien_new(void);

/**
 * @brief Inserts new word into the trie.
 * @param root Trie root node.
 * @param word Character string.
 */
void trie_ins(trien_t *root, const char *word);

/**
 * @brief Searches for word in trie.
 * @param root Trie root node.
 * @param word Character string.
 * @return
 */
int trie_srch(trien_t *root, const char *word);

/**
 * @brief Removes a word from trie.
 * @param root Trie root node.
 * @param word Character string.
 */
void trie_rem(trien_t *root, const char *word);

/**
 * @brief Deallocates the memory for the trie.
 * @param root Trie root node.
 */
void trie_free(trien_t *root);

/**************************************************
 * - Heap
 * -- Max heap
 **************************************************/

typedef struct {
    int *array;
    int size; // Array size
    int last; // Array last index
} heap_t;

/**
 * @brief Creates new integer heap (1-based).
 * @param size Size of the heap array.
 * @return Pointer to the heap.
 */
heap_t *heap_new(const int size);

/**
 * @brief Inserts integer into heap.
 * @param heap Heap pointer (1-based).
 * @param value Integer value.
 * @return 0 on success -1 on failure.
 */
int heapmax_ins(heap_t *heap, int value);

/**
 * @brief Removes topmost number (root - which is first element of the array).
 * @param heap Heap pointer (1-based).
 * @return Removed number on success, -1 on failure.
 */
int heapmax_rem(heap_t *heap);

/**
 * @brief Takes an array and returns max heap (1-based).
 * @param arr Array that needs to be heapified.
 * @param size Length of the array
 * @return Pointer to the heap.
 */
heap_t *heapmax_heapify(int *arr, int size);

/**
 * @brief Sorts an array in ascending order.
 * Creates heap from array first, then sorts. Time complexity `O(n log n)`.
 * @param arr Unsorted array.
 * @param size Length of the array.
 */
void heapmax_asort(int *arr, int size);

/**
 * @brief Sorts an array in descending order.
 * Creates heap from array first, then sorts. Time complexity `O(n log n)`.
 * @param arr Unsorted array.
 * @param size Length of the array.
 */
void heapmax_dsort(int *arr, int size);

/**
 * @brief Cleansup resources.
 * @param heap
 */
void heap_free(heap_t *heap);

/**************************************************
 * - Graph
 **************************************************/

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
