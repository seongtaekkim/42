/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:04:37 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"

void	pipe_parent(t_cmd *cmd_line, t_astree *ast, int *local_fd)
{
	if (dup2(cmd_line->bak_stdout, STDOUT_FILENO) == -1)
		exit (1);
	if (dup2(cmd_line->bak_stdin, STDIN_FILENO) == -1)
		exit (1);
	if (dup2(cmd_line->bak_stderr, STDERR_FILENO) == -1)
		exit (1);
	if (ast->before_meta == AST_PIPE && ast->after_meta == AST_PIPE)
	{
		close(cmd_line->fd[0]);
		close(local_fd[1]);
	}
	else if (ast->after_meta == AST_PIPE)
	{
		close(local_fd[1]);
	}
	else if (ast->before_meta == AST_PIPE)
	{
		close(cmd_line->fd[0]);
	}
	cmd_line->fd[0] = local_fd[0];
	cmd_line->fd[1] = local_fd[1];
}

void	pipe_child2(t_cmd *cmd_line, int *local_fd)
{
	if (!(cmd_line->redirin))
		if (dup2(cmd_line->fd[0], STDIN_FILENO) == -1)
			exit (1);
	close(cmd_line->fd[0]);
	close(local_fd[0]);
	if (!(cmd_line->redirout))
		if (dup2(local_fd[1], STDOUT_FILENO) == -1)
			exit (1);
	close(local_fd[1]);
}

void	pipe_child(t_cmd *cmd_line, t_astree *ast, int *local_fd)
{
	open_infile(cmd_line->redirin, cmd_line->is_parent);
	open_outfile(cmd_line->redirout, cmd_line->is_parent);
	if (ast->before_meta == AST_PIPE && ast->after_meta == AST_PIPE)
		pipe_child2(cmd_line, local_fd);
	else if (ast->before_meta == AST_PIPE)
	{
		if (!(cmd_line->redirin))
			if (dup2(cmd_line->fd[0], STDIN_FILENO) == -1)
				exit (1);
		close(cmd_line->fd[0]);
	}
	else if (ast->after_meta == AST_PIPE)
	{
		close(local_fd[0]);
		if (!(cmd_line->redirout))
			if (dup2(local_fd[1], STDOUT_FILENO) == -1)
				exit (1);
		close(local_fd[1]);
	}
}
