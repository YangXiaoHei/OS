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
     * ffffffff
     */

    /*
     * 0xFF 是字面量, 默认 int 型, 即 0x000000FF
     * 然后 0xFF 变为 unsigned char 被截断, 即 0xFF
     * 然后当负号作用于它时，它又被提升为 int，即 0x000000FF
     * 然后对无符号的 int 0xFF 求加法逆元得到 0xFFFFFF01
     *
     * 其实想到这里我发现，对补码和无符号数取非都是一样的可以应用 ~x + 1
     * 比如 0x80000000 取非，等同于 0x7FFFFFFF+1
     * 比如 0xFFFFFFFF 取非，等同于 0x00000000+1
     */
    int a = -(unsigned char)0xFF;
    printf("%x\n", a);

    /*
     * 0xFF 是字面量，默认 int 型，因此对其求非结果是 0xFFFFFF01
     * 然后将其强转为无符号 char，即截断为 0x01
     * 当使用 %x 打印时被提升为 int，执行 0 位扩展，即 0x00000001
     * 打印时前导 0 被省略, 即 1
     */
    int b = (unsigned char)-0xFF;
    printf("%x\n", b);

    /*
     * 0x1 是字面量，默认 int 型，即 0x00000001
     * 将其强转为无符号 char 即截断为 0x01
     * 对其求非时，先被提升为 int，执行 0 位扩展，即 0x00000001
     * 然后求非，即 0xFFFFFFFE+1 = 0xFFFFFFFF
     */
    int c = -(unsigned char)0x1;
    printf("%x\n", c);

    /*
     * 0x1 是字面量，默认 int 型，即 0x00000001
     * 将其强转为 char 即截断为 0x01
     * 对其求非时，先被提升为 int, 执行符号位扩展，因为符号位是 0，得到 0x00000001
     * 然后求非，即 0xFFFFFFFE+1 = 0xFFFFFFFF
     */
    int d = -(char)0x1;
    printf("%x\n", d);

    /*
     * 0x80 是字面量，默认 int 型，即 0x00000080
     * 将其强转为 char ，即 0x80
     * 对其求非时，先被提升为 int, 执行符号位扩展，得到 0xFFFFFF80
     * 然后求非，得到 0x0000007F+1 = 0x00000080
     */
    int e = -(char)0x80;
    printf("%x\n", e);
}
