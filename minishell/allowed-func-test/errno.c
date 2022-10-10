#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *err_msg;

    for (int i=0; i < 255 ; i++)
    {
        err_msg = strerror(i);
        printf("%d %s\n", i, err_msg);
    }
    return (0);
}