/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:10:23 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"

int	node_size(t_astree *ast)
{
	t_astree	*tmp;
	int			size;

	size = 0;
	tmp = ast;
	while (tmp)
	{
		size++;
		tmp = tmp->right;
	}
	return (size);
}

char	**make_cmd(t_astree *ast)
{
	char		**cmd;
	t_astree	*node;
	int			index;

	if (!ast->data)
		return (0);
	index = 0;
	node = ast;
	index = node_size(node);
	s_malloc((void **)&cmd, sizeof(char *) * (index + 1));
	index = 0;
	while (node)
	{
		s_malloc((void **)&(cmd[index]),
			sizeof(char) * (ft_strlen(node->data) + 1));
		ft_strlcpy(cmd[index], node->data, ft_strlen(node->data) + 1);
		node = node->right;
		index++;
	}
	cmd[index] = 0;
	return (cmd);
}

char	**parse_envp(char *target)
{
	int		i;
	char	*path;
	int		length;

	i = 0;
	while (g_envp[i])
	{
		path = ft_strnstr(g_envp[i], target, (ft_strlen(target) + 1));
		if (path == g_envp[i])
			break ;
		i++;
	}
	length = 0;
	while (g_envp[length])
		length++;
	if (length == i)
		return (0);
	return (ft_split(&(g_envp[i][5]), ':'));
}

char	*valid_cmd(char *arg_cmd, char **path)
{
	int		i;
	char	*path_cmd;
	char	*cmd;

	cmd = NULL;
	if (path == 0)
		return (NULL);
	path_cmd = ft_strjoin("/", arg_cmd);
	i = 0;
	while (path[i])
	{
		cmd = ft_strjoin(path[i], path_cmd);
		if (is_exist_file(cmd))
		{
			free(path_cmd);
			free2(path);
			return (cmd);
		}
		free(cmd);
		i++;
	}
	free(path_cmd);
	free2(path);
	return (NULL);
}

void	find_cmd(char ***cmd_list, t_cmd *cmd_line)
{
	char	*cmd;

	cmd = NULL;
	if (*cmd_list && !ft_strchr((*cmd_list)[0], '/'))
	{
		cmd = valid_cmd((*cmd_list)[0], parse_envp("PATH="));
		if (cmd && cmd_line->is_builtin == false)
		{
			free((*cmd_list)[0]);
			(*cmd_list)[0] = cmd;
		}
		else
			free(cmd);
	}
}
