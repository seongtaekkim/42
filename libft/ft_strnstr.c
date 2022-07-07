/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:24:45 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/07 13:42:51 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle,  size_t len)
{
	const char	*do_find;

	do_find = needle;
	if (*do_find == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len-- > 0)
	{
		if (*do_find == *haystack)
			do_find++;
		else
			do_find = needle;
		haystack++;
		if (*do_find == '\0')
			break ;
	}
	if (len == 0 && *do_find != '\0')
		return (NULL);
	if (ft_strlen(needle) != (size_t)(do_find - needle))
		return (NULL);
	while ((do_find - needle) > 0)
	{
		haystack--;
		do_find--;
	}
	return ((char *)haystack);
}
