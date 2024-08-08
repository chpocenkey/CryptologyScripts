#ifndef _BASE58_H  
#define _BASE58_H  
  
#include <stdlib.h>  
#include <string.h>  
  
unsigned char* base58_encode(unsigned char* str);
  
unsigned char* base58_decode(unsigned char* code);
#endif  


