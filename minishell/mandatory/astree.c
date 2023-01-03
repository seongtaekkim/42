/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:55:37 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	attach_node_ast(t_astree *root, t_astree *left, t_astree *right)
{
	root->left = left;
	root->right = right;
}

void	set_type_ast(t_astree *ast, t_ast_type type)
{
	ast->type = type;
	ast->before_meta = 0;
	ast->after_meta = 0;
	ast->parentheses = 0;
	ast->subshell = NULL;
	ast->pid = 0;
}

void	set_data_ast(t_astree *ast, char *data)
{
	ast->data = data;
	if (ast->type == AST_CMDPATH)
		ast->is_last = false;
}

void	delete_node_ast(t_astree *ast)
{
	if (ast == NULL)
		return ;
	if (ast->data)
		free(ast->data);
	if (ast->subshell)
		delete_node_ast(ast->subshell);
	delete_node_ast(ast->left);
	delete_node_ast(ast->right);
	free(ast);
}
