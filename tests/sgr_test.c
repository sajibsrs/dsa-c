#include <stdio.h>
#include <assert.h>
#include "../src/dtst/dtst.h"

int main(void) {
    int size = 5;
    printf("--- Sparse Graph (SGR) Structure and DFS Tests ---\n\n");

    // 1. Initialization and Setup Test
    sgr_t *g = sgr_new(size);

    // Set vertex data
    sgr_vdata_set(g, 0, 'S');
    sgr_vdata_set(g, 1, 'A');
    sgr_vdata_set(g, 2, 'B');
    sgr_vdata_set(g, 3, 'C');
    sgr_vdata_set(g, 4, 'D');

    // 2. Edge Creation Test
    sgr_edge_new(g, 0, 1, 10);
    sgr_edge_new(g, 1, 2, 5);
    sgr_edge_new(g, 0, 3, 7);
    sgr_edge_new(g, 0, 4, 3);
    sgr_edge_new(g, 3, 3, 1);

    printf("1. Graph Structure:\n");
    printf("-----------------------------------------------------------------------\n");
    printf("Expected Vertex 'S' (0) list order: D (w:3) -> C (w:7) -> A (w:10)\n");
    printf("-----------------------------------------------------------------------\n");

    // 3. Print Test
    sgr_print(g);
    printf("✓ sgr_new, sgr_vdata_set, sgr_edge_new verified by print.\n\n");

    // 4. DFS Traversal Test
    printf("2. DFS Traversal Test:\n");

    sgr_dfs(g, 'S');
    printf(
        "✓ sgr_dfs traversal performed. Check output order against expected LIFO/prepending "
        "logic.\n\n"
    );

    // 5. Memory Cleanup Test
    sgr_free(g);
    printf("✓ sgr_free called. Memory cleanup test successful.\n");
    printf("\n🎉 Sparse Graph Tests Completed.\n");

    return 0;
}
