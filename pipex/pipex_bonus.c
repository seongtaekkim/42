#include <stdio.h>
#include "pipex.h"

typedef struct	s_arg
{
	int		pipe_num;
	int		pipe_even[2];
	int		pipe_odd[2];
	char	*cmd;
	char	**cmd_arg;
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

int	parse_argv(char **argv, t_arg *arg, int i)
{
	arg->cmd_arg = ft_split(argv[i+2], ' ');
	if (arg->cmd_arg == NULL)
		return (1);
	arg->cmd = is_valid_cmd(arg, arg->cmd_arg[0]);
	if (arg->cmd == NULL)
	{
		perror("command not found");
		exit(127);
	}
	return (0);
}

int	init(int argc, char **argv, char **envp, t_arg **arg)
{
	if (argc < 4)
		return (1);
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if ((*arg) == NULL)
		return (1);
	(*arg)->infile = ft_strdup(argv[1]);
	(*arg)->outfile = ft_strdup(argv[argc - 1]);
	(*arg)->pipe_num = argc - 3;
	if ((*arg)->infile == NULL || (*arg)->outfile == NULL)
		return (1);
	if ((parse_envp(&((*arg)->cmd_envp), envp)) == 1)
		return (1);
	return (0);
}

int	open_infile(t_arg *arg)
{
	int	fd;
	int	r_fd;

	fd = open(arg->infile, O_RDONLY);
	if (fd == -1)
		return (1);
	r_fd = dup2(fd, STDIN_FILENO);
		close(fd);
	if (r_fd == -1)
		return (1);
	return (0);
}

int	open_outfile(t_arg *arg)
{
	int	fd;
	int	w_fd;

	fd = open(arg->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	w_fd = dup2(fd, STDOUT_FILENO);
	close(fd);
	if (w_fd == -1)
		return (1);
	return (0);
}

int	pipex(int *pid, t_arg *arg, char **envp, int i)
{
	if (*pid < 0)
		return (1);
	else if (!*pid)
	{
		if (i == 0)
		{
			if (open_infile(arg) == 1)
				return (1);
			close(arg->pipe_even[PIPE_R]);
			int w_fd = dup2(arg->pipe_even[PIPE_W], STDOUT_FILENO);
			close(arg->pipe_even[PIPE_W]);
			if (w_fd == -1)
				return (1);
			if (i == arg->pipe_num - 1)
			{
				if (open_outfile(arg) == 1)
					return (1);
			}
		}
		else if(i == arg->pipe_num - 1)
		{
			if (open_outfile(arg) == 1)
				return (1);
			if (i % 2 == 0)
			{
				int w_fd = dup2(arg->pipe_odd[PIPE_R], STDIN_FILENO);
				close(arg->pipe_odd[PIPE_R]);
				if (w_fd == -1)
					return (1);
			}
			else
			{
				int w_fd = dup2(arg->pipe_even[PIPE_R], STDIN_FILENO);
				close(arg->pipe_even[PIPE_R]);
				if (w_fd == -1)
					return (1);
			}
		}
		else if (i != 0 && i % 2 == 0)
		{
			int w_fd = dup2(arg->pipe_odd[PIPE_R], STDIN_FILENO);
			close(arg->pipe_odd[PIPE_R]);
			if (w_fd == -1)
				return (1);

			close(arg->pipe_even[PIPE_R]);
			w_fd = dup2(arg->pipe_even[PIPE_W], STDOUT_FILENO);
			close(arg->pipe_even[PIPE_W]);
			if (w_fd == -1)
				return (1);
		}
		else if (i != 0 && i % 2 == 1)
		{
			//close(pipe_fd[PIPE_W]);
			int w_fd = dup2(arg->pipe_even[PIPE_R], STDIN_FILENO);
			close(arg->pipe_even[PIPE_R]);
			if (w_fd == -1)
				return (1);
			w_fd = dup2(arg->pipe_odd[PIPE_W], STDOUT_FILENO);
			close(arg->pipe_odd[PIPE_W]);
			if (w_fd == -1)
				return (1);
		}
		
		if (execve(arg->cmd, arg->cmd_arg, envp) == -1)
			return (1);
	}
	else if(*pid > 0)
	{
		//wait(NULL);
		if (i == 0)
		{
			close(arg->pipe_even[PIPE_W]);
		}
		else if (i == arg->pipe_num - 1)
		{

			if (i % 2 == 0)
			{
			close(arg->pipe_odd[PIPE_W]);
			close(arg->pipe_even[PIPE_R]);
			}
			else
			{
			close(arg->pipe_even[PIPE_W]);
			close(arg->pipe_odd[PIPE_R]);
			}
		}
		else if (i % 2 == 0)
		{
			close(arg->pipe_even[PIPE_W]);
			close(arg->pipe_odd[PIPE_R]);
		}
		else
		{
			close(arg->pipe_odd[PIPE_W]);
			close(arg->pipe_even[PIPE_R]);
		}
		//wait(NULL);
		waitpid(*pid, NULL, WNOHANG);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg *arg;
	pid_t	pid;
	int		i;

	if (init(argc, argv, envp, &arg) == 1)
		exit(1);
	i = -1;
	while (++i < arg->pipe_num)
	{
		parse_argv(argv, arg, i);
		if (i % 2 == 0)
			if (pipe(arg->pipe_even) == -1)
				exit(1);
		if (i % 2 == 1)
			if (pipe(arg->pipe_odd) == -1)
				exit(1);
		pid = fork();
		if (pid == -1)
		{
			//close(pipe_fd[PIPE_R]);
			//close(pipe_fd[PIPE_W]);
			exit(1);
		}
		if (pipex(&pid, arg, envp, i) == 1)
			exit(1);
	}
	return (0);
}
