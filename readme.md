# Data Structures and Algorithms in C

## Data Structures

## Algorithms
### Recursions
- [Standard Recursion](docs/recursion.md#standard-recursion)
- [Tail-Recursion](docs/recursion.md#tail-recursion)

## Testing
```cmake
# Enable testing
include(CTest)
enable_testing()

# Tests
add_test(NAME fibonacci_rec COMMAND dsa)
add_test(NAME fibonacci_trc COMMAND dsa)
```

Run:

```terminal
ctest
```
