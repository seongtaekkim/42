/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:43:14 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/09 17:20:48 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned char	*str;

	if (!s || fd == -1)
		return ;
	str = (unsigned char *)s;
	while (*str)
		ft_putchar_fd(*str++, fd);
	write(fd, "\n", 1);
}
