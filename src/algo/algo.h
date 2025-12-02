#ifndef ALGO_H
#define ALGO_H

#include "../dtst/dtst.h"
#include "../helper.h"

/**************************************************
 * - Sorting
 * -- Insertion sort
 **************************************************/

/**
 * @brief Sorts an array of integers in ascending order using the insertion sort algorithm.
 * @param arr Array of integers.
 * @param len Length of the array.
 * @return
 */
void insrt(int *arr, int len);

/**************************************************
 * - Searching
 * -- Linear search
 * -- Binary search
 **************************************************/

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

/**************************************************
 * - Recursions
 * -- Fibonacci
 * -- Factorial
 **************************************************/

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

void agraph_dfs(const agr_t *g, char start_vdata);
void agraph_bfs(const agr_t *g, char start_vdata);

void sgraph_dfs(const sgr_t *g, char start_vtx);
void sgraph_bfs(const sgr_t *g, char start_vtx);

void dijkstra(sgr_t *g, int start_vtx, int *distances, int *predecessors);

#endif
