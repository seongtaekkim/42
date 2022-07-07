/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:47:31 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/07 14:54:00 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	int		index;
	size_t	size;
	size_t	length;

	size = ft_strlen(s);
	if (start > size || (len <= 0 && start != 0))
	{
		arr = (char *)malloc(sizeof(char));
		arr[0] = '\0';
		return (arr);
	}
	if (size - start < len)
		length = size - start;
	else
		length = len;
	index = 0;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	while (len-- > 0)
		arr[index++] = s[start++];
	arr[index] = '\0';
	return (arr);
}
