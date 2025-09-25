# Data Structures and Algorithms in C

## Data Structures
### Linked Lists
- Singly Linked-List
- Doubly Linked-List
- Circular List

### Stacks & Queues
- Stack
- Queue

### Trees
- Binary trees
- Binary search trees
- AVL trees
- B-trees
- Tries

### Heaps & Priority Queues
- Heaps
- Priority queues

### Spatial Trees
- Quad trees
- k-d trees

### Sets
- Sets

### Hash Tables
- Hash tables
  - Chained hash table
  - Open-addressed hash table
- Hash sets
- Hash maps

### Bloom Filters

### Skip Lists

### Grids
- Grids

### Graphs
- Graphs

## Algorithms
### Dynamic Programming
- Memoization
- Tabulation

### Recursions
- Standard Recursion
- Tail-Recursion

### Sorting
- Insertion sort
- Quick sort
- Merge sort
- Counting sort
- Radix sort

### Searching
- Linear search
- Binary search

### Data Compression
- Bit operations
- Huffman coding
- LZ77

### Data Encryption
- DES
- AES
- RSA

### Tree Algorithms
- Pre-order traversal
- In-order traversal
- Post-order traversal

### Grid Algorithms
- Nearest neighbor

### Graph Algorithms
- Minimum spanning trees
  - Prim's
  - Kruskal's
- Shortest paths
  - Dijkstra's
  - Bellman-Ford
- Maximum flow
  - Ford-Fukerson
  - Edmonds-Karp
- Traveling salesman

### Geometric Algorithms
- Line segments intersection
- Convex hulls
- Arch Length on spherical surface

## Testing
```cmake
# Enable testing
include(CTest)
enable_testing()

# Test executables
add_executable(test_slist tests/slist_test.c ${LIB_SRC})
target_include_directories(test_slist PRIVATE src src/dtst)

# Registers tests
add_test(NAME TestSList COMMAND test_slist)
```

Run:

```terminal
cmake --build build
ctest --test-dir build // or `cd build` and run `ctest`
```
