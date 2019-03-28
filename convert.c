#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("usage : %s <num> <10/16>", argv[0]);
        exit(1);
    }

    const char *fmt = argv[2];
    if (strcmp(fmt, "16") == 0) {
        printf("%ld\n", strtol(argv[1], NULL, 16));
    } else if (strcmp(fmt, "10") == 0) {
        printf("%lx\n", strtol(argv[1], NULL, 10));
    } else {
        printf("usage : %s <num> <10/16>", argv[0]);
    }

}

