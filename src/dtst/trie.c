#include <stdio.h>
#include "dtst.h"

trie_t *trie_node_new(void) {
    trie_t *node = malloc(sizeof(trie_t));
    if (!node) exit(1);

    node->is_end = false;
    for (int i = 0; i < TRIE_SIZE; i++) node->child[i] = NULL;
    return node;
}

void trie_ins(trie_t *node, char const *word) {
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';

        if (!node->child[idx]) node->child[idx] = trie_node_new();
        node = node->child[idx];
    }
    node->is_end = true;
}

bool trie_find(trie_t *node, const char *word) {
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        if (!node->child[idx]) return false;
        node = node->child[idx];
    }
    return node->is_end;
}

void trie_free(trie_t *node) {
    if (!node) return;
    for (int i = 0; i < TRIE_SIZE; i++) {
        trie_free(node->child[i]);
    }
    free(node);
}
