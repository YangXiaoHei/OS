#include <stdio.h>
#include <complex.h>

double fuck(double complex x)
{
    printf("%f\n", creal(x));
    return cimag(x) + creal(x);    
}

int main()
{
    double complex x = 1 + 3i;
    printf("%f+%fi\n", creal(x), cimag(x));
}
