/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:27:56 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"

t_astree	*find_redir(t_token **cursor, int index)
{
	t_astree	*new;
	char		*filename;
	const int	arr[4] = {AST_REDIRECT_IN, AST_REDIRECT_OUT, AST_APPEND, 0};
	t_token		*save;
	int			ret;

	save = *cursor;
	while (arr[++index])
	{
		*cursor = save;
		ret = term(cursor, arr[index], NULL);
		if (ret)
			break ;
	}
	if (!ret)
		return (NULL);
	if (!term(cursor, AST_DATA, &filename))
		return (NULL);
	s_malloc((void **)&new, sizeof(*new));
	set_type_ast(new, arr[index]);
	set_data_ast(new, filename);
	attach_node_ast(new, NULL, NULL);
	return (new);
}

static t_astree	*cmd1(t_token **cursor, t_astree *new, t_astree *right)
{
	t_astree	*node;
	t_astree	*tmp;

	node = single_cmd(cursor);
	if (node == NULL)
		return (NULL);
	new = find_redir(cursor, -1);
	if (new == NULL)
	{
		delete_node_ast(node);
		return (NULL);
	}
	right = new;
	tmp = node;
	while (1)
	{
		right->right = find_redir(cursor, -1);
		tmp = last_node(tmp);
		tmp->right = single_cmd(cursor);
		if (right->right == NULL || cursor == 0 || *cursor == NULL)
			break ;
		right = select_ast_or_right(right, right->right);
	}
	new->left = node;
	return (new);
}

static t_astree	*cmd2(t_token **cursor, t_astree *node,
	t_astree *new, t_astree *right)
{
	t_astree	*tmp;

	new = find_redir(cursor, -1);
	if (new == NULL)
		return (NULL);
	right = new;
	while (1)
	{
		if (node == NULL)
		{
			node = single_cmd(cursor);
			tmp = node;
		}
		else
		{
			tmp = last_node(tmp);
			tmp->right = single_cmd(cursor);
		}
		right->right = find_redir(cursor, -1);
		if (right->right == NULL || cursor == 0 || *cursor == NULL)
			break ;
		right = select_ast_or_right(right, right->right);
	}
	new->left = node;
	return (new);
}

t_astree	*cmd3(t_token **cursor)
{
	return (single_cmd(cursor));
}

t_astree	*cmd(t_token **cursor)
{
	t_token		*save;
	t_astree	*node;

	save = *cursor;
	node = cmd1(cursor, NULL, NULL);
	if (node != NULL)
		return (node);
	*cursor = save;
	node = cmd2(cursor, NULL, NULL, NULL);
	if (node != NULL)
		return (node);
	node = cmd3(cursor);
	return (node);
}
