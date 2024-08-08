#include "base32.h"

#ifndef CEIL_POS
#define CEIL_POS(X) (X > (uint64_t)(X) ? (uint64_t)(X + 1) : (uint64_t)(X))
#endif

unsigned char *base32_encode(const unsigned char *str)
{
    uint64_t len = strlen(str);
    uint64_t length = (len * 8 + 4) / 5 * 5;
    unsigned char *res = (unsigned char *)malloc(sizeof(unsigned char) * length);
    uint64_t idx = 0;

    for (uint64_t i = 0; i < len; i += 5)
    {
        uint64_t byte1 = (uint8_t)str[i];
        uint64_t byte2 = (i + 1 < len) ? (uint8_t)str[i + 1] : 0;
        uint32_t byte3 = (i + 2 < len) ? (uint8_t)str[i + 2] : 0;
        uint16_t byte4 = (i + 3 < len) ? (uint8_t)str[i + 3] : 0;
        uint8_t byte5 = (i + 4 < len) ? (uint8_t)str[i + 4] : 0;

        uint64_t quintuple = (byte1 << 32) | (byte2 << 24) | (byte3 << 16) | (byte4 << 8) | byte5;

        for (uint64_t j = 0; (j < 8) && (i + j * 0.625 < len); j++)
        {
            res[idx] = BASE32_TABLE[(quintuple >> (5 * (7 - j))) & 0x1f];
            idx++;
        }
    }

    char paddingChar = BASE32_TABLE[32];
    if (paddingChar)
    {
        while (idx % 8)
        {
            res[idx] = paddingChar;
            idx++;
        }
    }
    res[idx] = 0;
    return res;
}

unsigned char *base32_decode(const unsigned char *str)
{
    uint64_t len = strlen(str);
    while (str[len - 1] == BASE32_TABLE[32])
    {
        len--;
    }
    uint64_t length = CEIL_POS(len * 5 / 8) + 1;
    char *res = (unsigned char *)malloc(sizeof(unsigned char) * length);
    uint64_t idx = 0;

    for (uint64_t i = 0; i < len; i += 8)
    {
        uint64_t quintuple = 0;
        for (uint8_t j = 0; j < 8; ++j)
        {
            if (i + j < len)
                quintuple = (quintuple << 5) | ((uint8_t)BASE32_REVERSE_TABLE[str[i + j]] & 0x1f);
            else
                quintuple = quintuple << 5;
        }
        for (uint8_t j = 0; (j < 5); ++j)
        {
            res[idx] = (quintuple >> (8 * (4 - j))) & 0xff;
            idx++;
        }
    }
    res[idx] = 0;
    return res;
}
