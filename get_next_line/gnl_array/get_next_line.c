/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:06:00 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/15 19:25:16 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char	*read_file(int fd, char *line)
{
	char	*buf;
	ssize_t	n;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		line = ft_strnjoin(line, buf, n);
		if (n < BUFFER_SIZE || ft_strchr(line, '\n'))
			break ;
	}
	free(buf);
	if (n < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*line;
	char			*curr_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!line)
		line = ft_strndup("", 0);
	line = read_file(fd, line);
	if (!line || !(*line))
	{
		free(line);
		return (NULL);
	}

	// 한 줄 get
	char	*sp;
	sp = ft_strchr(line, '\n');
	if (sp)
	{
		curr_line = ft_strndup(line, sp - line + 1);
		line = ft_strndup(sp + 1, ft_strlen(sp + 1));		
		//free(line);
		return (curr_line);
	}
	return (line);
}
