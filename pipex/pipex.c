/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:23:08 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 17:57:54 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		p_exit("invalid file name", 1);
	if ((parse_envp(&((*arg)->cmd_envp), envp)) == 1)
		return (1);
	(*arg)->exit_code = 0;
	return (0);
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
		else if (i == arg->pipe_num - 1)
			ret = proc_child_last(arg);
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
	return (arg->exit_code);
}
