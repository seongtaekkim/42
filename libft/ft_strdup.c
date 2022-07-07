/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:45:07 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/07 11:26:14 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*dest;
	char	*result;

	length = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (length + 1));
	if (!dest)
		return (0);
	result = dest;
	while (*s1)
		*dest++ = *s1++;
	*dest = '\0';
	return (result);
}
