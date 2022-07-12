/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:07:10 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 14:30:20 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*obj;

	if (size != 0 && ((count * size) / size) != count)
		return (NULL);
	obj = malloc(count * size);
	if (!obj)
		return (NULL);
	ft_memset(obj, 0, count * size);
	return (obj);
}
