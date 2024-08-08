#include "xxtea.h"

void encrypt(uint32_t v[2], uint32_t const key[4]) {
    uint32_t y, z, sum;
    unsigned p, rounds, e;
    rounds = 6 + 52/2;
    sum = 0;
    z = v[1];
    do
    {
        sum += DELTA;
        e = (sum >> 2) & 3;
        for (p=0; p<n-1; p++)
        {
            y = v[p+1];
            z = v[p] += MX;
        }
        y = v[0];
        z = v[n-1] += MX;
    }
    while (--rounds);
}

void decrypt(uint32_t v[2], uint32_t const key[4]) {
    uint32_t y, z, sum;
    unsigned p, rounds, e;
    rounds = 6 + 52/2;
    sum = rounds*DELTA;
    y = v[0];
    do
    {
        e = (sum >> 2) & 3;
        for (p=1; p>0; p--)
        {
            z = v[p-1];
            y = v[p] -= MX;
        }
        z = v[n-1];
        y = v[0] -= MX;
        sum -= DELTA;
    }
    while (--rounds);
}
