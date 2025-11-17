#include "helper.h"
#include <stdio.h>

void *_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) exit(11);
    return ptr;
}

void *_calloc(size_t count, size_t size) {
    void *ptr = calloc(count, size);
    if (!ptr) exit(11);
    return ptr;
}

void *_realloc(void *ptr, size_t size) {
    void *rptr = realloc(ptr, size);
    if (!rptr) exit(11);
    return rptr;
}

void __free(void **ptr) {
    if (ptr && *ptr) {
        free(*ptr);
        *ptr = NULL;
    }
}

void print_byte(unsigned char n) {
    unsigned char mask = 1 << 7; // 1 is 0011 0001

    for (int i = 0; i < sizeof(char) * 8; i++) {
        if ((n & mask) != 0) {
            printf("1");
        } else {
            printf("0");
        }
        mask = mask >> 1; // Check next bit
    }
    printf("\n");
}
