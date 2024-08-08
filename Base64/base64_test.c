#include "base64.h"  
#include <stdio.h> 
#include <string.h>   
  
int main(void)  
{  
    char *encoded = NULL;
    char *decoded = NULL;

    encoded = "flag{a8d4347722800e72e34e1aba3fe914ae}";
    encoded = base64_encode(encoded);
    printf("Encoded: %s\n", encoded);
    decoded = base64_decode(encoded);
    printf("Decoded: %s\n", decoded);
  
    return 0;  
} 