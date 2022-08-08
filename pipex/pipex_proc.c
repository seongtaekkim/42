/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:29:34 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 16:11:24 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

	fd = 0;
	open_outfile(arg);
	close(arg->pipe_odd[PIPE_W]);
	close(arg->pipe_odd[PIPE_R]);
	fd = dup2(arg->pipe_even[PIPE_R], STDIN_FILENO);
	close(arg->pipe_even[PIPE_R]);
	if (fd == -1)
		return (1);
	return (0);
}
