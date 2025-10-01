#include <stdio.h>
#include <assert.h>
#include "../src/dtst/dtst.h" // Assuming graph_has_cycle is in this header

int main(void) {
    int size = 6;
    agr_t *g_acyclic = agr_new(size);
    agr_t *g_cyclic = agr_new(size);

    // Set vertex data for Acyclic Graph
    agr_vdata_set(g_acyclic, 0, 'A');
    agr_vdata_set(g_acyclic, 1, 'B');
    agr_vdata_set(g_acyclic, 2, 'C');
    agr_vdata_set(g_acyclic, 3, 'D');
    agr_vdata_set(g_acyclic, 4, 'E');
    agr_vdata_set(g_acyclic, 5, 'F');

    // Add Acyclic Edges
    agr_edge_new(g_acyclic, 0, 1, 2); // A -> B
    agr_edge_new(g_acyclic, 0, 2, 5); // A -> C
    agr_edge_new(g_acyclic, 1, 3, 3); // B -> D
    agr_edge_new(g_acyclic, 1, 4, 6); // B -> E
    agr_edge_new(g_acyclic, 2, 5, 4); // C -> F

    printf("CYCLE DETECTION TESTS\n");
    printf("----------------------------------\n");

    // Test 1: ACYCLIC Graph (Expected: 0 / FALSE)
    printf("1. ACYCLIC Graph Test:\n");
    printf("Graph Structure:\n");
    agr_print(g_acyclic);

    int is_cyclic_1 = agr_has_cycle(g_acyclic);
    assert(is_cyclic_1 == 0); // Assert graph is not cyclic
    printf("Result: Graph is %s (Expected: Not Cyclic)\n", is_cyclic_1 ? "Cyclic" : "Not Cyclic");
    printf("✓ ACYCLIC Test Passed\n");

    printf("\n2. CYCLIC Graph Test:\n");

    // Set vertex data for Cyclic Graph (Same vertices)
    agr_vdata_set(g_cyclic, 0, 'W');
    agr_vdata_set(g_cyclic, 1, 'X');
    agr_vdata_set(g_cyclic, 2, 'Y');
    agr_vdata_set(g_cyclic, 3, 'Z');

    // Add edges forming a cycle: W -> X -> Y -> W
    agr_edge_new(g_cyclic, 0, 1, 1); // W -> X
    agr_edge_new(g_cyclic, 1, 2, 1); // X -> Y
    agr_edge_new(g_cyclic, 2, 0, 1); // Y -> W (Cycle Closer)

    // Add a disconnected component (to test full traversal): Y -> Z
    agr_edge_new(g_cyclic, 2, 3, 1); // Y -> Z

    printf("Graph Structure (W->X->Y->W cycle):\n");
    agr_print(g_cyclic);

    // Test 2: CYCLIC Graph (Expected: 1 / TRUE)
    int is_cyclic_2 = agr_has_cycle(g_cyclic);
    assert(is_cyclic_2 == 1); // Assert graph is cyclic
    printf("Result: Graph is %s (Expected: Cyclic)\n", is_cyclic_2 ? "Cyclic" : "Not Cyclic");
    printf("✓ CYCLIC Test Passed\n");

    // 3. Traversal Tests (Can use g_acyclic)
    printf("TRAVERSAL TESTS\n");
    printf("----------------------------------\n");

    printf("DFS Test:\n");
    agr_dfs(g_acyclic, 'A');
    printf("✓ DFS traversal performed\n");

    printf("BFS Test:\n");
    printf("BFS traversal from A: ");
    agr_bfs(g_acyclic, 'A');
    printf("\n");
    printf("✓ BFS traversal performed\n");

    // 4. Cleanup
    agr_free(g_acyclic);
    agr_free(g_cyclic);
    printf("🎉 All Graph tests passed successfully!\n");

    return 0;
}
