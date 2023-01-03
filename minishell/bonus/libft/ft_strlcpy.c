/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:18:53 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/06 17:40:27 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	src_size;

	index = 0;
	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (dstsize != 0)
	{
		while (src[index] != '\0' && (dstsize -1) > index)
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (src_size);
}
