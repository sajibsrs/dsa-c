#include "algo.h"

int fibonacci_rec(int n) {
    if (n <= 1) return n;
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

int fibonacci_trc(int n, int a, int b) {
    if (n == 0) return a;
    return fibonacci_trc(n - 1, b, a + b);
}
