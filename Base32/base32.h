#ifndef _BASE32_H
#define _BASE32_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

static const char BASE32_TABLE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";
static const uint8_t BASE32_REVERSE_TABLE[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 27, 28, 29, 30, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6,
        7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
};

unsigned char *base32_encode(const unsigned char *str);

unsigned char *base32_decode(const unsigned char *str);

#endif //_BASE32_H

