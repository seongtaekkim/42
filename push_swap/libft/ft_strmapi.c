/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:23:11 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 09:23:22 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*arr;
	size_t	size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if (size == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	index = 0;
	while (s[index])
	{
		arr[index] = f(index, s[index]);
		index++;
	}
	arr[index] = '\0';
	return (arr);
}
