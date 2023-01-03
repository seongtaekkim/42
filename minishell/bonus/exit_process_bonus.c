/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_process_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:41:27 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"

static void	exit_print2(char *s1, char *s2, char *s3)
{
	s_write(STDERR_FILENO, s1);
	s_write(STDERR_FILENO, s2);
	s_write(STDERR_FILENO, s3);
}

int	exit_print(char *str, t_bool is_parent)
{
	int	err;

	if (errno == ENOENT)
	{
		exit_print2("shell: ", str, ": No such file or directory\n");
		err = EXITGENERAL;
	}
	else if (errno == EACCES)
	{
		exit_print2("shell: ", str, ": Permission denied\n");
		err = EXITCANNOTEXECUTE;
	}
	else if (errno == EFAULT)
	{
		exit_print2("shell: ", str, ": Command not found\n");
		err = EXITNOTFOUND;
	}
	else
		err = EXITVALID;
	if (is_parent == true)
		return (0);
	exit(err);
}

void	exit_not_found(char *str)
{
	s_write(STDERR_FILENO, "shell: ");
	s_write(STDERR_FILENO, str);
	s_write(STDERR_FILENO, ": Command not found\n");
	exit(EXITNOTFOUND);
}

int	file_free(char *filename)
{
	free(filename);
	return (1);
}
