#include <stdio.h>
#include "../../bin_tool.h"

/*
 * 将 x 的第 i 个字节替换为 b
 * @param  x    被替换字节的源数据
 * @param  i    要替换第几个字节
 * @param  b    替换字节
 * @return 替换后的字节
 */
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    return (x & ~(0xff << (i * 8))) | (b << (i * 8)); 
}

int main(int argc, char *argv[])
{
    /*
     * 12 ab 56 78
     * 12 34 56 ab
     */
    show_int(replace_byte(0x12345678, 2, 0xAB));
    show_int(replace_byte(0x12345678, 0, 0xAB));
}
