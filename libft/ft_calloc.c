/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:07:10 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 08:12:46 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*obj;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (((count * size) / size) != count)
		return (NULL);
	obj = malloc(count * size);
	if (!obj)
		return (NULL);
	ft_memset(obj, 0, count * size);
	return (obj);
}
