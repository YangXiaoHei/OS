#include <stdio.h>
#include <inttypes.h>

unsigned signed_high_prod(int x, int y)
{
    int64_t q = (int64_t)x * y;
    return q >> 32;
}

/*
 * x' 代表无符号数, x 代表补码
 * x' = x + x(w-1) * 2^w
 * y' = y + y(w-1) * 2^w
 * 
 * x' * y' = (x + x(w-1) * 2^w) * (y + y(w-1) * 2^w)
 *         = [x * y + x * y(w-1) * 2^w + x(w-1) * 2^w * y + x(w-1) * y(w-1) * 2^2w ]
 *         
 *         此时取高 w 位，则整体模 2^w
 * 
 *         = (x * y) mod 2^w + x * y(w-1) + y * x(w-1) 
 *         = 补码高 w  位 + x * y(w-1) + y * x(w-1)
 */

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int sig_x = x >> 31;
    int sig_y = y >> 31;
    return signed_high_prod(x, y) + sig_x * y + sig_y * x;
}

unsigned another_unsigned_high_prod(unsigned x, unsigned y)
{
    uint64_t q = (uint64_t)x * y;
    return q >> 32;
}

int main(int argc, char *argv[])
{
    int x = 0x12345678;
    int y = 0x99998888;

    printf("%zd\n", unsigned_high_prod(x, y));
    printf("%zd\n", another_unsigned_high_prod(x, y)); 
}

