#include "../src/algo/algo.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char text[] = "data compression";

    hmctx_t ctx = {0};
    hmcode_init(&ctx, text); // frequency scan + reset

    hmcode_build(&ctx); // builds tree → stored in ctx.root

    int arr[HMAX_HEIGHT];
    hmcode_store(&ctx, ctx.root, arr, 0); // generate lookup codes

    // ----------------------------------------------------
    // Measure encoded bit length (still char-per-bit demo)
    // ----------------------------------------------------
    int bitcount = 0;
    for (int i = 0; text[i]; i++)
        for (int j = 0; ctx.codes[text[i]][j]; j++) bitcount++;

    hmcomp_t comp = {0};
    comp.data = malloc(bitcount);
    if (!comp.data) return 1;

    hmcode_encode(&ctx, text, &comp);

    // ----------------------------------------------------
    // Decode test
    // ----------------------------------------------------
    char *decoded = malloc(256);
    if (!decoded) return 1;

    hmcode_decode(&comp, ctx.root, decoded);

    // ----------------------------------------------------
    // Verify text restored correctly
    // ----------------------------------------------------
    int match = 1;
    for (int i = 0; text[i]; i++) {
        if (text[i] != decoded[i]) {
            match = 0;
            break;
        }
    }

    printf("Original : %s\n", text);
    printf("Decoded  : %s\n", decoded);

    if (match) printf("\n 🎉 Huffman test passed\n");

    free(comp.data);
    free(decoded);
    return 0;
}
