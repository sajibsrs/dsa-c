#include <stdio.h>
#include "helper.h"

void *_malloc(size_t _size) {
    void *ptr = malloc(_size);
    if (!ptr) exit(11);
    return ptr;
}

void *_calloc(size_t _count, size_t _size) {
    void *ptr = calloc(_count, _size);
    if (!ptr) exit(11);
    return ptr;
}

void _free(void **_ptr) {
    if (_ptr && *_ptr) {
        free(*_ptr);
        *_ptr = NULL;
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
