/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:45:39 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/08 12:02:52 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_dst;

	if (!dst && !src)
		return (NULL);
	tmp_dst = dst;
	if (dst <= src)
	{
		while (len > 0)
		{
			*tmp_dst++ = *(unsigned char *)src++;
			len--;
		}
	}
	else
	{
		tmp_dst += len;
		src += len;
		while (len > 0)
		{
			*--tmp_dst = *(unsigned char *)--src;
			len--;
		}
	}
	return (dst);
}
