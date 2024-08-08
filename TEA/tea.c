#include "tea.h"

void encrypt(uint32_t *entryData, uint32_t const *key)
{
    uint32_t x = entryData[0];
    uint32_t y = entryData[1];
    uint32_t sum = 0;
    uint32_t delta = 0x9e3779b9;

    for (int i = 0; i < 32; i++)
    {
        sum += delta;
        x += ((y << 4) + key[0]) ^ (y + sum) ^ ((y >> 5) + key[1]);
        y += ((x << 4) + key[2]) ^ (x + sum) ^ ((x >> 5) + key[3]);
    }
    entryData[0] = x;
    entryData[1] = y;
}

void decrypt(uint32_t *v, uint32_t const *k)
{
    uint32_t v0 = v[0], v1 = v[1], i; // 这里的sum是0x9e3779b9*32后截取32位的结果，截取很重要。
    uint32_t delta = 0x9e3779b9;
    uint32_t sum = delta << 5;
    uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];
    for (i = 0; i < 32; i++)
    {
        v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
        v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
        sum -= delta;
    }
    v[0] = v0;
    v[1] = v1;
}

