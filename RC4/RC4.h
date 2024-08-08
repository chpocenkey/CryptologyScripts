#ifndef _RC4_H  
#define _RC4_H  
  
#include <stdlib.h>  
#include <string.h>  

void RC4_init(unsigned char*s,unsigned char*key, unsigned long Len);
void RC4_enc_dec(unsigned char*s,unsigned char*key, unsigned long Len);

#endif  