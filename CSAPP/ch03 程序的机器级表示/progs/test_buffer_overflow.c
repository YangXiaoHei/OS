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
    buf[5] = (long)why_run_here;
}

void last_call(void)
{
    printf("hello world\n");
}

int main(int argc, char *argv[])
{
    argv = (long)last_call;
    my_call();
}
