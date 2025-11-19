#include "../helper.h"
#include "dtst.h"

trien_t *trien_new(void) {
    trien_t *node = _malloc(sizeof(trien_t));
    node->is_end = 0;

    for (int i = 0; i < TRIE_SIZE; i++) node->cnodes[i] = NULL;
    return node;
}

void trie_ins(trien_t *root, const char *word) {
    trien_t *node = root;

    while (*word) {
        int idx = *word - 'a';
        if (idx < 0 || idx >= TRIE_SIZE) return;

        if (!node->cnodes[idx]) node->cnodes[idx] = trien_new();
        node = node->cnodes[idx];
        word++;
    }
    node->is_end = 1;
}

int trie_srch(trien_t *root, const char *word) {
    trien_t *node = root;

    while (*word) {
        int idx = *word - 'a';
        if (!node->cnodes[idx]) return 0; // Word not found
        node = node->cnodes[idx];
        word++;
    }
    return node->is_end;
}

static int trie_remh(trien_t *node, const char *word) {
    if (*word) {
        int idx = *word - 'a';
        if (!node->cnodes[idx]) return 0;

        // Recurse for the next character
        if (trie_remh(node->cnodes[idx], word + 1)) {
            _free(node->cnodes[idx]);
            node->cnodes[idx] = NULL;
        }
        // If this node marks the end of another word: KEEP
        if (node->is_end) return 0;

        // If we have any remaining children: KEEP
        for (int i = 0; i < TRIE_SIZE; i++) {
            if (node->cnodes[i]) return 0;
        }
        // No children + not end: DELETE
        return 1;
    }
    // End of word reached
    if (!node->is_end) return 0; // Word not found
    node->is_end = 0;            // Remove end marker

    // If this node has children: KEEP
    for (int i = 0; i < TRIE_SIZE; i++) {
        if (node->cnodes[i]) return 0;
    }
    // No children: DELETE
    return 1;
}

void trie_rem(trien_t *root, const char *word) {
    trie_remh(root, word);
}

void trie_free(trien_t *node) {
    for (int i = 0; i < TRIE_SIZE; i++) {
        if (node->cnodes[i]) trie_free(node->cnodes[i]);
    }
    _free(node);
}
