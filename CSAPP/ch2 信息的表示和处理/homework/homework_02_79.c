#include <stdio.h>

int mul3div4(int x)
{
    int w = sizeof(int) << 3;
    int mask = (x >> (w - 1));
    int bias = 3 & mask;
    return x - ((x + bias) >> 2);
}

int main(int argc, char *argv[])
{
    /*
     * 4
     * 15
     * 75
     * 51
     * -4
     * -15
     * -75
     * -51
     */
   printf("%d\n", mul3div4(5)); 
   printf("%d\n", mul3div4(20)); 
   printf("%d\n", mul3div4(100)); 
   printf("%d\n", mul3div4(67)); 
   printf("%d\n", mul3div4(-5)); 
   printf("%d\n", mul3div4(-20)); 
   printf("%d\n", mul3div4(-100)); 
   printf("%d\n", mul3div4(-67)); 
}
