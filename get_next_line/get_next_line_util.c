/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:04:52 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/10 15:53:49 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*dest;
	char	*result;

	length = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (length + 1));
	if (!dest)
		return (0);
	result = dest;
	while (*s1)
	{
		*dest++ = *s1;
		s1++;
	}
	*dest = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strnjoin(char *s1, char *s2, ssize_t n)
{
	char	*result;
	size_t	index;
	size_t	s1_len;
	size_t	s2_len;
	
	if (!s1 || !s2 || n < 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len == 0 && s2_len == 0)
	{
		result = (char *)malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	index = 0;
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	while (*s1)
		result[index++] = *s1++;
	while (*s2)
		result[index++] = *s2++;
	result[index] = '\0';
	return (result);
}
