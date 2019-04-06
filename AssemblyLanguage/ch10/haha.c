#include <stdio.h>

int main(int argc, char *argv[])
{
    int max = 0;
    int max_1 = 0;
    int max_2 = 0;
    int rem = 0;
    for (int H = 1; H < 0xFFFF; H++) { 
        for (int N = 1; N < 0xFFFF; N++) {
            if (H < N)  
                continue;
            rem = H % N; 
            if (rem > max) {
                max = rem;
                max_1 = H;
                max_2 = N;
            }
        }
    }
    printf("%d %% %d = %d\n", max_1, max_2, max);
}
