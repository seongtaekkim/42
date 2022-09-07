/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:06:37 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/30 16:58:12 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define BUFFER_SIZE 1024

typedef struct s_holder
{
	int				fd;
	char			*line;
	struct s_holder	*prev;
	struct s_holder	*next;
}	t_holder;

char	*get_next_line(int fd);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strnjoin(char *s1, char *s2, ssize_t n);
#endif
