#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage : %s <string>", argv[0]);
        exit(1);
    }
    /*
     * argv[1] = "welcome to masm!";
     */
    for (int i = 0; i < strlen(argv[1]); i++) {
        printf("%c - %2x\n", argv[1][i], argv[1][i]);
    }
}
