#include <stdio.h>
#include <string.h>
#include <unistd.h>

void why_run_here(void)
{
    #define yxh_str "why run here\n"
    write(STDOUT_FILENO, yxh_str, strlen(yxh_str));
}

void my_call(void)
{
    long buf[3];
    buf[0] = 1;
    buf[1] = 2;
    buf[5] = (long)why_run_here;
}

int main(int argc, char *argv[])
{
    my_call();
}
