/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:28:28 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"

t_astree	*find_ast_and(t_astree *ast)
{
	t_astree	*tmp;

	tmp = ast;
	while (tmp->right)
	{
		tmp = tmp->right;
		if (tmp->type == AST_AND)
			return (tmp);
	}
	return (NULL);
}

t_astree	*after_and_or_check(t_astree *ast, int *exit_code)
{
	t_astree	*tmp;

	if ((ast->left->after_meta == AST_AND && *(exit_code)))
		return (NULL);
	if (ast->left->after_meta == AST_OR
		&& *exit_code == (SIGINT + SIGNALOFFSET))
		return (NULL);
	if ((ast->left->after_meta == AST_OR && !*(exit_code)))
	{
		tmp = find_ast_and(ast);
		if (!tmp)
			return (NULL);
		tmp->before_meta = ast->left->after_meta;
		ast = tmp;
	}
	return (ast);
}

void	execute_and_or(t_astree *ast, t_cmd *cmd_line, int *exit_code, int type)
{
	t_astree	*tmp;

	if (ast->left)
	{
		ast->left->before_meta = ast->before_meta;
		ast->left->after_meta = type;
		execute_cmd(ast->left, cmd_line, exit_code);
		if (cmd_line->is_parent == false)
			execute_waitpid_to_status(ast->left, exit_code);
		tmp = after_and_or_check(ast, exit_code);
		if (tmp == NULL)
			return ;
		ast = tmp;
	}
	if (ast->right)
	{
		ast->right->before_meta = type;
		execute_job(ast->right, cmd_line, exit_code);
	}
}

void	execute_job(t_astree *ast, t_cmd *cmd_line, int *exit_code)
{
	if (ast->type == AST_PIPE)
		execute_pipe(ast, cmd_line, exit_code);
	else if (ast->type == AST_AND)
		execute_and_or(ast, cmd_line, exit_code, AST_AND);
	else if (ast->type == AST_OR)
		execute_and_or(ast, cmd_line, exit_code, AST_OR);
	else
		execute_cmd(ast, cmd_line, exit_code);
}

void	execute(t_astree *ast, int *exit_code)
{
	t_cmd	cmd_line;

	cmd_line.seq = 0;
	cmd_line.bak_stdout = dup(STDOUT_FILENO);
	if (cmd_line.bak_stdout == -1)
		exit(1);
	cmd_line.bak_stdin = dup(STDIN_FILENO);
	if (cmd_line.bak_stdout == -1)
		exit(1);
	cmd_line.bak_stderr = dup(STDERR_FILENO);
	if (cmd_line.bak_stdout == -1)
		exit(1);
	execute_job(ast, &cmd_line, exit_code);
	do_waitpid(ast, exit_code);
}
