#include <stdio.h>
#include <limits.h>

char complement_inverse(char a)
{
    /*
     * 补码的非等于对补码求反再加 1
     */
    return ~a + 1;
}

int main(int argc, char *argv[])
{
/*
 *     128
 *     128
 *     -128
 * 
 *     32768
 *     32768
 *     -32768
 * 
 *     -2147483648
 */
    char i = -127 - 1;

    /*
     * 一个思考：如果负号对 i 的作用是
     * 先把 char 型的 i 转为 -i，那么 -i  应该是 -128 (char 最小值)
     * 那么接下来当 %d 将其提升为 int 时，应该执行符号扩展，于是结果还是 -128，即 0xFFFFFF80
     * 可是打印出的结果是 128 即 0x00000080，这说明
     * 负号作用于 i 时，char 型的 i 先被提升为 int，即 0xFFFFFF80，这里执行了符号位扩展
     * 然后将其转为 -i，那么 -i 就是对 int 型补码取非，即 0x0000007F+1 = 0x00000080
     * 用 C 语言描述此过程为 -(int)i  
     */
    printf("%d\n", -i); 
    printf("%d\n", -(char)i);

    /*
     * 下面的转换结果依然是 0x00000080，但我们最后将其截断为 char，即 0x80
     * 那么当 %d 将其提升为 int 时，会执行符号扩展，即 0xFFFFFF80
     */
    printf("%d\n", (char)-i);
    printf("\n");

    /*
     * 上面描述的先提升为 int, 然后再执行补码取非操作对 char short 等小整型都适用
     */
    short j = -32767 - 1;
    printf("%d\n", -j);
    printf("%d\n", -(short)j);
    printf("%d\n", (short)-j);
    printf("\n");

    /*
     * 可以看到，由于 int 无需进行提升，所以直接对补码取非
     */
    int k = -2147483647 - 1;
    printf("%d\n", -k);
    printf("\n");

    int wrong = 0;
    /*
     * 如果在这里 i++，那么当 i 等于 127 时, i++ 使 i 溢出到 -128，因此 -128 <= 127，
     * 形成死循环
     */
    for (char i = -127 - 1; i <= 127;) {  
        /*
         * 这里的 -i 一定要强转，否则会被提升为 int，即当 -i 应该是 -128 时，被提升
         * 为 int 就变为了 128
         */
        if ((char)-i != complement_inverse(i)) {
            printf("i=%d %d != %d\n", i,  (char)-i, complement_inverse(i));
            wrong = 1;
        } 
        if (i == 127) break;
        ++i;
    }
    if (!wrong)
        printf("all correct!\n");
}
