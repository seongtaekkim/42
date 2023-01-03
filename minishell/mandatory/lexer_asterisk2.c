/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_asterisk2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:37:29 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "shell.h"

static void	join_d_name(char **ret, char *name)
{
	int		ret_size;
	int		name_size;
	char	*join;

	ret_size = 0;
	if (*ret != 0)
		ret_size = ft_strlen(*ret);
	name_size = ft_strlen(name);
	s_malloc((void **)&join, sizeof(char *) * (ret_size + name_size + 2));
	ft_memcpy(join, *ret, ret_size);
	ft_memcpy(join + ret_size, " ", 1);
	ft_memcpy(join + ret_size + 1, name, name_size);
	join[ret_size + name_size + 1] = '\0';
	free(*ret);
	(*ret) = join;
}

char	*dir_to_string(char *wc)
{
	DIR				*dir_info;
	struct dirent	*dir_entry;
	char			*ret;

	ret = 0;
	dir_info = opendir(".");
	if (dir_info)
	{
		dir_entry = readdir(dir_info);
		while (dir_entry)
		{
			if (is_proper_file(wc, dir_entry->d_name))
				join_d_name(&ret, dir_entry->d_name);
			dir_entry = readdir(dir_info);
		}
		closedir(dir_info);
	}
	return (ret);
}
