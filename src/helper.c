#include <stdio.h>

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
