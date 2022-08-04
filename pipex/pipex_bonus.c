#include <stdio.h>
#include "pipex_bonus.h"

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
	int		heredoc;
	char	*heredoc_exit;
}	t_arg;

int	parse_envp(char ***ptr, char **envp)
{
	int		i;
	char	*path;
	i =0;
	while (envp[i])
	{
		//printf("envp : %s\n", envp[i]);
		path = ft_strnstr(envp[i], "PATH=", 6);
		if (path == envp[i])
			break ;
		free(path);
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
	if (arg->heredoc)
		arg->cmd_arg = ft_split2(argv[i+3], ' ', '\'');
	else
		arg->cmd_arg = ft_split2(argv[i+2], ' ', '\'');
	if (arg->cmd_arg == NULL)
		return (1);
	arg->cmd = is_valid_cmd(arg, arg->cmd_arg[0]);
	if (arg->cmd == NULL)
	{
		perror("command not found");
		//exit(127);
	}
	return (0);
}

int	open_here_doc(t_arg *arg)
{
	int		fd;
	char	*str;

	fd = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (!fd)
		return (1);
	while (1)
	{
		write(1, "pipex heredoc> ", 16);
		str = get_next_line(0);
		if (!str)
			break ;
		if (ft_strncmp(arg->heredoc_exit, str, ft_strlen(arg->heredoc_exit)) == 0)
			break ;
		write(fd, str, ft_strlen(str));
		free(str);
	}
	free(str);
	close(fd);
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
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		(*arg)->heredoc = 1;
		(*arg)->heredoc_exit = ft_strdup(argv[2]);
	}
	else
		(*arg)->heredoc = 0;
	if ((*arg)->heredoc)
		(*arg)->pipe_num = argc - 4;
	else
		(*arg)->pipe_num = argc - 3;
	if ((*arg)->infile == NULL || (*arg)->outfile == NULL)
		return (1);
	if ((parse_envp(&((*arg)->cmd_envp), envp)) == 1)
		return (1);
	if ((*arg)->heredoc)
		open_here_doc(*arg);
	return (0);
}

int	open_infile(t_arg *arg)
{
	int		fd;
	int		r_fd;

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

void	proc_parent_last(t_arg *arg, int i)
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

int	proc_parent(int *pid, t_arg *arg, int i)
{		
	if (i == 0)
		close(arg->pipe_even[PIPE_W]);
	else if (i == arg->pipe_num - 1)
		proc_parent_last(arg, i);
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
	return (0);
}

int	proc_child_first(t_arg *arg)
{
	int	w_fd;

	if (open_infile(arg) == 1)
		return (1);
	close(arg->pipe_even[PIPE_R]);
	w_fd = dup2(arg->pipe_even[PIPE_W], STDOUT_FILENO);
	close(arg->pipe_even[PIPE_W]);
	if (w_fd == -1)
		return (1);
	if (arg->pipe_num - 1 == 0)
		if (open_outfile(arg) == 1)
			return (1);
	return (0);
}

int	proc_child_last(t_arg *arg, int i)
{
	int	w_fd;

	if (open_outfile(arg) == 1)
		return (1);
	if (i % 2 == 0)
	{
		w_fd = dup2(arg->pipe_odd[PIPE_R], STDIN_FILENO);
		close(arg->pipe_odd[PIPE_R]);
		if (w_fd == -1)
			return (1);
	}
	else
	{
		w_fd = dup2(arg->pipe_even[PIPE_R], STDIN_FILENO);
		close(arg->pipe_even[PIPE_R]);
		if (w_fd == -1)
			return (1);
	}
	return (0);
}

int	proc_child_even(t_arg *arg)
{
	int	r_fd;
	int	w_fd;

	r_fd = dup2(arg->pipe_odd[PIPE_R], STDIN_FILENO);
	close(arg->pipe_odd[PIPE_R]);
	if (r_fd == -1)
		return (1);
	close(arg->pipe_even[PIPE_R]);
	w_fd = dup2(arg->pipe_even[PIPE_W], STDOUT_FILENO);
	close(arg->pipe_even[PIPE_W]);
	if (w_fd == -1)
		return (1);
	return (0);
}

int	proc_child_odd(t_arg *arg)
{
	int	w_fd;
	int	r_fd;

	r_fd = dup2(arg->pipe_even[PIPE_R], STDIN_FILENO);
	close(arg->pipe_even[PIPE_R]);
	if (r_fd == -1)
		return (1);
	w_fd = dup2(arg->pipe_odd[PIPE_W], STDOUT_FILENO);
	close(arg->pipe_odd[PIPE_W]);
	if (w_fd == -1)
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
			ret = proc_child_last(arg, i);
		else if (i % 2 == 0)
			ret = proc_child_even(arg);
		else if (i % 2 == 1)
			ret = proc_child_odd(arg);
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

void	do_exit(int code, t_arg **arg)
{
	free(*arg);
	exit(code);
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
	if (arg->heredoc)
		free(arg->heredoc_exit);
	free(arg);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg *arg;
	pid_t	pid;
	int		i;

	if (init(argc, argv, envp, &arg) == 1)
		do_exit(1, &arg);
	i = -1;
	while (++i < arg->pipe_num)
	{
		parse_argv(argv, arg, i);
		if (i % 2 == 0 && pipe(arg->pipe_even) == -1)
				do_exit(1, &arg);
		if (i % 2 == 1 && pipe(arg->pipe_odd) == -1)
				do_exit(1, &arg);
		pid = fork();
		if (pipex(&pid, arg, envp, i) == 1)
			do_exit(1, &arg);
		cmd_free(arg);
	}
	if (arg->heredoc && unlink(arg->infile) == -1)
		do_exit(1, &arg);
	arg_free(arg);	
	return (0);
}
