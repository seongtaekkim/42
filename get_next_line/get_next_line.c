/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:03:54 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 19:07:05 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_file(int fd, char *line)
{
    char    *buf;
    ssize_t n;
    
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
    /*if (n < 0)
	{
        free(line);
        return (NULL);
    }*/
    return (line);
}

char    *get_line(t_gnl *node, char *line)
{
    char    *find;
    char    *temp;

    /*if (!line || !*line)
    {
        free(line);
        (node->prev)->next = node->next;
        if (node->next)
            (node->next)->prev = node->prev;
        free(node);
        return (NULL);
    }*/
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


/*
 * 1. fd가같지 않을 경우만 링크리스트 생성
 */
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
	node->fd = fd;
	node->line = ft_strdup("");
	node->next = head;
	head->prev = node;
	return (node);
}

char	*get_next_line(int fd)
{
	static t_holder	head;
    t_holder		*now;
    char            *line;
	
    if (fd < 0 || BUFFER_SIZE < 1)
        return ((void *)0);
	now = create_node(&head,fd);
	line = now->line;
	printf("line : %s\n", line);
	//now->line = (void *)0;
    line = read_file(fd, line);
    printf("retline : %s, %lu\n", line, ft_strlen(line));
	//line = get_line(now, line);
    return (line);
}
