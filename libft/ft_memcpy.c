/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:45:39 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/06 16:52:42 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	if (dst == NULL && src == NULL)
		return (NULL);
	index = 0;
	while (index < n)
	{
		((unsigned char*)dst)[index] = ((unsigned char*)src)[index];
		index++;
	}
	return (dst);
}
