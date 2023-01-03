/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_util_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:42:27 by susong            #+#    #+#             */
/*   Updated: 2023/01/03 13:59:12 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_bonus.h"

// Return	Context of envp
// Argument	: const char *path
// Return	: char *context of envp which matched to path
char	*get_envp(const char *path)
{
	int				index;
	int				letter_index;
	int				path_size;

	index = 0;
	path_size = ft_strlen(path);
	while (g_envp[index])
	{
		letter_index = 0;
		while (letter_index < path_size && \
			path[letter_index] == g_envp[index][letter_index])
			letter_index++;
		if (letter_index == path_size)
			return (ft_strchr(g_envp[index], '=') + 1);
		index++;
	}
	return (0);
}

void	cd_err_print(int flag, char *path)
{
	(void)flag;
	s_write(2, "shell: cd: ");
	s_write(2, path);
	s_write(2, ": ");
	s_writeln(2, strerror(errno));
	return ;
}

void	s_free(char *target)
{
	if (target[0] != '\0' && target != 0 && target)
		free(target);
	return ;
}
