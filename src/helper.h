#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h>

#define __free(ptr) _free((void **)&(ptr))

void *__malloc(size_t _size);
void *__calloc(size_t _count, size_t _size);
void _free(void **_ptr);

/**
 * @brief Prints bits in a byte.
 * @param n Byte to print.
 */
void print_byte(unsigned char n);

#endif
