#include <stdio.h>

int main(int argc, char *argv[])
{
    /*
     * 3.140000
     * 0.000000
     * inf
     * 1e+20
     * 0.000000
     * nan
     */
    printf("%f\n", 3.14f + (1e10f - 1e10f));
    printf("%f\n", (3.14f + 1e10f) - 1e10f);

    printf("%g\n", (1e20f* 1e20f) * 1e-20f);
    printf("%g\n", 1e20f * (1e20f * 1e-20f ));

    printf("%f\n", 1e20f * (1e20f - 1e20f));
    printf("%f\n", 1e20f * 1e20f -  1e20f * 1e20f);
}
