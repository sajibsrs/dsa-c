#ifndef ALGO_H
#define ALGO_H

/**************************************************
 * - Sorting
 * -- Insertion
 **************************************************/

/**
 * @brief Sorts an array of integers in ascending order using the insertion sort algorithm.
 * @param arr Array of integers.
 * @param len Length of the array.
 * @return
 */
void ins_srt(int arr[], int len);

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
int fib_rec(int n);

/**
 * @brief Get `nth` fibonacci number using tail-recursion.
 * @param n Total steps.
 * @param a Number for the current step (starting with Fib(0)).
 * @param b Number for the next step (starting with Fib(1)).
 * @return `nth` fibonacci number.
 */
int fib_trc(int n, int a, int b);

/**
 * @brief Get factorial of a number with recursion.
 * @param n Number.
 * @return Factorial.
 */
int fact_rec(int n);

/**
 * @brief Get factorial of a number with tail-recursion.
 * @param n Number.
 * @param a Accumulator.
 * @return Factorial.
 */
int fact_trc(int n, int a);

#endif
