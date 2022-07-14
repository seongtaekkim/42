/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:06:00 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/14 12:10:35 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *line)
{
	char	*buf;
	ssize_t	n;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (line)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		line = ft_strnjoin(line, buf, n);
		if (n < BUFFER_SIZE)
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

char	*get_line(t_holder *node, char *line)
{
	char	*find;
	char	*temp;

	if (!line || !*line)
	{
		free(line);
		(node->prev)->next = node->next;
		if (node->next)
			(node->next)->prev = node->prev;
		free(node);
		return (NULL);
	}
	find = ft_strchr(line, '\n');
	if (find)
	{
		node->line = ft_strndup(find + 1, ft_strlen(find + 1));
		temp = ft_strndup(line, find - line + 1);
		free(line);
		return (temp);
	}
	return (line);
}

t_holder	*create_node(t_holder *head, int fd)
{
	t_holder	*node;

	node = head->next;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_holder *)malloc(sizeof(t_holder));
	if (!node)
		return ((void *)0);
	node->fd = fd;
	node->line = ft_strndup("", 0);
	node->next = head->next;
	node->prev = head;
	head->next = node;
	if (node->next)
		(node->next)->prev = node;
	return (node);
}

char	*get_next_line(int fd)
{
	static t_holder	head;
	t_holder		*now;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return ((void *)0);
	now = create_node(&head, fd);
	//if (now->line == NULL)
	//	return (NULL);
	line = now->line;
	now->line = (void *)0;
	line = read_file(fd, line);
	line = get_line(now, line);
	return (line);
}
