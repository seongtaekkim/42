/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:03:49 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"

void	s_malloc(void **ptr, size_t size)
{
	*ptr = (void *)malloc(size);
	if (!ptr)
		exit(1);
}

void	s_write(int fd, char *buf)
{
	if (buf == 0)
		return ;
	if (write(fd, buf, ft_strlen(buf)) == -1)
		exit(1);
}

void	s_writeln(int fd, char *buf)
{
	s_write(fd, buf);
	s_write(fd, "\n");
}

void	reverse_str(char *str)
{
	const int	len = ft_strlen(str);
	char		tmp;
	int			i;

	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
}

t_bool	is_exist_file(char *filename)
{
	struct stat	buf;

	if (stat(filename, &buf) == 0)
		return (true);
	return (false);
}
