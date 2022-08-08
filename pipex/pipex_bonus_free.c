/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:56:23 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 16:16:34 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	close_pipe(t_arg *arg, int i)
{
	close(arg->pipe_even[PIPE_R]);
	close(arg->pipe_even[PIPE_W]);
	if (i > 0)
	{
		close(arg->pipe_odd[PIPE_R]);
		close(arg->pipe_odd[PIPE_W]);
	}
	return (1);
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
