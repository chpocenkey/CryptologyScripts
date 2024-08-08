#include "base16.h"

// 用于Base16编码的字符集
const unsigned char *base16_table = "0123456789ABCDEF";

// Base16编码函数
unsigned char *base16_encode(const unsigned char *str)
{
    unsigned char *res;
    long len = strlen(str);
    res = malloc(sizeof(unsigned char) * len * 2 + 1);

    for (int i = 0; i < len; ++i)
    {
        res[i * 2] = base16_table[(str[i] >> 4) & 0x0F];
        res[i * 2 + 1] = base16_table[str[i] & 0x0F];
    }

    res[len * 2] = '\0'; // 确保输出字符串以空字符结尾

    return res;
}

// Base16解码函数
unsigned char *base16_decode(const unsigned char *str)
{
    unsigned char *res;
    long len = strlen(str);

    res = malloc(sizeof(unsigned char) * len / 2 + 1);

    for (int i = 0; i < len; i += 2)
    {
        // 检查输入是否有效
        if (str[i] >= '0' && str[i] <= '9')
        {
            res[i / 2] = (str[i] - '0') << 4;
        }
        else if (str[i] >= 'A' && str[i] <= 'F')
        {
            res[i / 2] = (str[i] - 'A' + 10) << 4;
        }
        else
        {
            return 0; // 无效的字符，解码失败
        }

        if (str[i + 1] >= '0' && str[i + 1] <= '9')
        {
            res[i / 2] |= str[i + 1] - '0';
        }
        else if (str[i + 1] >= 'A' && str[i + 1] <= 'F')
        {
            res[i / 2] |= str[i + 1] - 'A' + 10;
        }
        else
        {
            return 0; // 无效的字符，解码失败
        }
    }
    return res; // 返回解码后的数据长度
}
