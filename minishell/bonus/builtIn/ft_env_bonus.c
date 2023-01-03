/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:51:39 by susong            #+#    #+#             */
/*   Updated: 2023/01/03 13:58:45 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_bonus.h"

void	ft_env(char **argument, int *exit_code)
{
	int	index;

	(void)argument;
	index = 0;
	while (g_envp[index] && g_envp[index] != NULL)
	{
		if (ft_strchr(g_envp[index], '=') != NULL)
		{
			s_write(1, g_envp[index]);
			s_write(1, "\n");
		}
		index++;
	}
	(*exit_code) = 0;
	return ;
}

void	ft_env_exit(char **argument, int *exit_code)
{
	int	index;

	(void)argument;
	index = 0;
	while (g_envp[index] && g_envp[index] != NULL)
	{
		if (ft_strchr(g_envp[index], '=') != NULL)
		{
			s_write(1, g_envp[index]);
			s_write(1, "\n");
		}
		index++;
	}
	(*exit_code) = 0;
	exit (0);
}
