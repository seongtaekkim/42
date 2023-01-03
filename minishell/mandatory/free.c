/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:41:36 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	free2(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while ((str[i]))
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_str(t_str *c)
{
	t_str	*next;

	while (c)
	{
		next = c->next;
		free(c);
		c = next;
	}
}

void	free_token(t_token *token)
{
	t_token	*next;

	if (!token)
		return ;
	while (token)
	{
		next = token->next;
		free_str(token->t_str);
		free(token);
		token = next;
	}
}

void	free_redir(t_redir *redir)
{
	t_redir	*tmp;

	if (!redir)
		return ;
	while (redir)
	{
		free(redir->filename);
		tmp = redir;
		redir = redir->next;
		free(tmp);
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free_redir(cmd->redirin);
	free_redir(cmd->redirout);
}
