/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_cmd_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 08:52:34 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"

t_astree	*single_cmd2(t_token **cursor)
{
	t_astree	*node;
	t_astree	*new;
	char		*pathname;

	if (!term(cursor, AST_PARENTHESES_O, &pathname))
		return (NULL);
	s_malloc((void **)&new, sizeof(*new));
	set_type_ast(new, AST_PARENTHESES_O);
	set_data_ast(new, pathname);
	new->subshell = job(cursor);
	node = job(cursor);
	attach_node_ast(new, NULL, node);
	return (new);
}

t_astree	*single_cmd(t_token **cursor)
{
	t_token		*save;
	t_astree	*node;

	save = *cursor;
	node = single_cmd2(cursor);
	if (node != NULL)
		return (node);
	*cursor = save;
	node = single_cmd1(cursor);
	if (node != NULL)
		return (node);
	return (node);
}

t_astree	*single_cmd1(t_token **cursor)
{
	t_astree	*node;
	t_astree	*new;
	char		*pathname;

	if (!term(cursor, AST_DATA, &pathname))
		return (NULL);
	node = arg_list(cursor);
	s_malloc((void **)&new, sizeof(*new));
	set_type_ast(new, AST_CMDPATH);
	set_data_ast(new, pathname);
	attach_node_ast(new, NULL, node);
	return (new);
}

t_astree	*arg_list(t_token **cursor)
{
	t_astree	*node;

	node = arg_list1(cursor);
	if (node == NULL)
		return (NULL);
	return (node);
}

t_astree	*arg_list1(t_token **cursor)
{
	t_astree	*node;
	t_astree	*new;
	char		*arg;

	new = NULL;
	if (!term(cursor, AST_DATA, &arg))
		return (NULL);
	node = arg_list(cursor);
	s_malloc((void **)&new, sizeof(*new));
	set_type_ast(new, AST_ARGUMENT);
	set_data_ast(new, arg);
	attach_node_ast(new, NULL, node);
	return (new);
}
