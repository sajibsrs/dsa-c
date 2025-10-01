#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h>

#define xfree(ptr) _xfree((void **)&(ptr))

void *xmalloc(size_t _size);
void *xcalloc(size_t _count, size_t _size);
void _xfree(void **_ptr);

/**
 * @brief Prints bits in a byte.
 * @param n Byte to print.
 */
void print_byte(unsigned char n);

#endif
