#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h>

#define __free(_ptr) _free((void **)&(_ptr))

void *_malloc(size_t _size);
void *_calloc(size_t _count, size_t _size);
void  _free(void **_ptr);

/**
 * @brief Prints bits in a byte.
 * @param n Byte to print.
 */
void print_byte(unsigned char n);

#endif
