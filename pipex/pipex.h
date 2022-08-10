/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:06:37 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/10 14:27:41 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"
# define PIPE_R 0
# define PIPE_W 1

typedef struct s_arg
{
	int		pipe_num;
	int		pipe_even[2];
	int		pipe_odd[2];
	char	*cmd;
	char	**cmd_arg;
	char	*infile;
	char	*outfile;
	char	**cmd_envp;
	int		exit_code;
}	t_arg;

int		parse_envp(char ***ptr, char **envp);
int		open_infile(t_arg *arg);
int		open_outfile(t_arg *arg);
int		parse_argv(char **argv, t_arg *arg, int i);
void	cmd_find_error(t_arg *arg);
void	p_exit(char *str, int code);
void	close_pipe(t_arg *arg, int i);
void	cmd_free(t_arg *arg);
void	arg_free(t_arg *arg);
void	proc_parent_last(t_arg *arg);
int		proc_parent(int *pid, t_arg *arg, int i);
int		proc_child_first(t_arg *arg);
int		proc_child_last(t_arg *arg);
int		parse_envp(char ***ptr, char **envp);
#endif
