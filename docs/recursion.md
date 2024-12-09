# Recursion

## Standard Recursion
**Example 1:** Get the `nth` fibonacci number with standard recursion.

```c
int fibonacci_rec(int n) {
    if (n <= 1) return n;
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}
```

Usage:
```c
int main(void) {
    int rec = fibonacci_rec(6);
    printf("Rec: %d\n", rec);

    return 0;
}
```

Output:
```plaintext
Rec: 8
```

**Example 2:** Get factorial of a number with recursion.

```c
int factorial_rec(int n) {
    if (n <= 1) return 1;
    return n * factorial_rec(n - 1);
}
```

Usage:
```c
int main(void) {
    int rec = factorial_rec(6);
    printf("Rec: %d\n", rec);

    return 0;
}
```

Output:
```plaintext
Rec: 720
```

## Tail-Recursion
**Example 1:** Get the `nth` fibonacci number with standard tail-recursion.

```c
int fibonacci_trc(int n, int a, int b) {
    if (n == 0) return a;
    return fibonacci_trc(n - 1, b, a + b);
}
```

Usage:
```c
int main(void) {
    int trc = fibonacci_trc(6, 0, 1);
    printf("TRec: %d\n", trc);

    return 0;
}
```

Output:
```plaintext
TRec: 8
```

**Example 2:** Get factorial of a number with tail-recursion.

```c
int factorial_trc(int n, int a) {
    if (n <= 1) return a;
    return factorial_trc(n - 1, n * a);
}
```

Usage:
```c
int main(void) {
    int trc = factorial_trc(6, 1);
    printf("TRec: %d\n", trc);

    return 0;
}
```

Output:
```plaintext
TRec: 720
```
