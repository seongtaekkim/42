#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define PIPE_R 0
#define PIPE_W 1

typedef struct	s_env
{
	char	*cmd;
	char	*cmd_envp;
}	t_env;

void	env_init(t_env *env, int argc, char **argv)
{
	
}

int	infile_proc(char *file)
{

}

int	outfile_proc(char *file)
{
	
}

void	pipex(int pipe_fd[2], pid_t *pid)
{
	if (!pid)
	{
	}
	else
	{
		waitpid(*pid, NULL, WNOHANG);
		close(pipe[PIPE_W);
		int r_fd = dup2(pipe[PIPE_R], STDIN_FILENO);
		close(piipe[PIPE_R]);
		if (r_fd == -1)
			exit(1);
		fd = open("write", O_WRONLY);
		if (fd == -1)
			exit(1);
		int w_fd = dup2(fd, STDOUT_FILENO);
		if (w_fd == -1)
			exit(1);
		execve(env->cmd2, env->cmd_arg2, envp);
		perror(env->cmd2);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	int		pipe_fd[2];
	pid_t	pid;
	// 1:readfile, 2:cmd1, 3:cmd2, 4:writefile
	// 1. envp 파싱
	if (argc != 5)
		return (0);
	env_init(env);
	if (pipe(pipe_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
	{
		close(pipe_fd[PIPE_R]);
		close(pipe_fd[PIPE_W]);
		exit(1);
	}
	if (pipex(pipe_fd, &pid) == -1)
		exit(1);
	return (0);
}
