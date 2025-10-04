#include <stdio.h>
#include "dtst.h"
#include "../helper.h"

/**************************************************
 * - Adjacency Matrix (Array)
 **************************************************/

agr_t *agr_new(int size) {
    agr_t *g = __malloc(sizeof(agr_t));
    g->size = size;
    g->adjmat = __malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++) {
        g->adjmat[i] = __calloc(size, sizeof(int));
    }
    g->vdata = __malloc(size * sizeof(char));
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

static void agr_dfs_util(const agr_t *g, int v, int *visited) {
    visited[v] = 1;
    printf("%c ", g->vdata[v]);

    for (int i = 0; i < g->size; i++) {
        if (g->adjmat[v][i] > 0 && !visited[i]) {
            agr_dfs_util(g, i, visited);
        }
    }
}

void agr_dfs(const agr_t *g, char start_vdata) {
    int *visited = __calloc(g->size, sizeof(int));

    for (int i = 0; i < g->size; i++) {
        if (g->vdata[i] == start_vdata) {
            printf("DFS traversal from %c: ", start_vdata);
            agr_dfs_util(g, i, visited);
            printf("\n");
            break;
        }
    }
    __free(visited);
}

void agr_bfs(const agr_t *g, char start_vertex) {
    int *visited = __calloc(g->size, sizeof(int));
    int *queue = __malloc(g->size * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < g->size; i++) {
        if (g->vdata[i] == start_vertex) {
            queue[rear++] = i; // enqueue
            visited[i] = 1;

            while (front < rear) {
                int curr_qidx = queue[front++]; // dequeue
                printf("%c ", g->vdata[curr_qidx]);

                for (int j = 0; j < g->size; j++) {
                    if (g->adjmat[curr_qidx][j] > 0 && !visited[j]) {
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

static int agr_cycle_util(const agr_t *g, int u, int *state) {
    if (state[u] == 1) return 1; // processing, cycle
    if (state[u] == 2) return 0; // finished, no recheck

    state[u] = 1; // processing

    for (int v = 0; v < g->size; v++) {
        if (g->adjmat[u][v] > 0) {
            if (agr_cycle_util(g, v, state)) return 1;
        }
    }
    state[u] = 2; // check finished
    return 0;
}

int agr_has_cycle(const agr_t *g) {
    int *state = __calloc(g->size, sizeof(int));

    for (int i = 0; i < g->size; i++) {
        if (state[i] == 0) {
            if (agr_cycle_util(g, i, state)) {
                __free(state);
                return 1; // cycle
            }
        }
    }
    __free(state);
    return 0; // no cycle
}

void agr_free(agr_t *g) {
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
    sgr_t *g = __malloc(sizeof(sgr_t));
    g->size = size;
    g->alist = __calloc(size, sizeof(alnode_t *));
    g->vdata = __malloc(size * sizeof(char));

    return g;
}

void sgr_edge_new(sgr_t *g, int u, int v, int weight) {
    if (u >= 0 && u < g->size && v >= 0 && v < g->size) {
        alnode_t *new_node = __malloc(sizeof(alnode_t));
        new_node->vindex = v;
        new_node->weight = weight;
        new_node->next = g->alist[u];
        g->alist[u] = new_node;
    }
}

void sgr_vdata_set(sgr_t *g, int vertex, char data) {
    if (vertex >= 0 && vertex < g->size) {
        g->vdata[vertex] = data;
    }
}

static void sgr_dfs_util(const sgr_t *g, int u, int *visited) {
    visited[u] = 1;
    printf("%c ", g->vdata[u]);

    alnode_t *current = g->alist[u];
    while (current != NULL) {
        int v = current->vindex;
        if (!visited[v]) {
            sgr_dfs_util(g, v, visited);
        }
        current = current->next;
    }
}

void sgr_dfs(const sgr_t *g, char start_vtx) {
    int *visited = __calloc(g->size, sizeof(int));

    for (int i = 0; i < g->size; i++) {
        if (g->vdata[i] == start_vtx) {
            printf("DFS traversal from %c: ", start_vtx);
            sgr_dfs_util(g, i, visited);
            printf("\n");
            break;
        }
    }
    __free(visited);
}

void sgr_bfs(const sgr_t *g, char start_vtx) {
    int *visited = __calloc(g->size, sizeof(int));
    int *queue = __malloc(g->size * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < g->size; i++) {
        if (g->vdata[i] == start_vtx) {
            queue[rear++] = i; // enqueue
            visited[i] = 1;

            while (front < rear) {
                int curr_qidx = queue[front++]; // dequeue
                printf("%c ", g->vdata[curr_qidx]);

                alnode_t *current = g->alist[curr_qidx];
                while (current != NULL) {
                    int v = current->vindex;
                    if (!visited[v]) {
                        queue[rear++] = v; // enqueue
                        visited[v] = 1;
                    }
                    current = current->next;
                }
            }
            break;
        }
    }
    __free(queue);
    __free(visited);
}

static int sgr_cycle_util(const sgr_t *g, int u, int *state) {
    if (state[u] == 1) return 1; // processing, cycle
    if (state[u] == 2) return 0; // finished, no need to check

    state[u] = 1; // processing

    alnode_t *curr = g->alist[u];
    while (curr) {
        int v = curr->vindex;
        if (sgr_cycle_util(g, v, state)) return 1;
        curr = curr->next;
    }
    state[u] = 2; // finished
    return 0;
}

int sgr_has_cycle(const sgr_t *g) {
    int *state = __calloc(g->size, sizeof(int));

    for (int i = 0; i < g->size; i++) {
        if (state[i] == 0) {
            if (sgr_cycle_util(g, i, state)) {
                __free(state);
                return 1; // cycle found
            }
        }
    }
    __free(state);
    return 0; // no cycle
}

void sgr_print(const sgr_t *g) {
    for (int i = 0; i < g->size; i++) {
        printf("Vertex %d ('%c'): -> ", i, g->vdata[i]);

        alnode_t *current = g->alist[i];
        while (current != NULL) {
            printf("v%d (w:%d)", current->vindex, current->weight);
            current = current->next;

            if (current != NULL) {
                printf(" -> ");
            }
        }
        printf("\n");
    }
}

void sgr_free(sgr_t *g) {
    for (int i = 0; i < g->size; i++) {
        alnode_t *current = g->alist[i];
        alnode_t *temp;

        while (current != NULL) {
            temp = current;
            current = current->next;
            free(temp);
        }
    }
    __free(g->alist);
    __free(g->vdata);
    __free(g);
}
