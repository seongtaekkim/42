/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_c_proc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:56:15 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/10 14:00:23 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

	close(arg->pipe_even[PIPE_R]);
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

	close(arg->pipe_odd[PIPE_R]);
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
