/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_heredoc3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:07:24 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"
#include "./libft/get_next_line.h"

static void	int_handler(int sig)
{
	exit(sig + SIGNALOFFSET);
}

static void	open_heredoc(char *eof, char *filename)
{
	int		fd;
	char	*str;

	signal(SIGINT, int_handler);
	signal(SIGQUIT, SIG_IGN);
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (!fd)
		exit_print(filename, true);
	while (1)
	{
		s_write(1, "heredoc> ");
		str = get_next_line(0);
		if (!str || (*(str) != '\n' && !ft_memcmp(str, eof, ft_strlen(str) - 1)
				&& !ft_memcmp(str, eof, ft_strlen(eof))))
		{
			free(str);
			break ;
		}
		else
		{
			s_write(fd, str);
			free(str);
		}
	}
	close(fd);
}

int	waitpid_heredoc(int pid, int *exit_code, t_lexer **lexer, char *eof)
{
	int	state;

	free(eof);
	if (waitpid(pid, &state, 0))
	{
		if (WIFEXITED(state))
		{
			*(exit_code) = WEXITSTATUS(state);
			if (*(exit_code) == 130)
			{
				(*lexer)->syntex_error = -2;
				return (0);
			}
		}
		else if (WIFSIGNALED(state))
			*(exit_code) = WTERMSIG(state) + SIGNALOFFSET;
	}
	return (1);
}

void	child_heredoc(char *eof, char *filename)
{
	open_heredoc(eof, filename);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	free(eof);
	free(filename);
	exit(0);
}
