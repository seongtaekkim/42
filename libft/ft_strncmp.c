/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:16:48 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/08 16:27:03 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 != '\0' || *s2 != '\0') && n - 1 > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (*(unsigned char *)s1 - *(unsigned char *)s2 > 0)
		return (1);
	else if (*(unsigned char *)s1 - *(unsigned char *)s2 < 0)
		return (-1);
	else
		return (0);
}
