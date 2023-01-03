/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_util_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:28:34 by nouswong          #+#    #+#             */
/*   Updated: 2023/01/03 13:58:45 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_bonus.h"

int	ft_find_string(char *argument)
{
	int			index;
	int			arg_index;
	const int	arg_size = ft_strlen(argument);
	const int	env_size = ft_strlen2_ncon(g_envp);

	index = 0;
	arg_index = 0;
	if (argument == 0)
		return (0);
	while (index < env_size)
	{
		if (g_envp[index][0] == argument[0])
		{
			while (argument[arg_index] && g_envp[index][arg_index] \
			&& g_envp[index][arg_index] == argument[arg_index])
				arg_index++;
		}
		if (arg_index == arg_size && (int)ft_strlen(g_envp[index]) > arg_size \
			&& g_envp[index][arg_index] == '=')
			return (1);
		index++;
	}
	return (0);
}

char	**copy_envp_export(char **argument, int add_size)
{
	const int	size = ft_strlen2((const char **)g_envp);
	int			i;
	int			index;
	char		**dest;

	i = 0;
	index = 0;
	s_malloc((void **)&dest, sizeof(char *) * (size + 1 + add_size));
	while (size > i)
	{
		*(dest + i) = ft_strdup(*(g_envp + i));
		i++;
	}
	while (index < add_size)
	{
		*(dest + i + index) = ft_strdup(argument[index]);
		index++;
	}
	*(dest + i + index) = 0;
	free2(g_envp);
	return (dest);
}

void	show_env_export(void)
{
	int		index;
	char	**target;

	index = 0;
	while (g_envp[index])
	{
		s_write(1, "declare -x ");
		if (ft_find(g_envp[index], '=') == 1)
		{
			target = ft_split(g_envp[index], '=');
			s_write(1, target[0]);
			s_write(1, "=\"");
			s_write(1, target[1]);
			s_write(1, "\"");
			free2(target);
		}
		else
			s_write(1, g_envp[index]);
		s_write(1, "\n");
		index++;
	}
	return ;
}

int	check_argument(char **argument, int max_argument, int *flag)
{
	int	index;
	int	target_index;
	int	return_flag;

	index = 0;
	return_flag = 0;
	while (index < max_argument)
	{
		target_index = 0;
		return_flag = check_argument_util(index, argument, target_index);
		if (return_flag != 0)
		{
			*flag = return_flag;
			return (1);
		}
		index++;
	}
	return (0);
}

int	check_argument_util(int index, char **argument, int target_index)
{
	int	equal_position;

	if (ft_find(argument[index], '=') == 1)
	{
		equal_position = -1;
		while (argument[index][target_index])
		{
			if (target_index == 0 && argument[index][target_index] == '=')
				return (index + 1);
			if (argument[index][target_index] == '=')
				equal_position = target_index;
			if (equal_position == -1 \
			&& !ft_isalpha(argument[index][target_index]))
				return (index + 1);
			target_index++;
		}
	}
	else
	{
		while (argument[index][target_index])
			if (!ft_isalpha(argument[index][target_index++]))
				return (index + 1);
	}
	return (0);
}
