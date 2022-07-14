/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:06:00 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/14 17:17:40 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *line)
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

void	free_node(t_holder *node)
{
	(node->prev)->next = node->next;
	if (node->next)
		(node->next)->prev = node->prev;
	free(node);
	node = NULL;
}

char	*get_line_one(t_holder *node, char *line)
{
	char	*find;
	char	*temp;

	if (!line || !(*line))
	{
		free(line);
		free_node(node);
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
	t_holder		*curr_node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return ((void *)0);
	curr_node = create_node(&head, fd);
	line = curr_node->line;
	curr_node->line = NULL;
	line = read_file(fd, line);
	line = get_line_one(curr_node, line);

	return (line);
}
