#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *base58_encode(unsigned char *str)  // 编码
{
  // 定义 base58 编码表
    static char *nb58 = (char *)"123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
    size_t len = strlen((char *)str);
    size_t rlen = (len / 2 + 1) * 3;
    unsigned char *ret = (unsigned char *)malloc(rlen + len);
    unsigned char *src = ret + rlen;
    unsigned char *rptr = ret + rlen;
    unsigned char *ptr, *e = src + len - 1;
    size_t i;
    memcpy(src, str, len);
    while (src <= e) {
        if (*src) {
        unsigned char rest = 0;
        ptr = src;
        while (ptr <= e) {
            unsigned int c = rest * 256;
            rest = (c + *ptr) % 58;
            *ptr = (c + *ptr) / 58;
            ptr++;
        }
        --rptr;
        *rptr = nb58[rest];
        } else {
        src++;
        }
    }
    for (i = 0; i < ret + rlen - rptr; i++) ret[i] = rptr[i];
    ret[i] = 0;
    return ret;
}

unsigned char *base58_decode(unsigned char *src)  // 解码
{
    static char b58n[] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  1,  2,  3,  4,
        5,  6,  7,  8,  -1, -1, -1, -1, -1, -1, -1, 9,  10, 11, 12, 13, 14, 15,
        16, -1, 17, 18, 19, 20, 21, -1, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
        32, -1, -1, -1, -1, -1, -1, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,
        -1, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1,
    };
    size_t len = strlen((char *)src);
    size_t rlen = (len / 4 + 1) * 3;
    unsigned char *ret = (unsigned char *)malloc(rlen);
    unsigned char *rptr = ret + rlen;
    size_t i;
    unsigned char *ptr;
    for (i = 0; i < len; i++) {
        char rest = b58n[src[i]];
        if (rest < 0) {
            free(ret);
            return NULL;
        }
        for (ptr = ret + rlen - 1; ptr >= rptr; ptr--) {
            unsigned int c = rest + *ptr * 58;
            *ptr = c % 256;
            rest = c / 256;
        }
        if (rest > 0) {
            rptr--;
            if (rptr < ret) {
                free(ret);
                return NULL;
            }
            *rptr = rest;
        }
    }
    for (i = 0; i < ret + rlen - rptr; i++) ret[i] = rptr[i];
    ret[i] = 0;
    return ret;
}
