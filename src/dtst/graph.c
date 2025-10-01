#include <stdio.h>
#include "dtst.h"
#include "../helper.h"

/**************************************************
 * - Adjacency Matrix (Array)
 **************************************************/

agr_t *agr_new(int size) {
    agr_t *g = _malloc(sizeof(agr_t));
    g->size = size;
    g->adjmat = _malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++) {
        g->adjmat[i] = _calloc(size, sizeof(int));
    }
    g->vdata = _malloc(size * sizeof(char));
    return g;
}

void agr_edge_new(agr_t *g, int u, int v, int weight) {
    if (u >= 0 && u < g->size && v >= 0 && v < g->size) {
        g->adjmat[u][v] = weight;
    }
}

void agr_vdata_set(agr_t *g, int vertex, char data) {
    if (vertex >= 0 && vertex < g->size) {
        g->vdata[vertex] = data;
    }
}

static void dfs_util(const agr_t *g, int v, int *visited) {
    visited[v] = 1;
    printf("%c ", g->vdata[v]);

    for (int i = 0; i < g->size; i++) {
        if (g->adjmat[v][i] > 0 && !visited[i]) {
            dfs_util(g, i, visited);
        }
    }
}

void agr_dfs(const agr_t *g, char start_vdata) {
    int *visited = _calloc(g->size, sizeof(int));

    for (int i = 0; i < g->size; i++) {
        if (g->vdata[i] == start_vdata) {
            printf("DFS traversal from %c: ", start_vdata);
            dfs_util(g, i, visited);
            printf("\n");
            break;
        }
    }
    __free(visited);
}

void agr_bfs(const agr_t *g, char start_vertex) {
    int *visited = _calloc(g->size, sizeof(int));
    int *queue = _malloc(g->size * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < g->size; i++) {
        if (g->vdata[i] == start_vertex) {
            queue[rear++] = i; // enqueue
            visited[i] = 1;

            while (front < rear) {
                int curr_vtx = queue[front++]; // dequeue
                printf("%c ", g->vdata[curr_vtx]);

                for (int j = 0; j < g->size; j++) {
                    if (g->adjmat[curr_vtx][j] > 0 && !visited[j]) {
                        queue[rear++] = j; // enqueue
                        visited[j] = 1;
                    }
                }
            }
            break;
        }
    }
    __free(queue);
    __free(visited);
}

static int cycle_util(const agr_t *g, int u, int *state) {
    if (state[u] == 1) return 1; // cycle
    if (state[u] == 2) return 0; // finished, no recheck

    state[u] = 1; // processing

    for (int v = 0; v < g->size; v++) {
        if (g->adjmat[u][v] > 0) {
            if (cycle_util(g, v, state)) return 1;
        }
    }
    state[u] = 2; // child check finished
    return 0;
}

int agr_has_cycle(const agr_t *g) {
    int *state = _calloc(g->size, sizeof(int));

    for (int i = 0; i < g->size; i++) {
        if (state[i] == 0) {
            if (cycle_util(g, i, state)) {
                __free(state);
                return 1; // cycle
            }
        }
    }
    __free(state);
    return 0;
}

void agr_free(agr_t *g) {
    if (!g) return;

    for (int i = 0; i < g->size; i++) __free(g->adjmat[i]);
    __free(g->adjmat);
    __free(g->vdata);
    __free(g);
}

void agr_print(const agr_t *g) {
    printf("Adjacency Matrix:\n");

    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            printf("%d ", g->adjmat[i][j]);
        }
        printf("\n");
    }
    printf("\nVertex Data:\n");

    for (int i = 0; i < g->size; i++) {
        printf("Vertex %d: %c\n", i, g->vdata[i]);
    }
}

/**************************************************
 * - Adjacency List (Sparse Graph)
 **************************************************/

sgr_t *sgr_new(int size) {
    sgr_t *g = _malloc(sizeof(sgr_t));
    g->size = size;
    g->alist = _calloc(size, sizeof(alnode_t *));
    g->vdata = _malloc(size * sizeof(char));
}

void sgr_edge_new(sgr_t *g, int u, int v, int weight);
void sgr_free(sgr_t *g);
