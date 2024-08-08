#include <stdio.h>
#include <stdint.h>
#include "tea.h"

int main()
{
    uint32_t data[3] = {0x44434241,0x48474645,0x0};
    printf("Data: %s\n", (char*)data);
    printf("Data: %x %x\n", data[0], data[1]);
    uint32_t const key[4] = {0x11223344, 0x55667788, 0x99AABBCC, 0xDDEEFF11};
    encrypt(data, key);
    printf("Encrypt Data: %c %c\n", data[0], data[1]);
    decrypt(data, key);
    printf("Decrypt Data: %c %c\n", data[0], data[1]);
    printf("Decrypt Data: %s\n", (char *)data);
    return 0;
}