#include <stdio.h>

float fun(double x, float y, int a, long b)
{
    return x / (y + a) - b;
}

double funct(double a, float x, double b, int i)
{
    return a * x - b / i;
}

int main(int argc, char *argv[])
{
   printf("%.2f\n", fun(3.14, 9.56, 1000, 200));
}
