#include "algo.h"

int fibonacci_rec(int n) {
    if (n <= 1) return n;
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

int fibonacci_trc(int n, int a, int b) {
    if (n == 0) return a;
    return fibonacci_trc(n - 1, b, a + b);
}

int factorial_rec(int n) {
    if (n <= 1) return 1;
    return n * factorial_rec(n - 1);
}

int factorial_trc(int n, int a) {
    if (n <= 1) return a;
    return factorial_trc(n - 1, n * a);
}
