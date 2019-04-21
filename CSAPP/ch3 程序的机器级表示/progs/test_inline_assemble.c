#include <stdio.h>

int exponet_of_2(int x, int y)
{
    int sum = 0;
    __asm__ (
                "label: addl %%eax, %%eax\n\t"
                "loop label\n\t"
                "movl %%eax, %0"
                : "=r" (sum)
                : "a" (x), "c" (y)
            );
    return sum;
}

int add(int x, int y)
{
    int sum = 0;
    __asm__ (
                "movl %1, %0\n\t"
                "addl %2, %0\n\t"
                : "=r" (sum)
                : "r" (x), "r" (y)
            );
    return sum;
}

int assign(void)
{
    int a = 10, b;
    __asm__  (
                "movl %1, %%eax\n\t"
                "movl %%eax, %0\n\t"
                : "=r" (b)
                : "r" (a)
                : "%eax"
             );
    return b;
}

int main(int argc, char *argv[])
{
    int a = 2, b = 5;
    printf("%d\n", assign());
    printf("%d\n", add(a, b));
    printf("%d\n", exponet_of_2(3, 4));
}
