/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:14:36 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/07 19:21:35 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*head;
	t_list	*node;

	node = lst[0];
	head = ft_lstnew(new);
	if (node == NULL)
		*lst = head;
	else
	{
		head->next = node;
		*lst = head;
	}
}
