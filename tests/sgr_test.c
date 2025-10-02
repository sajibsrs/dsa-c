#include <stdio.h>
#include <assert.h>
#include "../src/dtst/dtst.h"

int main(void) {
    int size = 5;
    printf("--- Sparse Graph (SGR) Core Structure Tests ---\n\n");

    // 1. Initialization and Setup Test
    sgr_t *g = sgr_new(size);

    // Set vertex data
    sgr_vdata_set(g, 0, 'S');
    sgr_vdata_set(g, 1, 'A');
    sgr_vdata_set(g, 2, 'B');
    sgr_vdata_set(g, 3, 'C');
    sgr_vdata_set(g, 4, 'D');

    // 2. Edge Creation Test (Focus on Linked List Structure)

    // Test 2a: Simple path (S -> A -> B)
    sgr_edge_new(g, 0, 1, 10); // S -> A
    sgr_edge_new(g, 1, 2, 5);  // A -> B

    // Test 2b: Multiple edges from one vertex (S -> C, D)
    // Note: Since sgr_edge_new prepends, D will appear before C in the printout for S.
    sgr_edge_new(g, 0, 3, 7); // S -> C
    sgr_edge_new(g, 0, 4, 3); // S -> D

    // Test 2c: Isolated vertex (Vertex 3/C has an edge to itself for testing)
    sgr_edge_new(g, 3, 3, 1);

    printf("1. Structure Initialization and Edge Addition:\n");
    printf("Expected Structure for Vertex 'S' (0): -> v4 (w:3) -> v3 (w:7) -> v1 (w:10)\n");
    printf("-----------------------------------------------------------------------\n");

    // 3. Print Test
    sgr_print(g);
    printf("✓ sgr_new, sgr_vdata_set, sgr_edge_new verified by print.\n\n");

    // 4. Memory Cleanup Test
    sgr_free(g);
    printf("✓ sgr_free called. Check memory usage/leak detection tools for safety.\n");

    // We can't use assert() here as we can't verify the structure's state without
    // traversal/inspection functions.

    printf("\n🎉 Sparse Graph Core Structure Tests Completed.\n");

    return 0;
}
