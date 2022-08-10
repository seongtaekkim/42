/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_p_proc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:56:27 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/10 14:03:49 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	proc_parent_last(t_arg *arg, int i)
{
	if (i % 2 == 0)
		close(arg->pipe_odd[PIPE_R]);
	else
		close(arg->pipe_even[PIPE_R]);
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
	waitpid(*pid, NULL, WNOHANG);
	return (0);
}
