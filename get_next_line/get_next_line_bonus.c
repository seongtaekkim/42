/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:19:56 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/15 19:25:23 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static void	free_node(t_holder *node)
{
	(node->prev)->next = node->next;
	if (node->next)
		(node->next)->prev = node->prev;
	free(node);
	node = NULL;
}

static char	*get_line_one(t_holder *node, char *line)
{
	char	*sp;
	char	*ret_line;

	sp = ft_strchr(line, '\n');
	if (sp)
	{
		node->line = ft_strndup(sp + 1, ft_strlen(sp + 1));
		ret_line = ft_strndup(line, sp - line + 1);
		free(line);
		return (ret_line);
	}
	return (line);
}

static t_holder	*create_node(t_holder *head, int fd)
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
		return (NULL);
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
		return (NULL);
	curr_node = create_node(&head, fd);
	line = curr_node->line;
	curr_node->line = NULL;
	line = read_file(fd, line);
	if (!line || !(*line))
	{
		free(line);
		free_node(curr_node);
		return (NULL);
	}
	line = get_line_one(curr_node, line);
	return (line);
}
