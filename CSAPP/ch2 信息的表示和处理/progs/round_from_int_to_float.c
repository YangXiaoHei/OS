#include <stdio.h>
#include "bin_tool.h"

int main(int argc, char *argv[])
{
    /*
     * 这个数字是 float 无法精确表示的最小正整数, 大于等于该数字的值，都无法用 float 精确表示
     */
    int a = toi32("1 00000000 00000000 0000000 1");
    printf("%d\n", a);

    /*
     * 将该 int 值转为 float, 产生舍入，观察下面单精度浮点的尾数，发现为全 0，因为第 24 位的 1 向偶数舍入时被丢弃了
     */
    float b = a;
    printf("%s\n", f32(a));

    /*
     * 将 float 值再转回 int 会发现，已经物是人非，不再是当年那个他
     */
    int c = b;
    printf("%d\n", c);
}
