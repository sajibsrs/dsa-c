#ifndef _ALGO_H
#define _ALGO_H

/**************************************************
 * - Recursions
 **************************************************/

/**
 * @brief Get `nth` fibonacci number using recursion.
 * @param n Total steps.
 * @return `nth` fibonacci number.
 */
int fibonacci_rec(int n);

/**
 * @brief Get `nth` fibonacci number using tail-recursion.
 * @param n Total steps.
 * @param a Number for the current step (starting with Fib(0)).
 * @param b Number for the next step (starting with Fib(1)).
 * @return `nth` fibonacci number.
 */
int fibonacci_trc(int n, int a, int b);

#endif
