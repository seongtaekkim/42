/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_waitpid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:02:25 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	do_waitpid(t_astree *ast, int *exit_code)
{
	int	state;

	if (!ast)
		return ;
	do_waitpid(ast->left, exit_code);
	if (ast->after_meta == AST_PIPE
		&& ast->type != AST_OR && ast->type != AST_AND)
	{
		waitpid(ast->pid, &state, 0);
	}
	do_waitpid(ast->right, exit_code);
}

void	execute_waitpid_to_status(t_astree *ast, int *exit_code)
{
	int	state;

	if (waitpid(ast->pid, &state, 0))
	{
		if (WIFEXITED(state))
			*(exit_code) = WEXITSTATUS(state);
		else if (WIFSIGNALED(state))
			*(exit_code) = WTERMSIG(state) + SIGNALOFFSET;
	}
}

void	execute_waitpid(t_astree *ast, int *exit_code, t_cmd *cmd_line)
{
	int	state;

	if (cmd_line->is_builtin == true)
		return ;
	if (!(ast->after_meta == AST_PIPE)
		&& !(ast->after_meta == AST_AND) && !(ast->after_meta == AST_OR))
	{
		if (ast->is_last || ast->before_meta == AST_OR
			|| ast->before_meta == AST_AND || ast->before_meta == AST_PIPE)
		{
			execute_waitpid_to_status(ast, exit_code);
		}
		else
			waitpid(ast->pid, &state, 0);
	}
}
