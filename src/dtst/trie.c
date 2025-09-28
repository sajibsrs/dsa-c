#include <stdio.h>
#include <stdlib.h>
#include "dtst.h"

trie_t *trie_node_new(void) {
    trie_t *node = malloc(sizeof(trie_t));
    if (node == NULL) exit(1);

    node->is_end = 0;
    for (int i = 0; i < TRIE_SIZE; i++) {
        node->child[i] = NULL;
    }
    return node;
}

void trie_ins(trie_t *node, const char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';

        if (node->child[idx] == NULL) {
            node->child[idx] = trie_node_new();
        }
        node = node->child[idx];
    }
    node->is_end = 1;
}

int trie_find(trie_t *node, const char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (node->child[idx] == NULL) {
            return 0;
        }
        node = node->child[idx];
    }
    return node->is_end;
}

void trie_free(trie_t *node) {
    if (node == NULL) return;
    for (int i = 0; i < TRIE_SIZE; i++) {
        trie_free(node->child[i]);
    }
    free(node);
}
