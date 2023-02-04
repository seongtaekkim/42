/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:01:42 by susong            #+#    #+#             */
/*   Updated: 2023/02/03 13:07:57 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
		((unsigned char *)b)[index++] = c;
	return (b);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 != '\0' || *s2 != '\0') && n > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (1);
}

void	free2(char **arg)
{
	int	index;

	index = 0;
	while (arg[index])
	{
		free(arg[index]);
		index++;
	}
	if (arg)
		free(arg);
	return ;
}

int	is_space(char c)
{
	int	flag;

	flag = (c == ' ' || c == '\n' || c == '\r');
	flag += (c == '\t' || c == '\v' || c == '\f');
	return (flag);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
