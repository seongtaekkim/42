#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	int		tmp;
	int		ret;
	char	buffer[4096];

	tmp = open("test.txt", O_RDONLY);
	printf("tmp : %d\n", tmp);
	printf("fileno : %d\n", STDIN_FILENO);
	fd = dup2(tmp, STDIN_FILENO);
	printf("fd : %d\n", fd);
	close(tmp);
	if (fd == -1)
		return (1);
	ret = read(STDIN_FILENO, buffer, 4096);
	printf("fileno : %d\n", STDIN_FILENO);
	if (ret == -1)
		return (1);
	buffer[ret] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));
	printf("filenoout : %d\n", STDOUT_FILENO);
	return (0);
}
