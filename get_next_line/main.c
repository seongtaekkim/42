#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int st_read_map(const char *filename)
{
    int fd;
    int i;
	char	*line;

    i = -1;
    fd = open(filename, O_RDONLY);
    printf("fd : %d\n",fd);
	
	while (fd)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		printf("%s", line);
		free(line);
		if (!line)
			break ;
	}
    return (fd);
}

int main(int argc, char **argv)
{
	int		index;

	index = 1;
    if (argc == 1)
        printf("File name missing.\n");
    else
    {
		while (argc > index)
        	st_read_map(argv[index++]);
    }
    return (0);
}
