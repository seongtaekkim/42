#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"


void	print(int fd)
{
	char	*line;
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		printf("%s", line);
		free(line);
		if (!line)
			break ;
	}
}
int st_read_map(const char *filename)
{
    int fd;
    int i;
	char	*line;

    i = -1;
    fd = open(filename, O_RDONLY);
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
	{
		print(0);
	}
	else
    {
		while (argc > index)
        	st_read_map(argv[index++]);
    }
    return (0);
}
