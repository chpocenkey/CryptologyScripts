#include "RC4.h"
#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char s[256] = {0}, s2[256] = {0}; // S-box
    char key[256] = {"justfortest"};
    char pData[512] = "flag{Stinger_JustTryRC4}";
    unsigned long len = strlen(pData);
    int i;

    printf("pData=%s\n", pData);
    printf("key=%s,length=%d\n\n", key, strlen(key));
    
    RC4_init(s, (unsigned char *)key, strlen(key)); // 已经完成了初始化

    for (i = 0; i < 256; i++) // 用s2[i]暂时保留经过初始化的s[i]
    {
        s2[i] = s[i];
    }

    RC4_enc_dec(s, (unsigned char *)pData, len); // 加密
    for (int i = 1; i < strlen(pData); ++i) {
        pData[i] = pData[i] ^ pData[i - 1];
        printf("0x%x, ", pData[i-1]);
    }
    printf("0x%x", pData[strlen(pData) - 1]);
    printf("pData=%s\n\n", pData);

    RC4_enc_dec(s2, (unsigned char *)pData, len); // 解密
    printf("pData=%s\n\n", pData);

    return 0;
}