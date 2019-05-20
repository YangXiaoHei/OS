#include <stdio.h>
#include <string.h>
#include "../../bin_tool.h"

int main(int argc, char *argv[])
{
    printf("%d\n", (1.1 + 1.2) == 2.3);
    printf("%d\n", (1.1f + 1.2f) == 2.3f);

    printf("1.1f        %s\n", f32(1.1f));
    printf("1.2f        %s\n", f32(1.2f));
    printf("1.1f + 1.2f %s\n", f32(1.1f + 1.2f));
    printf("2.3f        %s\n", f32(2.3f));

    printf("\n");

    printf("1.1         %s\n", d64(1.1));
    printf("1.2         %s\n", d64(1.2));
    printf("1.1 + 1.2   %s\n", d64(1.1 + 1.2));
    printf("2.3         %s\n", d64(2.3));
}
