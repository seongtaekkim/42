/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:23:11 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/08 16:31:46 by seongtki         ###   ########.fr       */
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
	{
		arr = (char *)malloc(sizeof(char));
		arr[0] = '\0';
		return (arr);
	}
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
