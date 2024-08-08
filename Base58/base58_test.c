#include "base58.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *encoded = NULL;
    char *decoded = NULL;

    encoded = base58_encode("flag{Stinger}");
    printf("Encoded: %s\n", encoded);
x`
    decoded = base58_decode(encoded);
    printf("Decoded: %s\n", decoded);

    return 0;
}