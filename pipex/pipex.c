
#include <stdio.h>
#include "pipex.h"

typedef struct	s_arg
{
	char	*cmd1;
	char	*cmd2;
	char	**cmd_arg1;
	char	**cmd_arg2;
	char	*infile;
	char	*outfile;
	char	**cmd_envp;
}	t_arg;

int	parse_envp(char ***ptr, char **envp)
{
	int	i;

	i =0;
	while (envp[i])
	{
		//printf("envp : %s\n", envp[i]);
		if ((ft_strnstr(envp[i], "PATH=", 6) == envp[i]))
			break ;
		i++;
	}
	//if ((i == ft_veclen((char **)envp)) || ft_veclen((char **)envp) == 1)
	//	return (1);
	//printf("%c\n", envp[i][5]);
	(*ptr) = ft_split(&(envp[i][5]), ':');
	//printf("ptr : %s\n", *ptr[0]);
	//printf("ptr : %s\n", (*ptr)[1]);
	//printf("ptr : %s\n", (*ptr)[2]);
	return (0);
}

char	*is_valid_cmd(t_arg *arg, char *arg_cmd)
{
	int	i;
	int	fd;
	char	*path_cmd;
	char	*cmd;

	path_cmd = ft_strjoin("/", arg_cmd);
	//printf("cmd : %s\n", path_cmd);
	fd = 0;
	i = 0;
	fd = access(path_cmd, X_OK);
	if (fd != -1)
		return (path_cmd);
	while (arg->cmd_envp[i])
	{
		cmd = ft_strjoin(arg->cmd_envp[i], path_cmd);
		//printf("in cmd : %s\n",cmd);
		fd = access(cmd, X_OK);
		if (fd != -1)
		{
			free(path_cmd);
			return (cmd);
		}
		close(fd);
		free(cmd);
		i++;
	}
	free(path_cmd);
	return (NULL);
}

int	parse_argv(char **argv, t_arg *arg)
{
	arg->cmd_arg1 = ft_split(argv[2], ' ');
	if (arg->cmd_arg1 == NULL)
		return (1);
	arg->cmd_arg2 = ft_split(argv[3], ' ');
	if (arg->cmd_arg2 == NULL)
		return (1);
	arg->cmd1 = is_valid_cmd(arg, arg->cmd_arg1[0]);
	arg->cmd2 = is_valid_cmd(arg, arg->cmd_arg2[0]);
	if (arg->cmd1 == NULL || arg->cmd2 == NULL)
	{
		perror("command not found");
		exit(127);
	}
	return (0);
}

int	init(int argc, char **argv, char **envp, t_arg **arg)
{
	if (argc != 5)
		return (1);
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if ((*arg) == NULL)
		return (1);
	(*arg)->infile = ft_strdup(argv[1]);
	(*arg)->outfile = ft_strdup(argv[argc - 1]);
	//printf("infile : %s\n", (*arg)->infile);
	//printf("outfile : %s\n", (*arg)->outfile);
	if ((*arg)->infile == NULL || (*arg)->outfile == NULL)
		return (1);
	if ((parse_envp(&((*arg)->cmd_envp), envp)) == 1)
		return (1);
	if ((parse_argv(argv, *arg)) == 1)
		return (1);
	return (0);
}

int	pipex(int pipe_fd[2], int *pid, t_arg *arg, char **envp)
{
	int fd;
	//printf("pid : %d\n", *pid);
	if (*pid < 0)
		return (1);
	else if (!*pid)
	{
		close(pipe_fd[PIPE_R]);
		int w_fd = dup2(pipe_fd[PIPE_W], STDOUT_FILENO);
		close(pipe_fd[PIPE_W]);
		if (w_fd == -1)
			return (1);
		fd = open(arg->infile, O_RDONLY);
		//printf("pipex infile : %s\n", arg->infile);
		if (fd == -1)
			return (1);
		int r_fd = dup2(fd, STDIN_FILENO);
		close(fd);
		if (r_fd == -1)
			return (1);
		if (execve(arg->cmd1, arg->cmd_arg1, envp) == -1)
			return (1);
	}
	else if(*pid > 0)
	{
		//wait(NULL);
		waitpid(*pid, NULL, WNOHANG);
		close(pipe_fd[PIPE_W]);
		int r_fd = dup2(pipe_fd[PIPE_R], STDIN_FILENO);
		close(pipe_fd[PIPE_R]);
		if (r_fd == -1)
			return (1);
		fd = open(arg->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
		//printf("pipex outfile : %s\n", arg->outfile);
		if (fd == -1)
			return (1);
		int w_fd = dup2(fd, STDOUT_FILENO);
		close(fd);
		if (w_fd == -1)
			return (1);
		if (execve(arg->cmd2, arg->cmd_arg2, envp) == -1)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg *arg;
	int		pipe_fd[2];
	pid_t	pid;
	if (init(argc, argv, envp, &arg) == 1)
		exit(1);
	if (pipe(pipe_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
	{
		close(pipe_fd[PIPE_R]);
		close(pipe_fd[PIPE_W]);
		exit(1);
	}
	if (pipex(pipe_fd, &pid, arg, envp) == 1)
		exit(1);
	return (0);
}
