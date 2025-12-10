#include "../helper.h"
#include "algo.h"
#include <string.h>

static hmnode_t *hmnode_new(char data, int freq) {
    hmnode_t *node = _malloc(sizeof(hmnode_t));
    node->data = data;
    node->freq = freq;
    node->left = node->right = 0;
    return node;
}

void hmcode_init(hmctx_t *ctx, const char *src) {
    // reset arrays
    memset(ctx->freqs, 0, sizeof ctx->freqs);
    memset(ctx->codes, 0, sizeof ctx->codes);

    // frequency count
    for (int i = 0; src[i]; i++) ctx->freqs[src[i]]++;
    ctx->root = 0;
}

static hmnode_t *extract_min(hmnode_t **nodes, int *count) {
    int idx = 0;
    for (int i = 1; i < *count; i++) {
        if (nodes[i]->freq < nodes[idx]->freq) idx = i;
    }

    hmnode_t *min = nodes[idx];
    nodes[idx] = nodes[--(*count)];
    return min;
}

void hmcode_build(hmctx_t *ctx) {
    hmnode_t *nodes[HMAX_SIZE];
    int count = 0;

    // create leaf nodes first
    for (int i = 0; i < HMAX_SIZE; i++) {
        if (ctx->freqs[i] > 0) nodes[count++] = hmnode_new(i, ctx->freqs[i]);
    }

    // merge until single tree
    while (count > 1) {
        hmnode_t *left = extract_min(nodes, &count);
        hmnode_t *right = extract_min(nodes, &count);

        hmnode_t *parent = hmnode_new('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        nodes[count++] = parent;
    }
    ctx->root = nodes[0];
}

void hmcode_store(hmctx_t *ctx, hmnode_t *root, int *bits, int depth) {
    if (root->left) {
        bits[depth] = 0;
        hmcode_store(ctx, root->left, bits, depth + 1);
    }

    if (root->right) {
        bits[depth] = 1;
        hmcode_store(ctx, root->right, bits, depth + 1);
    }

    if (!root->left && !root->right) { // leaf node
        for (int i = 0; i < depth; i++) ctx->codes[root->data][i] = bits[i] + '0';
        ctx->codes[root->data][depth] = 0;
    }
}

void hmcode_encode(hmctx_t *ctx, const char *src, hmcomp_t *dest) {
    int len = 0;
    for (int i = 0; src[i]; i++) {
        char *code = ctx->codes[src[i]];
        for (int j = 0; code[j]; j++) dest->data[len++] = code[j];
    }
    dest->size = len;
}

void hmcode_decode(const hmcomp_t *comp, hmnode_t *root, char *out) {
    hmnode_t *node = root;
    int sym = 0;

    for (int i = 0; i < comp->size; i++) {
        node = (comp->data[i] == '1') ? node->right : node->left;

        if (!node->left && !node->right) {
            out[sym++] = node->data;
            node = root;
        }
    }
    out[sym] = 0;
}
