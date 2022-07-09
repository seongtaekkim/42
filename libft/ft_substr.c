/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:47:31 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/09 17:49:55 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	index;
	size_t	size;
	size_t	length;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start > size || (len <= 0 && start != 0))
		return ((char *)ft_calloc(1, sizeof(char)));
	if (size - start < len)
		length = size - start;
	else
		length = len;
	index = 0;
	arr = (char *)malloc(sizeof(char) * (length + 1));
	if (!arr)
		return (NULL);
	while (length-- > 0)
	{
		arr[index++] = s[start];
		start++;
	}
	arr[index] = '\0';
	return (arr);
}
