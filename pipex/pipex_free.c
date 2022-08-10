/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:24:32 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/10 14:25:23 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_find_error(t_arg *arg)
{
	if (arg->cmd_arg == NULL)
		write(2, "pipex :command not found\n", 25);
	if (arg->cmd == NULL)
	{
		write(2, "pipex :command not found\n", 25);
		arg->exit_code = 127;
	}
}

void	p_exit(char *str, int code)
{
	perror(str);
	exit(code);
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
