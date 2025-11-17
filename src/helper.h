#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h>

#define _free(ptr) __free((void **)&(ptr))

void *_malloc(size_t size);
void *_calloc(size_t count, size_t size);
void *_realloc(void *ptr, size_t size);
void __free(void **ptr);

/**
 * @brief Prints bits in a byte.
 * @param n Byte to print.
 */
void print_byte(unsigned char n);

#endif
