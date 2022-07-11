/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:45:39 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 09:21:03 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;

	if (!dst && !src)
		return (NULL);
	tmp_dst = dst;
	if (dst <= src)
	{
		while (len-- > 0)
		{
			*tmp_dst = *(unsigned char *)src++;
			tmp_dst++;
		}
	}
	else
	{
		tmp_dst += len;
		src += len;
		while (len-- > 0)
		{
			--tmp_dst;
			*tmp_dst = *(unsigned char *)--src;
		}
	}
	return (dst);
}
