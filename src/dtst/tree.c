#include "../helper.h"
#include "dtst.h"

bintrn_t *bintrn_new(bintrn_t *parent, int value) {
    bintrn_t *node = _malloc(sizeof(bintrn_t));
    node->parent = parent;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bintrn_t *bintr_srch(bintrn_t *node, int value) {
    if (!node) return NULL;
    if (value < node->data) return bintr_srch(node->left, value);
    if (value > node->data) return bintr_srch(node->right, value);
    return node;
}

bintrn_t *bintr_ins(bintrn_t *node, int value) {
    if (!node) return NULL;
    if (node->data == value) return node; // nop for same value
    if (value < node->data) {
        if (node->left != NULL) return bintr_ins(node->left, value);
        else return node->left = bintrn_new(node, value);
    } else {
        if (node->right != NULL) return bintr_ins(node->right, value);
        else return node->right = bintrn_new(node, value);
    }
    return NULL;
}

bintrn_t *bintr_rem(bintrn_t *node, int value) {
    if (!node) return NULL;

    if (value < node->data) {
        node->left = bintr_rem(node->left, value);
    } else if (value > node->data) {
        node->right = bintr_rem(node->right, value);
    } else {
        // node to remove
        if (!node->left && !node->right) {
            // leaf node
            _free(node);
            return NULL;
        } else if (!node->left) {
            // only right child
            bintrn_t *tmp = node->right;
            tmp->parent = node->parent;
            _free(node);
            return tmp;
        } else if (!node->right) {
            // only left child
            bintrn_t *tmp = node->left;
            tmp->parent = node->parent;
            _free(node);
            return tmp;
        } else {
            // both child
            bintrn_t *succ = node->right;
            while (succ->left) succ = succ->left;
            node->data = succ->data;
            node->right = bintr_rem(node->right, succ->data);
        }
    }
    return node;
}

void bintr_free(bintrn_t *node) {
    if (!node) return;
    bintr_free(node->left);
    bintr_free(node->right);
    _free(node);
}
