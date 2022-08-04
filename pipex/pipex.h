/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:06:37 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/23 17:37:09 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include  <sys/wait.h>
#include <stdio.h>

# define PIPE_R 0
# define PIPE_W 1

typedef struct	s_arg
{
	int		pipe_num;
	int		pipe_even[2];
	int		pipe_odd[2];
	char	*cmd;
	char	**cmd_arg;
	char	*infile;
	char	*outfile;
	char	**cmd_envp;
}	t_arg;

//int		parse_argv(char **argv, t_arg *arg);
int		parse_envp(char ***ptr, char **envp);
char	**ft_split(char const *s, char c);
char	**ft_split2(char const *s, char c, char c2);
void change_flag(const char **str, char c2, int *flag);
int	next_word(const char **str, char c, char c2, int *flag);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
