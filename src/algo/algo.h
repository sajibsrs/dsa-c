#ifndef ALGO_H
#define ALGO_H

#include "../dtst/dtst.h"
#include "../helper.h"

/******************************************************************************
 * - Sorting
 * -- Insertion sort
 ******************************************************************************/

/**
 * @brief Sorts an array of integers in ascending order using the insertion sort algorithm.
 * @param arr Array of integers.
 * @param len Length of the array.
 * @return
 */
void insrt(int *arr, int len);

/******************************************************************************
 * - Searching
 * -- Linear search
 * -- Binary search
 ******************************************************************************/

/**
 * @brief Linear search algorithm.
 * @param arr Array that need to be searched.
 * @param size Length of the array.
 * @param targ Target number.
 * @return Index or -1 on failure.
 */
int srchlin(int *arr, int size, int targ);

/**
 * @brief Binary search algorithm.
 * @param arr Array that need to be searched.
 * @param size Length of the array.
 * @param targ Target number.
 * @return Index or -1 on failure.
 */
int srchbin(int *arr, int size, int targ);

/******************************************************************************
 * - Recursions
 * -- Fibonacci
 * -- Factorial
 ******************************************************************************/

/**
 * @brief Get `nth` fibonacci number using recursion.
 * @param n Total steps.
 * @return `nth` fibonacci number.
 */
int recr_fib(int n);

/**
 * @brief Get `nth` fibonacci number using tail-recursion.
 * @param n Total steps.
 * @param a Number for the current step (starting with Fib(0)).
 * @param b Number for the next step (starting with Fib(1)).
 * @return `nth` fibonacci number.
 */
int trecr_fib(int n, int a, int b);

/**
 * @brief Get factorial of a number with recursion.
 * @param n Number.
 * @return Factorial.
 */
int recr_fact(int n);

/**
 * @brief Get factorial of a number with tail-recursion.
 * @param n Number.
 * @param a Accumulator.
 * @return Factorial.
 */
int trecr_fact(int n, int a);

/******************************************************************************
 * - Huffman coding
 *
 * Minimal implementation of Huffman coding. This is only for demonstration &
 * proof of concept.
 *
 * Huffman coding should be implemented using a priority queue (min-heap). This
 * example uses array to mimic priority queue for simplicity.
 *
 * Compressed data should be stored as packed-bits instead of characters. So,
 * no real compression is happenning here. It just demonstrates the process.
 ******************************************************************************/

#define HMAX_SIZE 256  // Supports ASCII range 0–255
#define HMAX_HEIGHT 64 // Max tree height (Max bitstring size)

// Huffman tree node
typedef struct hmnode {
    char data;
    int freq;
    struct hmnode *left, *right;
} hmnode_t;

// Huffman compression data type
typedef struct {
    char *data;
    int size;
} hmcomp_t;

// Huffman code context
typedef struct {
    char codes[HMAX_SIZE][HMAX_HEIGHT]; // Index-mapped array that stores Huffman bitstring
    int freqs[HMAX_SIZE];               // Index-mapped array for character frequency
    hmnode_t *root;                     // Huffman tree root
} hmctx_t;

/**
 * @brief Initializes the Huffman coding context.
 *
 * Sets all frequencies and codes to zero, counts character frequencies
 * from the source string, and creates leaf nodes for each unique character.
 *
 * @param ctx Pointer to Huffman context.
 * @param src Source string to analyze.
 */
void hmcode_init(hmctx_t *ctx, const char *src);

/**
 * @brief Builds the Huffman binary tree.
 *
 * Combines nodes with the smallest frequencies repeatedly
 * until a single root node remains.
 *
 * @param ctx Pointer to Huffman context.
 */
void hmcode_build(hmctx_t *ctx);

/**
 * @brief Recursively generates Huffman codes from the tree.
 *
 * Fills the `codes` array in the context with the bitstring for each character.
 *
 * @param ctx Pointer to Huffman context.
 * @param root Current root node of the (sub)tree.
 * @param arr Temporary array storing the current path (0 = left, 1 = right).
 * @param depth Current depth in the tree / length of the path.
 */
void hmcode_store(hmctx_t *ctx, hmnode_t *root, int *arr, int depth);

/**
 * @brief Encodes a string into its Huffman bitstring representation.
 *
 * Uses the codes stored in the context to convert each character
 * into its corresponding bitstring and stores it in `dest`.
 *
 * @param ctx Pointer to Huffman context with generated codes.
 * @param src Source string to encode.
 * @param dest Pointer to structure to hold the encoded bitstring and size.
 */
void hmcode_encode(hmctx_t *ctx, const char *src, hmcomp_t *dest);

/**
 * @brief Decodes a Huffman-encoded bitstring.
 *
 * Traverses the Huffman tree according to each bit in `comp->data`.
 * Writes the decoded characters into `out`.
 *
 * @param comp Pointer to the compressed data structure.
 * @param root Pointer to the root of the Huffman tree.
 * @param out Output buffer to store decoded string (should be large enough).
 */
void hmcode_decode(const hmcomp_t *comp, hmnode_t *root, char *out);

/******************************************************************************
 * - Graph
 ******************************************************************************/

void agraph_dfs(const agr_t *g, char start_vdata);
void agraph_bfs(const agr_t *g, char start_vdata);

void sgraph_dfs(const sgr_t *g, char start_vtx);
void sgraph_bfs(const sgr_t *g, char start_vtx);

void dijkstra(sgr_t *g, int start_vtx, int *distances, int *predecessors);

#endif
