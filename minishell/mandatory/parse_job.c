/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:33:07 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_astree	*job(t_token **cursor)
{
	t_token		*save;
	t_astree	*ast;

	save = *cursor;
	if (term(cursor, AST_PARENTHESES_C, NULL))
		return (NULL);
	ast = job1(cursor);
	if (ast != NULL)
		return (ast);
	*cursor = save;
	ast = job3(cursor, AST_AND);
	if (ast != NULL)
		return (ast);
	*cursor = save;
	ast = job3(cursor, AST_OR);
	if (ast != NULL)
		return (ast);
	*cursor = save;
	ast = job2(cursor);
	if (ast != NULL)
		return (ast);
	return (NULL);
}

t_astree	*job1(t_token **cursor)
{
	t_astree	*cmd_node;
	t_astree	*job_node;
	t_astree	*ast;

	cmd_node = cmd(cursor);
	if (cmd_node == NULL)
		return (NULL);
	if (!term(cursor, AST_PIPE, NULL))
	{
		delete_node_ast(cmd_node);
		return (NULL);
	}
	job_node = job(cursor);
	if (job_node == NULL)
	{
		delete_node_ast(cmd_node);
		return (NULL);
	}
	s_malloc((void **)&ast, sizeof(*ast));
	set_type_ast(ast, AST_PIPE);
	set_data_ast(ast, NULL);
	attach_node_ast(ast, cmd_node, job_node);
	return (ast);
}

t_astree	*job2(t_token **cursor)
{
	return (cmd(cursor));
}

t_astree	*job3(t_token **cursor, int ast_type)
{
	t_astree	*cmd_node;
	t_astree	*job_node;
	t_astree	*ast;

	cmd_node = cmd(cursor);
	if (cmd_node == NULL)
		return (NULL);
	if (!term(cursor, ast_type, NULL))
	{
		delete_node_ast(cmd_node);
		return (NULL);
	}
	job_node = job(cursor);
	if (job_node == NULL)
	{
		delete_node_ast(cmd_node);
		return (NULL);
	}
	s_malloc((void **)&ast, sizeof(*ast));
	set_type_ast(ast, ast_type);
	set_data_ast(ast, NULL);
	attach_node_ast(ast, cmd_node, job_node);
	return (ast);
}
