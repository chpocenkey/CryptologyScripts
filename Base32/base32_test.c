#include <stdio.h>
#include <string.h>
#include "base32.h"
#include "stdlib.h"

int main(void)
{
    char str[] = "flag{Stinger}";
    char *encoded = base32_encode(str);
    printf("Encoded: %s\n", encoded);

    char *decoded = base32_decode(encoded);
    printf("Decoded: %s\n", decoded);

    return 0;
}