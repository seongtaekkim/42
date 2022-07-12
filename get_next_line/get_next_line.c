/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:03:54 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/12 19:47:15 by seongtki         ###   ########.fr       */
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
		line = ft_strjoin(line, buf);
		//buf = buf - BUFFER_SIZE;
		if (n < BUFFER_SIZE)
           break ;
	}	
    free(buf);
    if (n < 0)
	{
		printf("nullnull\n");
        free(line);
        return (NULL);
    }
    return (line);
}

char    *get_line(t_holder *node, char *line)
{
    char    *find;
    char    *temp;

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
        //printf("node->line : %s\n", node->line);
		temp = ft_strndup(line, find - line + 1);
		//printf("temp : %s, find-line+1 : %ld\n", temp, find-line+1);
        free(line);
        return (temp);
    }
    return (line);
}


/*
 * 1. fd가같지 않을 경우만 링크리스트 생성 (front create)
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
	node->line = ft_strndup("", 0);
	node->next = head;
	head->prev = node;
	
/*	if (head->fd == fd)
		return (head);
	head = (t_holder *)malloc(sizeof(t_holder));
	head->fd = fd;
	head->line = ft_strndup("", 0);
	*/
	return (head);
}

char	*get_next_line(int fd)
{
	static t_holder	head;
    t_holder		*now;
    char            *line;
    
	if (fd < 0 || BUFFER_SIZE < 1)
        return ((void *)0);
	printf("1");
	now = create_node(&head,fd);
	printf("2");
	if (now->line == NULL)
		return NULL;
	printf("3");	
	line = now->line;
	now->line = (void *)0;
    //printf("@storline : %s@\n", line);
	line = read_file(fd, line);
	//printf("$%s*",line);
	line = get_line(now, line);
	//printf("^%s&",line);
	head = *now;
	//printf("$now : %s$, $head : %s$\n", now->line, head.line);
    return (line);
}
