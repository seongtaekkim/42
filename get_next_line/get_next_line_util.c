/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:04:52 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/13 08:43:04 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *s1, size_t n)
{
	//size_t	length;
	char	*dest;
	char	*result;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	result = dest;
	while (*s1 && n > 0)
	{
		*dest++ = *s1;
		s1++;
		n--;
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	if (dst == NULL && src == NULL)
		return (NULL);
	index = 0;
	while (index < n)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}

char	*ft_strnjoin(char *s1, char *s2, ssize_t n)
{
	char	*result;
	size_t	index;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2 || n <= 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = n;
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
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len);
	result[s1_len + s2_len] = '\0';
	return (result);
}
