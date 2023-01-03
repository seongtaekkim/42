/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_heredoc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:07:24 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "shell.h"

void	delete_tempfile(void)
{
	DIR				*dir_info;
	struct dirent	*dir_entry;

	dir_info = opendir(".");
	if (dir_info)
	{
		dir_entry = readdir(dir_info);
		while (dir_entry)
		{
			if (ft_strncmp(dir_entry->d_name, ".temp", 5) == 0)
				unlink(dir_entry->d_name);
			dir_entry = readdir(dir_info);
		}
		closedir(dir_info);
	}
}

static void	num_of_tempfile(char *filename, int *max)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = NULL;
	if (ft_strncmp(filename, ".temp", 5) == 0)
	{
		if (ft_strlen(filename) > 5)
		{
			tmp = ft_substr(filename, 5, ft_strlen(filename));
			len = ft_atoi(tmp);
			if (len > *max)
				*max = len;
			free(tmp);
		}
	}
}

static char	*open_tempfile(void)
{
	DIR				*dir_info;
	struct dirent	*dir_entry;
	int				max;

	max = 0;
	dir_info = opendir(".");
	if (dir_info)
	{
		dir_entry = readdir(dir_info);
		while (dir_entry)
		{
			num_of_tempfile(dir_entry->d_name, &max);
			dir_entry = readdir(dir_info);
		}
		closedir(dir_info);
		max = max + 1;
	}
	return (ft_itoa(max));
}

char	*create_filename(void)
{
	char	*fileidx;
	char	*filename;

	fileidx = open_tempfile();
	filename = ft_strjoin(".temp", fileidx);
	free(fileidx);
	return (filename);
}
