/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:58:44 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:56:39 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	is_builtin_main(t_cmd *cmd_line, char *cmd)
{
	int			i;
	const char	*builtin_list[8] = {"pwd",
		"echo", "env", "exit", "export", "unset", "cd", 0};

	cmd_line->is_builtin = false;
	cmd_line->is_parent = false;
	if (!cmd)
		return ;
	i = 0;
	while (ft_strlen2(builtin_list) > i)
	{
		if (ft_strlen(cmd) == ft_strlen(builtin_list[i])
			&& ft_strncmp(builtin_list[i], cmd, ft_strlen(cmd)) == 0)
			cmd_line->is_builtin = true;
		i++;
	}
}

void	do_builtin_main_cmd(const char **builtin_list,
	char **cmd, void (*const builtin_cmd[7])(char **cmd, int *exit_code),
	int *exit_code)
{
	int	i;

	i = 0;
	while (ft_strlen2(builtin_list) > i)
	{
		if (ft_strlen(*(cmd)) == ft_strlen(builtin_list[i])
			&& ft_strncmp(builtin_list[i], *(cmd), ft_strlen(*(cmd))) == 0)
		{
			(builtin_cmd[i])(cmd + 1, exit_code);
			break ;
		}
		i++;
	}
}

int	execute_builtin_main_cmd_and_check(t_astree *ast,
	t_cmd *cmd_line, char **cmd, int *exit_code)
{
	const char			*builtin_list[8] = {"pwd",
		"echo", "env", "exit", "export", "unset", "cd", 0};
	static void (*const	builtin_cmd[7])(char **cmd, int *exit_code)
		= {ft_pwd, ft_echo, ft_env, ft_exit, ft_export, ft_unset, ft_cd};

	if (cmd_line->is_builtin == true
		&& (ast->after_meta != AST_PIPE && ast->before_meta != AST_PIPE))
	{
		cmd_line->is_parent = true;
		if (!open_infile(cmd_line->redirin, cmd_line->is_parent))
		{
			*exit_code = 1;
			return (1);
		}
		if (!open_outfile(cmd_line->redirout, cmd_line->is_parent))
		{
			*exit_code = 1;
			return (1);
		}
	}
	else
		return (0);
	do_builtin_main_cmd(builtin_list, cmd, builtin_cmd, exit_code);
	return (1);
}

void	execute_builtin_sub_cmd(char **cmd, int *exit_code)
{
	int					i;
	const char			*builtin_list[8] = {"pwd",
		"echo", "env", "exit", "export", "unset", "cd", 0};
	static void (*const	cmd_list[7])(char **cmd, int *exit_code)
		= {ft_pwd_exit, ft_echo_exit, ft_env_exit, ft_exit_exit,
		ft_export_exit, ft_unset_exit, ft_cd_exit};

	i = 0;
	while (ft_strlen2(builtin_list) > i)
	{
		if (ft_strlen(*cmd) == ft_strlen(builtin_list[i])
			&& ft_strncmp(builtin_list[i], *cmd, ft_strlen(*cmd)) == 0)
		{
			(cmd_list[i])(cmd + 1, exit_code);
		}
		i++;
	}
}
