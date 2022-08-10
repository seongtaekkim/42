/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_setting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:56:32 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/10 14:18:34 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	parse_envp(char ***ptr, char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH=", 6);
		if (path == envp[i])
			break ;
		free(path);
		i++;
	}
	(*ptr) = ft_split(&(envp[i][5]), ':');
	return (0);
}

char	*is_valid_cmd(t_arg *arg, char *arg_cmd)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*cmd;

	path_cmd = ft_strjoin("/", arg_cmd);
	i = 0;
	fd = access(path_cmd, X_OK);
	if (fd != -1)
		return (path_cmd);
	while (arg->cmd_envp[i])
	{
		cmd = ft_strjoin(arg->cmd_envp[i], path_cmd);
		fd = access(cmd, X_OK);
		if (fd != -1)
		{
			free(path_cmd);
			return (cmd);
		}
		close(fd);
		free(cmd);
		i++;
	}
	free(path_cmd);
	return (NULL);
}

int	parse_argv(char **argv, t_arg *arg, int i)
{
	if (arg->heredoc)
		arg->cmd_arg = ft_split2(argv[i + 3], ' ', '\'');
	else
		arg->cmd_arg = ft_split2(argv[i + 2], ' ', '\'');
	arg->cmd = is_valid_cmd(arg, arg->cmd_arg[0]);
	return (0);
}

int	open_infile(t_arg *arg)
{
	int		fd;
	int		r_fd;

	fd = open(arg->infile, O_RDONLY);
	if (fd == -1)
		p_exit("fail open file", 1);
	r_fd = dup2(fd, STDIN_FILENO);
	close(fd);
	if (r_fd == -1)
		p_exit("fail dup", 1);
	return (0);
}

int	open_outfile(t_arg *arg)
{
	int	fd;
	int	w_fd;

	if (arg->heredoc)
		fd = open(arg->outfile, O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(arg->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		p_exit("fail open file", 1);
	w_fd = dup2(fd, STDOUT_FILENO);
	close(fd);
	if (w_fd == -1)
		p_exit("fail dup", 1);
	return (0);
}
