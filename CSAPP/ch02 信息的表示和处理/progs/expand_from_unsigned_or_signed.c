#include <stdio.h>
#include <inttypes.h>
#include "../../bin_tool.h"

int main(int argc, char *argv[])
{
    unsigned i = 0x80000000;
    uint64_t j = i;

    printf("%s\n", i64(j));
}
