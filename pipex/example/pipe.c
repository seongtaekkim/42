#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define P_READ		0
#define P_WRITE		1
#define BUFFER_SIZE	4096

void	childcommand(void)
{
	int		ret;
	char	buffer[BUFFER_SIZE];
	ret = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	//printf("buffer : %s\n", buffer);
	write(STDOUT_FILENO, buffer, strlen(buffer));
}

void	childproc(int pipe[2])
{
	int		fd;
	int		r_fd;
	int		w_fd;

	printf("child proc\n");
	close(pipe[P_READ]);
	printf("child pipe : %d\n",pipe[P_WRITE]);
	w_fd = dup2(pipe[P_WRITE], STDOUT_FILENO);
	close(pipe[P_WRITE]);
	if (w_fd == -1)
		exit(1);
	fd = open("read.txt", O_RDONLY);
	if (fd == -1)
		exit(1);
	r_fd = dup2(fd, STDIN_FILENO);
	close(fd);
	if (r_fd == -1)
		exit(1);
	childcommand();
}

void	parentcommand(void)
{
	int		ret;
	char	buffer[BUFFER_SIZE];
	ret = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));
}

void	parentproc(int pipe[2], pid_t pid)
{
	int	fd;
	int	r_fd;
	int	w_fd;

	printf("parent proc\n");	
	close(pipe[P_WRITE]);
	r_fd = dup2(pipe[P_READ], STDIN_FILENO);
	close(pipe[P_READ]);
	if (r_fd == -1)
		exit(1);
	fd = open("write.txt", O_WRONLY);
	if (fd == -1)
		exit(1);
	w_fd = dup2(fd, STDOUT_FILENO);
	close(fd);
	if (w_fd == -1)
	{
		exit(1);
	}
	if (waitpid(pid, NULL, 0) == -1)
	{
		printf("wait exit\n");
		exit(1);
	}
		parentcommand();
}

int	main(void)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (1);
	printf("parent; read fd : %d, fd write : %d\n", fd[P_READ], fd[P_WRITE]);
	pid = fork();
	if (pid == -1)
	{
		close(fd[P_READ]);
		close(fd[P_WRITE]);
		return (1);
	}
	else if (!pid)
		childproc(fd);
	else
		parentproc(fd, pid);
	return (0);

}
