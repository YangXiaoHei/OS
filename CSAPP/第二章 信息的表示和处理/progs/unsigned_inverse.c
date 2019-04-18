/*
 * 重要!!!!!!!!
 * 仔细理解并复习这些转换!!!
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /*
     * ffffff01
     * 1
     * ffffffff
     * ffffff01
     * ffffff55
     * ffffffee
     */

    /*
     * 0xFF 先提升为 int, 即变为 0x000000FF
     * 然后 0xFF 变为无符号
     * 然后对无符号的 int 0xFF 求加法逆元得到 0xFFFFFF01
     */
    int a = -(unsigned char)0xFF;
    printf("%x\n", a);

    /*
     * 0xFF 先变为负数
     * 然后提升为 int, 即变为 0xFFFFFFFF
     * 然后变为无符号
     * 然后对无符号 int 0xFFFFFFFF 求加法逆元得到 0x00000001
     */
    int b = (unsigned char)-0xFF;
    printf("%x\n", b);

    /*
     * 0x1 先提升为 int，即变为 0x00000001
     * 然后变为无符号
     * 然后对无符号 int 0x00000001 求加法逆元得到 0xFFFFFFFF
     */
    int c = -(unsigned char)0x1;
    printf("%x\n", c);

    printf("%x\n", -(unsigned char)0xFF);    
    printf("%x\n", -(unsigned char)0xAB);   
    printf("%x\n", -(unsigned char)0x12);  
}
