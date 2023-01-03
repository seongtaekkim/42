/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:28:28 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	execute_process(t_astree *ast,
	t_cmd *cmd_line, int *exit_code, char **cmd_list)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (ast->subshell)
		execute_subshell(ast, exit_code);
	else
	{
		if (cmd_line->is_filename == true
			&& (cmd_line->redirin || cmd_line->redirout))
			exit_print(cmd_list[0], false);
		else if (!ft_strchr(cmd_list[0], '/'))
			exit_not_found(cmd_list[0]);
		else
		{
			execve(cmd_list[0], cmd_list, g_envp);
		}
	}
	exit_print(cmd_list[0], false);
}

void	execute_single_cmd(t_astree *ast, t_cmd *cmd_line, int *exit_code)
{
	char	**cmd_list;
	int		local_fd[2];

	cmd_list = make_cmd(ast);
	is_builtin_main(cmd_line, cmd_list[0]);
	find_cmd(&cmd_list, cmd_line);
	if (ast->after_meta == AST_PIPE)
		pipe(local_fd);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (!execute_builtin_main_cmd_and_check(ast, cmd_line, cmd_list, exit_code))
	{
		ast->pid = fork();
		if (ast->pid == 0)
		{
			pipe_child(cmd_line, ast, local_fd);
			execute_builtin_sub_cmd(cmd_list, exit_code);
			execute_process(ast, cmd_line, exit_code, cmd_list);
		}
	}
	pipe_parent(cmd_line, ast, local_fd);
	execute_waitpid(ast, exit_code, cmd_line);
	free2(cmd_list);
	free_cmd(cmd_line);
}

void	execute_cmd(t_astree *ast, t_cmd *cmd_line, int *exit_code)
{
	cmd_line->redirin = NULL;
	cmd_line->redirout = NULL;
	cmd_line->is_filename = false;
	if (ast->type == AST_REDIRECT_OUT
		|| ast->type == AST_APPEND || ast->type == AST_REDIRECT_IN)
	{
		set_redirect(&ast, &cmd_line);
		if (ast->left)
		{
			ast->left->after_meta = ast->after_meta;
			ast->left->before_meta = ast->before_meta;
			execute_single_cmd(ast->left, cmd_line, exit_code);
		}
		else
		{
			cmd_line->is_filename = true;
			execute_single_cmd(ast, cmd_line, exit_code);
		}
	}
	else
		execute_single_cmd(ast, cmd_line, exit_code);
}

void	execute_pipe(t_astree *ast, t_cmd *cmd_line, int *exit_code)
{
	if (ast->left)
	{
		ast->left->before_meta = ast->before_meta;
		ast->left->after_meta = AST_PIPE;
		execute_cmd(ast->left, cmd_line, exit_code);
	}
	if (ast->right)
	{
		ast->right->before_meta = AST_PIPE;
		execute_job(ast->right, cmd_line, exit_code);
	}
}

void	execute_subshell(t_astree *ast, int *exit_code)
{
	execute(ast->subshell, exit_code);
	exit(*(exit_code));
}
