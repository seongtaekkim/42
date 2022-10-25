#include "get_next_line.h"    
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    int rd = 0;
    int i = 0;
    char c;
    if (BUFFER_SIZE < 1)
        return (NULL);
    char *buf = malloc(10000);

    while ((rd = read(fd, &c, 1)) > 0)
    {
        buf[i++] = c;
        if (c == '\n')
            break ;
    }
    if ((!buf[i - 1] && !rd) || rd < 0)
    {
        free(buf);
        return (NULL);
    }
    buf[i] = '\0';
    return buf;
}

