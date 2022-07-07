/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:43:14 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/07 17:21:15 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	size;

	size = ft_strlen(s);
	if (fd == -1)
		return ;
	else
		write(fd, s, size);
	write(fd, "\n", 1);
}
