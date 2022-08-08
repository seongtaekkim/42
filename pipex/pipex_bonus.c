/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:02:18 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 18:15:09 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		if (ft_strncmp(arg->heredoc_exit
				, str, ft_strlen(arg->heredoc_exit)) == 0)
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
	(*arg)->heredoc = 1;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		(*arg)->heredoc_exit = ft_strdup(argv[2]);
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
	(*arg)->exit_code = 0;
	return (0);
}

int	pipex(int *pid, t_arg *arg, char **envp, int i)
{
	int	ret;

	ret = 0;
	if (*pid < 0)
		return (close_pipe(arg, i));
	else if (!*pid)
	{
		if (i == 0)
			ret = proc_child_first(arg);
		else if (i == arg->pipe_num - 1)
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
	else if (*pid > 0)
		if (proc_parent(pid, arg, i) == 1)
			return (1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	*arg;
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
