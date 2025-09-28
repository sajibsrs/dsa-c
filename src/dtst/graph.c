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

static void dfs_util(const graph_t *g, int v, int visited[]) {
    visited[v] = 1;
    printf("%c ", g->vertex_data[v]);

    for (int i = 0; i < GRAPH_SIZE; i++) {
        if (g->vertex_data[i] != '\0' && g->adj_matrix[v][i] > 0 && visited[i] == 0) {
            dfs_util(g, i, visited);
        }
    }
}

void graph_dfs(const graph_t *g, char start_vertex) {
    int visited[GRAPH_SIZE] = {0};

    for (int i = 0; i < GRAPH_SIZE; i++) {
        if (g->vertex_data[i] == start_vertex) {
            printf("DFS traversal from %c: ", start_vertex);
            dfs_util(g, i, visited);
            printf("\n");
            break;
        }
    }
    printf("Vertex %c not found\n", start_vertex);
}

void graph_print(const graph_t *g) {
    int actual_size = 0;
    for (int i = 0; i < GRAPH_SIZE; i++) {
        if (g->vertex_data[i] != '\0') {
            actual_size = i + 1;
        }
    }

    printf("Adjacency Matrix (weights):\n");
    printf("   ");
    for (int i = 0; i < actual_size; i++) {
        printf("%c ", g->vertex_data[i]);
    }
    printf("\n");

    for (int i = 0; i < actual_size; i++) {
        printf("%c ", g->vertex_data[i]);
        for (int j = 0; j < actual_size; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nEdges:\n");
    for (int i = 0; i < actual_size; i++) {
        for (int j = 0; j < actual_size; j++) {
            if (g->adj_matrix[i][j] > 0) {
                printf(
                    "%c -(%d)-> %c\n", g->vertex_data[i], g->adj_matrix[i][j], g->vertex_data[j]
                );
            }
        }
    }
}
