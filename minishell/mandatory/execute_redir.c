/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:06:19 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_redir	*new_redir(t_astree *ast)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	redir->filename = ft_strdup((ast)->data);
	redir->type = (ast)->type;
	redir->next = 0;
	return (redir);
}

void	append_redir_back(t_redir **head, t_redir *new)
{
	t_redir	*tail;

	if (!(*head))
		*head = new;
	else
	{
		tail = *head;
		while (tail->next)
			tail = tail->next;
		tail->next = new;
	}
}

void	set_redirect(t_astree **ast, t_cmd **cmd)
{
	t_cmd		*bak;
	t_astree	*tmp;
	t_redir		*tmp_redir;

	bak = *cmd;
	tmp = *ast;
	while (tmp)
	{
		tmp_redir = new_redir(tmp);
		if (tmp->type == AST_REDIRECT_IN)
			append_redir_back(&((*cmd)->redirin), tmp_redir);
		else if (tmp->type == AST_REDIRECT_OUT || tmp->type == AST_APPEND)
			append_redir_back(&((*cmd)->redirout), tmp_redir);
		tmp = tmp->right;
	}
	*cmd = bak;
}

int	open_infile(t_redir *redir, t_bool is_parent)
{
	int		fd;
	int		r_fd;
	t_redir	*tmp;

	tmp = redir;
	fd = 0;
	r_fd = 0;
	while (redir)
	{
		if (redir->type == AST_REDIRECT_IN)
			fd = open(redir->filename, O_RDONLY);
		if (fd == -1 && !exit_print(redir->filename, is_parent))
			return (0);
		if (fd)
		{
			r_fd = dup2(fd, STDIN_FILENO);
			close(fd);
			if (r_fd == -1 && !exit_print(redir->filename, is_parent))
				return (0);
		}
		redir = redir->next;
	}
	redir = tmp;
	return (1);
}

int	open_outfile(t_redir *redir, t_bool is_parent)
{
	int				fd;
	int				w_fd;
	const t_redir	*tmp = redir;

	fd = 0;
	w_fd = 0;
	while (redir)
	{
		if (redir->type == AST_REDIRECT_OUT)
			fd = open(redir->filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
		else if (redir->type == AST_APPEND)
			fd = open(redir->filename, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd == -1 && !exit_print(redir->filename, is_parent))
			return (0);
		if (fd != 1)
		{
			w_fd = dup2(fd, STDOUT_FILENO);
			close(fd);
			if (w_fd == -1 && !exit_print(redir->filename, is_parent))
				return (0);
		}
		redir = redir->next;
	}
	redir = (t_redir *)tmp;
	return (1);
}
