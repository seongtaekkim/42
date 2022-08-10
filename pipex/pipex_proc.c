/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:29:34 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/10 14:02:48 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	proc_parent_last(t_arg *arg)
{
	close(arg->pipe_even[PIPE_R]);
}

int	proc_parent(int *pid, t_arg *arg, int i)
{	
	if (i == 0)
		close(arg->pipe_even[PIPE_W]);
	else if (i == arg->pipe_num - 1)
		proc_parent_last(arg);
	waitpid(*pid, NULL, WNOHANG);
	return (0);
}

int	proc_child_first(t_arg *arg)
{
	int	w_fd;

	close(arg->pipe_even[PIPE_R]);
	open_infile(arg);
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
	fd = dup2(arg->pipe_even[PIPE_R], STDIN_FILENO);
	close(arg->pipe_even[PIPE_R]);
	if (fd == -1)
		return (1);
	return (0);
}
