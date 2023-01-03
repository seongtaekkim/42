/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 09:28:08 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"

t_str	*create_str(char c)
{
	t_str	*new;

	s_malloc((void **)&new, sizeof(t_str));
	if (new)
	{
		new->next = 0;
		new->c = c;
	}
	return (new);
}

void	append_str_back(t_str **head, t_str *new)
{
	t_str	*tail;

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

t_token	*create_token(t_str *str)
{
	t_token	*new;

	s_malloc((void **)&new, sizeof(t_token));
	if (new)
	{
		new->next = 0;
		new->t_str = str;
	}
	return (new);
}

void	append_token_back(t_token **head, t_token *new)
{
	t_token	*tail;

	if (new->t_str)
	{
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
}
