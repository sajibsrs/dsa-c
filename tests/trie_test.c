#include <stdio.h>
#include <assert.h>
#include "../src/dtst/dtst.h"

int main(void) {
    trie_t *root = trie_node_new();

    trie_ins(root, "cat");
    trie_ins(root, "car");
    trie_ins(root, "dog");

    assert(trie_find(root, "cat") == 1);
    assert(trie_find(root, "car") == 1);
    assert(trie_find(root, "dog") == 1);
    assert(trie_find(root, "cap") == 0);
    assert(trie_find(root, "cats") == 0);

    printf("All trie tests passed!\n");

    trie_free(root);
    return 0;
}
