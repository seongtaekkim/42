/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:16:00 by susong            #+#    #+#             */
/*   Updated: 2023/01/03 13:21:59 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	ft_export(char **argument, int *exit_code)
{
	int		index;
	int		flag;
	int		skip;

	index = ft_strlen2_ncon(argument);
	skip = 0;
	if (index == 0)
		show_env_export();
	else
	{
		if (check_argument(argument, index, &flag))
		{
			s_write(1, "shell: export: ");
			s_write(1, argument[flag - 1]);
			s_write(1, ": not a valid idntifier\n");
			(*exit_code) = 1;
			return ;
		}
		index = 0;
		ft_export_util(&argument, &index, &skip, &exit_code);
		g_envp = copy_envp_export(argument, index - skip);
	}
	(*exit_code) = 0;
	return ;
}

void	ft_export_util(char ***argument, int *index, int *skip, int **exit_code)
{
	char	**temp_argument;
	char	**array;

	array = *argument;
	while (array[*index] != 0)
	{
		if (ft_find(array[*index], '=') == 1)
		{
			temp_argument = ft_split(array[*index], '=');
			free(temp_argument[1]);
			temp_argument[1] = 0;
			ft_unset(temp_argument, *exit_code);
			free(temp_argument[0]);
			free(temp_argument);
		}
		else if (ft_find_string(array[*index]) == 0)
			ft_unset(array, *exit_code);
		else
		{
			move_one(&array, *index);
			(*skip)++;
		}
		(*index)++;
	}
}

void	move_one(char ***argument, int temp)
{
	char	**array;

	array = *argument;
	if (array[temp])
		free(array[temp]);
	while (array[temp + 1])
	{
		array[temp] = array[temp + 1];
		temp++;
	}
	array[temp] = 0;
	return ;
}

void	ft_export_exit(char **argument, int *exit_code)
{
	int		index;
	int		flag;
	int		skip;

	index = ft_strlen2_ncon(argument);
	skip = 0;
	if (index == 0)
		show_env_export();
	else
	{
		if (check_argument(argument, index, &flag))
		{
			s_write(2, "shell: export: ");
			s_write(2, argument[flag - 1]);
			s_write(2, ": not a valid idntifier\n");
			(*exit_code) = 1;
			exit(1);
		}
		index = 0;
		ft_export_util(&argument, &index, &skip, &exit_code);
		g_envp = copy_envp_export(argument, index - skip);
	}
	(*exit_code) = 0;
	exit(0);
}

int	ft_find(char *argument, int c)
{
	int	index;

	index = 0;
	while (argument[index])
	{
		if (argument[index] == c)
			return (1);
		index++;
	}
	return (0);
}
