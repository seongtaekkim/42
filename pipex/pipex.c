#include "pipex.h"


void	p_exit(char *str, int code)
{
	perror(str);
	exit(code);
}

int	parse_envp(char ***ptr, char **envp)
{
	int		i;
	char	*path;

	i =0;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH=", 6);
		if (path == envp[i])
			break ;
		free(path);
		i++;
	}
	(*ptr) = ft_split(&(envp[i][5]), ':');
	return (0);
}

char	*is_valid_cmd(t_arg *arg, char *arg_cmd)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*cmd;

	path_cmd = ft_strjoin("/", arg_cmd);
	fd = 0;
	i = 0;
	fd = access(path_cmd, X_OK);
	if (fd != -1)
		return (path_cmd);
	while (arg->cmd_envp[i])
	{
		cmd = ft_strjoin(arg->cmd_envp[i], path_cmd);
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
	arg->cmd_arg = ft_split2(argv[i+2], ' ', '\'');
	if (arg->cmd_arg == NULL)
		p_exit("command not found", 127);
	arg->cmd = is_valid_cmd(arg, arg->cmd_arg[0]);
	if (arg->cmd == NULL)
		p_exit("command not found", 127);
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
	(*arg)->pipe_num = 2;
	if ((*arg)->infile == NULL || (*arg)->outfile == NULL)
		p_exit("not exist file", 1);
	if ((parse_envp(&((*arg)->cmd_envp), envp)) == 1)
		return (1);
	return (0);
}

int	open_infile(t_arg *arg)
{
	int		fd;
	int		r_fd;

	fd = open(arg->infile, O_RDONLY);
	if (fd == -1)
		p_exit("fail open file", 1);
	r_fd = dup2(fd, STDIN_FILENO);
	close(fd);
	if (r_fd == -1)
		p_exit("fail dup", 1);
	return (0);
}

int	open_outfile(t_arg *arg)
{
	int	fd;
	int	w_fd;

	fd = open(arg->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		p_exit("fail open file", 1);
	w_fd = dup2(fd, STDOUT_FILENO);
	close(fd);
	if (w_fd == -1)
		p_exit("fail dup", 1);
	return (0);
}

void	proc_parent_last(t_arg *arg)
{
	close(arg->pipe_even[PIPE_R]);
	close(arg->pipe_odd[PIPE_R]);
	close(arg->pipe_odd[PIPE_W]);
}

int	proc_parent(int *pid, t_arg *arg, int i)
{		
	if (i == 0)
		close(arg->pipe_even[PIPE_W]);
	else if (i == arg->pipe_num - 1)
		proc_parent_last(arg);
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
	waitpid(*pid, NULL, WNOHANG);
	return (0);
}

int	proc_child_first(t_arg *arg)
{
	int	w_fd;

	open_infile(arg);
	close(arg->pipe_even[PIPE_R]);
	w_fd = dup2(arg->pipe_even[PIPE_W], STDOUT_FILENO);
	close(arg->pipe_even[PIPE_W]);
	if (w_fd == -1)
		return (1);
	return (0);
}

int	proc_child_last(t_arg *arg)
{
	int	fd;
	open_outfile(arg); 
	close(arg->pipe_odd[PIPE_W]);
	close(arg->pipe_odd[PIPE_R]);
	fd = dup2(arg->pipe_even[PIPE_R], STDIN_FILENO);
	close(arg->pipe_even[PIPE_R]);
	if (fd == -1)
		return (1);
	return (0);
}

void	close_pipe(t_arg *arg, int i)
{
	close(arg->pipe_even[PIPE_R]);
	close(arg->pipe_even[PIPE_W]);
	if (i > 0)
	{
		close(arg->pipe_odd[PIPE_R]);
		close(arg->pipe_odd[PIPE_W]);
	}
}

int	pipex(int *pid, t_arg *arg, char **envp, int i)
{
	int	ret;

	ret = 0;
	if (*pid < 0)
	{
		close_pipe(arg, i);
		return (1);
	}
	else if (!*pid)
	{
		if (i == 0)
			ret = proc_child_first(arg);
		else if(i == arg->pipe_num - 1)
			ret = proc_child_last(arg);
		if (ret == 1)
			return (1);
		if (execve(arg->cmd, arg->cmd_arg, envp) == -1)
			return (1);
	}
	else if(*pid > 0)
		if (proc_parent(pid, arg, i) == 1)
			return (1);
	return (0);
}

void	cmd_free(t_arg *arg)
{
	int	i;

	i = 0;
	free(arg->cmd);
	while (arg->cmd_arg[i])	
	{
		free(arg->cmd_arg[i]);
		i++;
	}
	free(arg->cmd_arg);
}

void	arg_free(t_arg *arg)
{
	int	i;

	i = 0;
	free(arg->infile);
	free(arg->outfile);
	while (arg->cmd_envp[i])
	{
		free(arg->cmd_envp[i]);
		i++;
	}
	free(arg->cmd_envp);
	free(arg);
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
		if (i % 2 == 0 && pipe(arg->pipe_even) == -1)
			exit(1);
		if (i % 2 == 1 && pipe(arg->pipe_odd) == -1)
			exit(1);
		pid = fork();
		if (pipex(&pid, arg, envp, i) == 1)
			exit(1);
		cmd_free(arg);
	}
	arg_free(arg);	
	return (0);
}
