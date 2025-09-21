#include "algo.h"

int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int fib_trc(int n, int a, int b) {
    if (n == 0) return a;
    return fib_trc(n - 1, b, a + b);
}

int fact_rec(int n) {
    if (n <= 1) return 1;
    return n * fact_rec(n - 1);
}

int fact_trc(int n, int a) {
    if (n <= 1) return a;
    return fact_trc(n - 1, n * a);
}
