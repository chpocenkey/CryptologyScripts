#include "xtea.h"

#include <stdint.h>
#include <stdio.h>

int main() {
    uint32_t data[2] = {0x6e697453, 0x00726567};
    uint32_t const key[4] = {0x11223344, 0x55667788, 0x99AABBCC, 0xDDEEFF11};
    unsigned int r = 32;

    printf("Data: %s\n", (char*)data);
    printf("Data: %u %u\n", data[0], data[1]);
    encrypt(data, key);
    printf("Encrypt Data: %x %x\n", data[0], data[1]);
    decrypt(data, key);
    printf("Decrypt Data: %u %u\n", data[0], data[1]);
    printf("Decrypt Data: %s\n", (char*)data);

    return 0;
}