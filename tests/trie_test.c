#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "../src/dtst/dtst.h"

int main(void) {
    // Create trie
    trie_t *root = trie_node_new();

    // Test 1: Insert and find lowercase words
    trie_ins(root, "hello");
    trie_ins(root, "world");
    trie_ins(root, "test");
    trie_ins(root, "tree");

    assert(trie_find(root, "hello") == true);
    assert(trie_find(root, "world") == true);
    assert(trie_find(root, "test") == true);
    assert(trie_find(root, "tree") == true);
    printf("✓ Lowercase words work\n");

    // Test 2: Non-existent words
    assert(trie_find(root, "hell") == false);   // prefix
    assert(trie_find(root, "wor") == false);    // prefix
    assert(trie_find(root, "hello!") == false); // longer (special char)
    assert(trie_find(root, "abc") == false);    // different
    printf("✓ Non-existent words correctly not found\n");

    // Test 3: Empty string edge case
    trie_ins(root, "");           // Insert empty string
    assert(root->is_end == true); // Root should be marked as end
    printf("✓ Empty string handled\n");

    // Test 4: Valid lowercase only operations
    trie_ins(root, "apple");
    trie_ins(root, "zebra"); // Edge cases: first and last letters
    assert(trie_find(root, "apple") == true);
    assert(trie_find(root, "zebra") == true);
    printf("✓ Letter boundaries work\n");

    // Cleanup
    trie_free(root);
    printf("✓ Memory freed successfully\n");

    printf("\nAll trie tests passed! 🎉\n");
    return 0;
}
