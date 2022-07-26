#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	int		tmp;
	int		ret;
	char	buffer[4096];

	tmp = open("test.txt", O_RDONLY);
	fd = dup(tmp);
	close(tmp);
	if (fd == -1)
		return (1);
	ret = read(fd, buffer, 4096);
	close(fd);
	if (ret == -1)
		return (1);
	buffer[ret] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));
	return (0);
}
