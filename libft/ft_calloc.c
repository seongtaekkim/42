/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:07:10 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/10 16:55:49 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*obj;

	if (size == 0 || count == 0)
	{
		size = 1;
		count = 1;
	}
	if (((count * size) / size) != count)
		return (NULL);
	obj = malloc(0);
	if (!obj)
		return (NULL);
	ft_memset(obj, 0, count * size);
	return (obj);
}
