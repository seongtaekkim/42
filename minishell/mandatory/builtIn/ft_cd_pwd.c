/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:15:11 by susong            #+#    #+#             */
/*   Updated: 2023/01/03 13:21:59 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

//https://man7.org/linux/man-pages/man1/cd.1p.html

int	no_operand(void)
{
	char	*home_path;

	home_path = 0;
	home_path = get_envp("HOME=");
	if (!home_path)
	{
		s_writeln(2, "shell: cd : HOME not set");
		return (1);
	}
	if (chdir(home_path) == -1)
	{
		s_write(2, "shell: cd: No such file or directory\n");
		return (1);
	}
	return (0);
}

void	ft_cd(char **path, int *exit_code)
{
	int		index;
	int		err_code;

	index = ft_strlen2_ncon(path);
	err_code = 0;
	if (index > 1)
	{
		s_write(2, "shell: cd: 인자가 너무 많음\n");
		return ;
	}
	if (path[0] == 0)
		err_code = no_operand();
	else
	{
		if (chdir(*path) == -1)
		{
			cd_err_print(0, *path);
			err_code = 1;
		}
	}
	(*exit_code) = err_code;
	return ;
}

void	ft_cd_exit(char **path, int *exit_code)
{
	int		index;
	int		err_code;

	err_code = 0;
	index = ft_strlen2_ncon(path);
	if (index > 1)
	{
		s_write(2, "shell: cd: 인자가 너무 많음\n");
		exit (1);
	}
	if (path[0] == 0)
		err_code = no_operand();
	else
	{
		if (chdir(*path) == -1)
		{
			cd_err_print(0, *path);
			err_code = 1;
		}
	}
	(*exit_code) = err_code;
	exit (0);
}

void	ft_pwd(char **cmd, int *exit_code)
{
	char	path_max[4096];

	(void)cmd;
	s_write(1, getcwd(path_max, 4096));
	s_write(1, "\n");
	(*exit_code) = 0;
	return ;
}

void	ft_pwd_exit(char **cmd, int *exit_code)
{
	char	path_max[4096];

	(void)cmd;
	s_write(1, getcwd(path_max, 4096));
	s_write(1, "\n");
	(*exit_code) = 0;
	exit(0);
}
