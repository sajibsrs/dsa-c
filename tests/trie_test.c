#include "../src/dtst/dtst.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    trien_t *root = trien_new();

    // Basic search before insertion
    assert(trie_srch(root, "hello") == 0);
    assert(trie_srch(root, "a") == 0);
    assert(trie_srch(root, "") == 0);
    printf("✓ Basic searches before insertion\n");

    // Insert words
    trie_ins(root, "hello");
    trie_ins(root, "hey");
    trie_ins(root, "he");
    trie_ins(root, "cat");
    trie_ins(root, "dog");
    printf("✓ Insert some words\n");

    // Check inserted words
    assert(trie_srch(root, "hello") == 1);
    assert(trie_srch(root, "hey") == 1);
    assert(trie_srch(root, "he") == 1);
    assert(trie_srch(root, "cat") == 1);
    assert(trie_srch(root, "dog") == 1);
    printf("✓ Check full-word matches\n");

    // Check prefixes only (not full words)
    assert(trie_srch(root, "h") == 0);
    assert(trie_srch(root, "hel") == 0);
    assert(trie_srch(root, "do") == 0);
    printf("✓ Check prefix-only searches\n");

    // Remove some words and test
    trie_rem(root, "he");       // remove a middle word
    trie_rem(root, "dog");      // remove a leaf word
    trie_rem(root, "nonexist"); // try removing a word that doesn’t exist

    // Check that removed words are gone
    assert(trie_srch(root, "he") == 0);
    assert(trie_srch(root, "dog") == 0);

    // Check remaining words are intact
    assert(trie_srch(root, "hello") == 1);
    assert(trie_srch(root, "hey") == 1);
    assert(trie_srch(root, "cat") == 1);
    printf("✓ Remove words and check remaining\n");

    // Edge cases
    assert(trie_srch(root, "") == 0);
    trie_rem(root, ""); // removing empty word, should be safe
    printf("✓ Edge cases passed\n");

    trie_free(root);
    printf("\n🎉 All trie tests passed!\n");
    return 0;
}
