/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:54:29 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/07 12:16:43 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*strt;

	strt = NULL;
	while (*s)
	{
		if (*s == (char)c)
			strt = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (strt);
}
