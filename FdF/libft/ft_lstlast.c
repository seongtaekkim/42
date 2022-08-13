/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 08:38:56 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 08:04:12 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (1)
		{
			if (lst->next == NULL)
				return (lst);
			lst = lst->next;
		}
	}
	return (NULL);
}
