/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:01:54 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/08 16:34:25 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*old;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	new = new_list;
	old = lst->next;
	while (1)
	{
		if (old == NULL)
			break ;
		new->next = ft_lstnew((*f)(old->content));
		if (!(new->next))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new = new->next;
		old = old->next;
	}
	return (new_list);
}
