#include "../helper.h"
#include "dtst.h"

btsn_t *btsn_new(btsn_t *parent, int value) {
    btsn_t *node = _malloc(sizeof(btsn_t));
    node->data = value;
    node->parent = parent;
    node->left = node->right = NULL;
    return node;
}

btsn_t *bts_srch(btsn_t *node, int value) {
    if (!node) return NULL;
    if (value < node->data) return bts_srch(node->left, value);
    if (value > node->data) return bts_srch(node->right, value);
    return node;
}

btsn_t *bts_ins(btsn_t *node, int value) {
    if (!node) return NULL;
    if (node->data == value) return node; // nop for same value
    if (value < node->data) {
        if (node->left != NULL) return bts_ins(node->left, value);
        else return node->left = btsn_new(node, value);
    } else {
        if (node->right != NULL) return bts_ins(node->right, value);
        else return node->right = btsn_new(node, value);
    }
    return NULL;
}

btsn_t *bts_rem(btsn_t *node, int value) {
    if (!node) return NULL;

    if (value < node->data) {
        node->left = bts_rem(node->left, value);
    } else if (value > node->data) {
        node->right = bts_rem(node->right, value);
    } else {
        // node to remove
        if (!node->left && !node->right) {
            // leaf node
            _free(node);
            return NULL;
        } else if (!node->left) {
            // only right child
            btsn_t *tmp = node->right;
            tmp->parent = node->parent;
            _free(node);
            return tmp;
        } else if (!node->right) {
            // only left child
            btsn_t *tmp = node->left;
            tmp->parent = node->parent;
            _free(node);
            return tmp;
        } else {
            // both child
            btsn_t *succ = node->right;
            while (succ->left) succ = succ->left;
            node->data = succ->data;
            node->right = bts_rem(node->right, succ->data);
        }
    }
    return node;
}

void bts_free(btsn_t *node) {
    if (!node) return;
    bts_free(node->left);
    bts_free(node->right);
    _free(node);
}
