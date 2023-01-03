/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:07:24 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	find_eof(char *str, int *i, char **eof, t_lexer **lexer)
{
	int		length;
	int		start;

	length = 0;
	while (str[*i] == ' ')
		(*i)++;
	start = (*i);
	while (get_lexical_type(str[*i]) == 0)
	{
		(*i)++;
		length++;
	}
	*eof = ft_substr(str, start, length);
	if (ft_strlen(*eof) == 0)
	{
		free(*eof);
		(*lexer)->syntex_error = -1;
		return (0);
	}
	return (1);
}

static void	set_result(char **str, char *temp_file, int start, int *cur)
{
	const int	templen = ft_strlen(temp_file);
	const int	curlen = *cur - start;
	const int	entire_len = ft_strlen(*str) + templen - curlen + 2;
	char		*new;
	int			pre_index;

	pre_index = *cur - curlen;
	if (pre_index < 0)
		pre_index = 0;
	s_malloc((void **)&new, sizeof(char) * entire_len + 1);
	ft_memcpy(new, *str, pre_index);
	ft_memcpy(new + pre_index, "< ", 2);
	ft_memcpy(new + pre_index + 2, temp_file, templen);
	ft_memcpy(new + pre_index + 2 + templen,
		(*str) + pre_index + curlen, ft_strlen(*str) - pre_index - curlen);
	new[entire_len] = '\0';
	free(*str);
	free(temp_file);
	(*cur) += (2 + templen - curlen);
	(*cur) -= 1;
	(*str) = new;
}

static void	quote_check(int *quote, char c)
{
	if (!(*quote) && (c == '\'' || c == '\"'))
		*quote = c;
	else if (c == *quote)
		*quote = 0;
}

static void	pre_set_heredoc(int *start, int *i)
{
	*start = *i;
	(*i) += 2;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

char	*lex_heredoc(char *str, int *exit, t_lexer **lexer, int quote)
{
	int		i;
	int		start;
	char	*eof;
	int		pid;
	char	*fname;

	i = -1;
	while (str[++i])
	{
		quote_check(&quote, str[i]);
		if (str[i] == '<' && str[i + 1] == '<' && quote == 0)
		{
			pre_set_heredoc(&start, &i);
			if (!find_eof(str, &i, &eof, lexer))
				return (str);
			pid = fork();
			fname = create_filename();
			if (pid == 0)
				child_heredoc(eof, fname);
			if (!waitpid_heredoc(pid, exit, lexer, eof) && file_free(fname))
				return (str);
			set_result(&str, fname, start, &i);
		}
	}
	return (str);
}
