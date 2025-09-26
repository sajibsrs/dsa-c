#include <stdio.h>
#include "dtst.h"

void graph_init(graph_t *g) {
    for (int i = 0; i < GRAPH_SIZE; i++) {
        for (int j = 0; j < GRAPH_SIZE; j++) {
            g->adj_matrix[i][j] = 0;
        }
        g->vertex_data[i] = '\0';
    }
}

void graph_add_edge(graph_t *g, int u, int v, int weight) {
    if (u >= 0 && u < GRAPH_SIZE && v >= 0 && v < GRAPH_SIZE) {
        g->adj_matrix[u][v] = weight;
    }
}

void graph_set_vertex_data(graph_t *g, int vertex, char data) {
    if (vertex >= 0 && vertex < GRAPH_SIZE) {
        g->vertex_data[vertex] = data;
    }
}

void graph_print(const graph_t *g) {
    printf("Adjacency Matrix (weights):\n");
    printf("   A  B  C  D\n");

    const char *labels = "ABCD";
    for (int i = 0; i < GRAPH_SIZE; i++) {
        printf("%c ", labels[i]);
        for (int j = 0; j < GRAPH_SIZE; j++) {
            printf("%2d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nEdges:\n");
    for (int i = 0; i < GRAPH_SIZE; i++) {
        for (int j = 0; j < GRAPH_SIZE; j++) {
            if (g->adj_matrix[i][j] > 0) {
                printf(
                    "%c -(%d)-> %c\n", g->vertex_data[i], g->adj_matrix[i][j], g->vertex_data[j]
                );
            }
        }
    }
}
