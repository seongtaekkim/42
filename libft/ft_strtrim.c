/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:59:06 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/07 16:08:45 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int	index;
	int	index2;
	int	size;

	size = ft_strlen(s1);
	index = 0;
	index2 = 0;
	while (s1[index])
	{
		index2 = 0;
		while (set[index2])
		{
			if (s1[index] != set[index2])
				break ;
			index++;
			index2++;
		}
	}
	printf("%c \n",s1[index]);
	return ((char *)s1 + index);
}

int	main(void)
{
	printf("%s ",ft_strtrim("abcabckkk","abc"));
}
