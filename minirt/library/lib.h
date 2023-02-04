/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:21:41 by susong            #+#    #+#             */
/*   Updated: 2023/02/03 16:55:39 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# define BUFFER_SIZE 1024
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
// GNL
char	*get_next_line(int fd);
char	*extract_result(char *result, char *backup);
char	*absolute_enter(int fd, char *BUFFER, char *backup);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// SPLIT
char	**ft_split(char const *s, char c);

//library
void	*ft_memset(void *b, int c, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free2(char **arg);
float	ft_atof(const char *str, int *ascii);
int		ft_atoi(const char *str, int *ascii);
int		ft_strlen2(char **word);
int		is_space(char c);
int		ft_isdigit(int c);

#endif
