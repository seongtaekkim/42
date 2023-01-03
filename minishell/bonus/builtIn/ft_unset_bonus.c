/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:05:22 by nouswong          #+#    #+#             */
/*   Updated: 2023/01/03 13:58:45 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_bonus.h"

// static int *make_target(char **argument, int **delete_target)
// {

// }
static char	**copy_envp_exclude(char **envp, int *target, int target_size)
{
	const int	size = ft_strlen2((const char **)envp);
	int			i;
	int			dest_index;
	int			target_index;
	char		**dest;

	i = 0;
	dest_index = 0;
	target_index = 0;
	s_malloc((void **)&dest, sizeof(char *) * (size + 1 - target_size));
	while (i < size)
	{
		if (i == target[target_index] && target[target_index])
		{
			i++;
			target_index++;
			continue ;
		}
		*(dest + dest_index) = ft_strdup(*(envp + i));
		i++;
		dest_index++;
	}
	*(dest + dest_index) = 0;
	free2(envp);
	return (dest);
}

static int	find_env(char *argument)
{
	int		env_index;
	char	**splited;

	env_index = 0;
	while (g_envp[env_index])
	{
		if (ft_find(g_envp[env_index], '=') == 1)
		{
			splited = ft_split(g_envp[env_index], '=');
			if (ft_strcmp(splited[0], argument) == 0)
			{
				free2(splited);
				return (env_index);
			}
			free2(splited);
		}
		else
		{
			if (ft_strcmp(argument, g_envp[env_index]) == 0)
				return (env_index);
		}
		env_index++;
	}
	return (0);
}

void	ft_unset(char **argument, int *exit_code)
{
	int	index;
	int	target_index;
	int	result;
	int	delete_target[256];

	index = 0;
	target_index = 0;
	ft_memset(delete_target, 0, sizeof(char) * 256);
	while (argument[index])
	{
		result = 0;
		result = find_env(argument[index]);
		if (result != 0)
		{
				delete_target[target_index] = result;
				target_index += 1;
		}
		index++;
	}
	delete_target[target_index] = 0;
	g_envp = copy_envp_exclude(g_envp, delete_target, target_index);
	(*exit_code) = 0;
	return ;
}

void	ft_unset_exit(char **argument, int *exit_code)
{
	int	index;
	int	target_index;
	int	result;
	int	delete_target[256];

	index = 0;
	target_index = 0;
	ft_memset(delete_target, 0, sizeof(char) * 256);
	while (argument[index])
	{
		result = 0;
		result = find_env(argument[index]);
		if (result != 0)
		{
				delete_target[target_index] = result;
				target_index += 1;
		}
		index++;
	}
	delete_target[target_index] = 0;
	g_envp = copy_envp_exclude(g_envp, delete_target, target_index);
	(*exit_code) = 0;
	exit(0);
}
