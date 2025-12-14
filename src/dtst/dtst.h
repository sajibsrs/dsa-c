#ifndef DTST_H
#define DTST_H

#include <stddef.h>

/******************************************************************************
 * - Linked-lists
 * -- Singly linked-list
 * -- Doubly linked-list
 ******************************************************************************/

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

/******************************************************************************
 * - Doubly linked-list
 ******************************************************************************/

typedef struct dlistn {
    void *data;
    struct dlistn *prev, *next;
} dlistn_t;

typedef struct {
    int size;
    dlistn_t *head, *tail;
} dlist_t;

/******************************************************************************
 * - Stack
 * -- Array implementation
 * -- Linked-list implementation
 ******************************************************************************/

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

/*----------------------------------------------------------------------------*
 * - Stack using linked-list
 *----------------------------------------------------------------------------*/

// TODO:

/******************************************************************************
 * - Queue
 * -- Queue implemented with array
 ******************************************************************************/

/** Queue implementation with array.
 *
 * As array based linear queue is wasteful, this implementation
 * uses array based circular queue.
 **/
typedef struct {
    int capacity, front, back, size, *array;
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

/******************************************************************************
 * - Trees
 * -- Binary search tree
 ******************************************************************************/

typedef struct bstn {
    int data;
    struct bstn *parent, *left, *right;
} btsn_t;

/**
 * @brief Creates new binary tree node.
 * @param parent Parent node, or `NULL` if it's root node.
 * @param value Integer value of the node.
 * @return Pointer to the node.
 */
btsn_t *btsn_new(btsn_t *parent, int value);

/**
 * @brief Creates new node with value and inserts into the tree.
 * @param node Root/node under which the value should be inserted.
 * @param value Value to be inserted.
 * @return Pointer to the newly inserted node.
 */
btsn_t *bts_ins(btsn_t *node, int value);

/**
 * @brief Remove node from tree by value.
 * @param node Root/node to start from.
 * @param value Value to be removed.
 * @return Pointer to the subtree node where change occured.
 */
btsn_t *bts_rem(btsn_t *node, int value);

/**
 * @brief Searches for a value in the tree.
 * @param node Root/node to start from.
 * @param value Value to look for.
 * @return Pointer to the node.
 */
btsn_t *bts_srch(btsn_t *node, int value);

/**
 * @brief Frees the allocated space for the whole tree.
 * @param node Root node.
 */
void bts_free(btsn_t *node);

/******************************************************************************
 * - Trie
 ******************************************************************************/

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

/******************************************************************************
 * - Heap
 * -- Ma-heap
 * -- Min-heap (TODO)
 * -- Priority queue
 ******************************************************************************/

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
 *
 * Creates heap from array first, then sorts. Time complexity `O(n log n)`.
 * Better alternative exists with `O(n)` with direct implementation.
 *
 * @param arr Unsorted array.
 * @param size Length of the array.
 */
void heapmax_asort(int *arr, int size);

/**
 * @brief Sorts an array in descending order.
 *
 * Creates heap from array first, then sorts. Time complexity `O(n log n)`.
 * Better alternative exists with `O(n)` with direct implementation.
 *
 * @param arr Unsorted array.
 * @param size Length of the array.
 */
void heapmax_dsort(int *arr, int size);

/**
 * @brief Cleansup resources.
 * @param heap
 */
void heap_free(heap_t *heap);

/*-----------------------------------------------------------------------------*
 * - Priority queue
 *-----------------------------------------------------------------------------*/

// Priority queue node type
typedef struct {
    int prio; // Data priority
    void *data;
} pquen_t;

// Priority queue type
typedef struct {
    pquen_t *heap;
    int size;
    int cap; // Queue capacity
} pque_t;

/**
 * @brief Creates new priority queue.
 * @param cap Capacity of the queue.
 * @return Pointer to the queue.
 */
pque_t *pque_new(int cap);

/**
 * @brief Adds new element to the end of the priority queue.
 * @param pq Pointer to the priority queue.
 * @param data Data to be stored in priority queue.
 * @param prio Priority of the data.
 * @return 0 on success, -2 when queue is full.
 */
int pque_push(pque_t *pq, void *data, int prio);

/**
 * @brief Removes an element from the front of the queue.
 * @param pq Pointer to the priority queue.
 * @return
 */
void *pque_pop(pque_t *pq);

/******************************************************************************
 * - Grid
 ******************************************************************************/

typedef struct {
    float x, y;
} point_t;

typedef struct {
    int rows;
    int cols;
    point_t origin; // top-left corner of the grid
    float cwidth;   // cell width
    float cheight;  // cell height
    char *data;     // contiguous memory [rows * cols]
} grid_t;

/**
 * @brief Create a new uniform 2D grid.
 * @param rows    Number of rows in the grid.
 * @param cols    Number of columns in the grid.
 * @param origin  The top-left corner position of the grid in world coordinates.
 * @param cwidth  Width of each cell.
 * @param cheight Height of each cell.
 * @return        Pointer to the grid.
 */
grid_t *grid_new(int rows, int cols, point_t origin, float cwidth, float cheight);

/**
 * @brief Check if a given row and column are within the grid bounds.
 * @param grid Pointer to the grid.
 * @param row  Row index to check.
 * @param col  Column index to check.
 * @return     Non-zero if valid, zero if out of bounds or grid is NULL.
 */
int grid_isvalid(const grid_t *grid, int row, int col);

/**
 * @brief Set a value at a specific cell in the grid.
 * @param grid Pointer to the grid.
 * @param row  Row index of the cell.
 * @param col  Column index of the cell.
 * @param val  Value to set.
 * @return     Non-zero on success, zero if invalid coordinates.
 */
int grid_set(grid_t *grid, int row, int col, char val);

/**
 * @brief Get the value at a specific cell in the grid.
 * @param grid Pointer to the grid.
 * @param row  Row index of the cell.
 * @param col  Column index of the cell.
 * @return     The value at the cell, or 0 if the coordinates are invalid.
 */
char grid_get(const grid_t *grid, int row, int col);

/**
 * @brief Find the first occurrence of a value in the grid.
 * @param grid Pointer to the grid.
 * @param targ Target value to search for.
 * @return     Linear index (row * cols + col) of the first matching cell,
 *             or -1 if the value is not found.
 */
int grid_find(const grid_t *grid, char targ);

/**
 * @brief Find the nearest cell center to a given point.
 * @param grid Pointer to the grid.
 * @param pt   Target point in world coordinates.
 * @return     Linear index of the nearest cell, or -1 if grid is NULL.
 *
 * Note: This performs a linear search over all cells (O(rows * cols)).
 */
int grid_nearest(const grid_t *grid, point_t pt);

/**
 * @brief Find the nearest cell center to a given point using expanding ring search.
 * @param grid   Pointer to the grid.
 * @param pt     Target point in world coordinates.
 * @param radius Maximum radius (in cells) to search from the initial cell.
 * @return       Linear index of the nearest cell, or -1 if the point is outside the grid
 *               or no cell is found within the given radius.
 *
 * Note: This function starts from the cell containing the point and expands outward in
 *       concentric rings, checking only cells on the current ring.
 *
 * Time Complexity: O(min(rows*cols, R^2)), where R is the input radius.
 *                 In practice, for small radius R, the search is very fast.
 */
int grid_nearexp(const grid_t *grid, point_t pt, int radius);

/**
 * @brief Free all memory associated with a grid.
 * @param grid Pointer to the grid to free. Safe to pass NULL.
 */
void grid_free(grid_t *grid);

/**
 * @brief Print the grid to stdout for debugging. Empty cells are displayed as '.'.
 * @param grid Pointer to the grid.
 */
void grid_print(const grid_t *grid);

/******************************************************************************
 * - Graph
 * -- Array based graph
 * -- Linked-list based graph
 ******************************************************************************/

// Adjacency matrix based graph type
typedef struct {
    char *data;  // vtx data
    int **nodes; // adjacency matrix
    int size;
} amgr_t;

amgr_t *amgr_new(int size);
void amgr_edge_new(amgr_t *graph, int u, int v, int weight);
void amgr_vdata_set(amgr_t *graph, int vtx, char data);
int amgr_has_cycle(const amgr_t *graph);
void amgr_free(amgr_t *graph);
void amgr_print(const amgr_t *graph);

/*-----------------------------------------------------------------------------
 * - Linked-list based graph
 *-----------------------------------------------------------------------------*/

// Adjacency list node type
typedef struct adlistn {
    int idx;    // vtx index
    int weight; // edge weight
    struct adlistn *next;
} adlistn_t;

// Adjacency list based graph type
typedef struct {
    char *data;        // vtx data
    adlistn_t **nodes; // Adjacency list
    int size;
} algr_t;

algr_t *algr_new(int size);
void algr_edge_new(algr_t *graph, int u, int v, int weight);
void algr_vdata_set(algr_t *graph, int idx, char data);
int algr_has_cycle(const algr_t *graph);
void algr_free(algr_t *graph);
void algr_print(const algr_t *graph);

#endif
