/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:15:32 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/09 17:19:05 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		index;
	size_t		dest_size;
	size_t		src_size;

	index = 0;
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize <= dest_size)
		return (src_size + dstsize);
	while (dst[index] != '\0')
		index++;
	while (*src != '\0' && (dstsize - 1) > index)
	{
		dst[index] = *src;
		index++;
		src++;
	}
	dst[index] = '\0';
	return (dest_size + src_size);
}
