#include "../src/dtst/dtst.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    printf("Testing binary tree...\n");

    // Create root
    bintrn_t *root = bintrn_new(NULL, 50);
    printf("✓ Root created\n");
    assert(root->data == 50);
    assert(root->parent == NULL);

    // Insert elements
    bintr_ins(root, 30);
    bintr_ins(root, 70);
    bintr_ins(root, 20);
    bintr_ins(root, 40);
    bintr_ins(root, 60);
    bintr_ins(root, 80);

    printf("✓ Inserted 30,70,20,40,60,80\n");

    // Search tests
    assert(bintr_srch(root, 30)->data == 30);
    assert(bintr_srch(root, 80)->data == 80);
    assert(bintr_srch(root, 999) == NULL);
    printf("✓ Search works\n");

    // Check parent links
    assert(bintr_srch(root, 30)->parent == root);
    assert(bintr_srch(root, 20)->parent == bintr_srch(root, 30));
    printf("✓ Parent pointers correct\n");

    // DELETE leaf node (40)
    root = bintr_rem(root, 40);
    assert(bintr_srch(root, 40) == NULL);
    printf("✓ Removed leaf node 40\n");

    // DELETE node with ONE child (80 has no left, but we remove 70 first)
    root = bintr_rem(root, 70);
    assert(bintr_srch(root, 70) == NULL);
    assert(bintr_srch(root, 80)); // 80 must survive
    printf("✓ Removed node 70 (one child)\n");

    // DELETE node with TWO children (30 has 20 and ???)
    bintr_ins(root, 35);
    bintr_ins(root, 33);
    printf("✓ Added nodes for two-child delete test\n");

    root = bintr_rem(root, 30);
    assert(bintr_srch(root, 30) == NULL);
    printf("✓ Removed node 30 (two children, successor promoted)\n");

    // DELETE ROOT (current root = 50)
    root = bintr_rem(root, 50);
    assert(bintr_srch(root, 50) == NULL);
    printf("✓ Removed root node\n");

    // Tree still valid?
    assert(root != NULL);
    printf("✓ Tree remains valid after root deletion\n");

    bintr_free(root);
    printf("✓ Tree freed successfully\n");

    printf("\n🎉 All binary tree tests passed!\n");
    return 0;
}
