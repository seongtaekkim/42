/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:28:28 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"

t_astree	*last_node(t_astree *node)
{
	t_astree	*tmp;

	tmp = node;
	while (tmp->right)
		tmp = tmp->right;
	return (tmp);
}

t_astree	*select_ast_or_right(t_astree *ast, t_astree *right)
{
	if (right != NULL)
		return (right);
	return (ast);
}
