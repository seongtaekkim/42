/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:03:54 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/10 16:03:27 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_gnl(int fd, char *line)
{
    char    *buf;
    ssize_t n;
    
	buf = malloc(sizeof(char) * BUFFER_SIZE);
    if (!buf)
        return (NULL);
    while (line || !(ft_strchr(line, '\n')))
    {
        n = read(fd, buf, BUFFER_SIZE);
        if (n <= 0)
            break ;
        printf("buf : %s\n", buf);
	//	line = ft_strnjoin(line, buf, n);
		printf("awegawegawge\n");        
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

char	*get_next_line(int fd)
{
	static t_holder	head;
    //t_gnl           *now;
    char            *line;
	
	line = ft_strdup("");
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    //now = make_lst(&head, fd);
    //line = now->line;
    //now->line = NULL;
    line = read_gnl(fd, line);
    //line = updat_gnl(now, line);
    return (line);
}
