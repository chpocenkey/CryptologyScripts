#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base16.h"

int main() {
    unsigned char data[] = "flag{Stinger}";
    unsigned char *str1, *str2;
    char encoded[10]; // 需要有足够的空间存储编码结果，这里假设数据长度已知
    char decoded[sizeof(data)];

    // 编码
    str1 = base16_encode(data);
    printf("Encoded: %s\n", str1);

    // 解码
    str2 = base16_decode(str1);
    printf("Decoded: %s\n", str2);

    return 0;
}