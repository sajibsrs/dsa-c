#include <stdio.h>
#include "../src/dtst/dtst.h"

void print_adjacency_matrix(int matrix[4][4], int size) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void test_weighted_directed(void) {
    printf("Weighted Directed Graph:\n");
    graph_t g;
    graph_init(&g);

    // Set vertex data: A=0, B=1, C=2, D=3
    graph_set_vertex_data(&g, 0, 'A');
    graph_set_vertex_data(&g, 1, 'B');
    graph_set_vertex_data(&g, 2, 'C');
    graph_set_vertex_data(&g, 3, 'D');

    // Add weighted edges as directed graph
    graph_add_edge(&g, 0, 1, 3); // A -(3)-> B
    graph_add_edge(&g, 0, 2, 2); // A -(2)-> C
    graph_add_edge(&g, 3, 0, 4); // D -(4)-> A
    graph_add_edge(&g, 2, 1, 1); // C -(1)-> B

    graph_print(&g);
}

void test_array_matrix(void) {
    printf("\nArray-Based Adjacency Matrix:\n");

    int adj_matrix[4][4] = {
        {0, 1, 1, 1}, // A
        {1, 0, 1, 0}, // B
        {1, 1, 0, 0}, // C
        {1, 0, 0, 0}  // D
    };

    print_adjacency_matrix(adj_matrix, 4);

    printf("\nEdges:\n");
    char vertices[] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (adj_matrix[i][j] == 1) {
                printf("%c -> %c\n", vertices[i], vertices[j]);
            }
        }
    }
}

int main(void) {
    test_weighted_directed();
    test_array_matrix();
    return 0;
}
