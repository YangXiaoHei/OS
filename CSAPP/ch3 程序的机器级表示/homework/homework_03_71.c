#include <stdio.h>

void good_echo(void)
{
    char buf[4];
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        if (fputs(buf, stdout) == EOF) {
            if (ferror(stdout)) {
                fprintf(stderr, "fputs error!");
                break;
            }
        }
    }
    if (ferror(stdin)) {
        fprintf(stderr, "fgets error!");
    }
}

int main(int argc, char *argv[])
{
    good_echo();
}
