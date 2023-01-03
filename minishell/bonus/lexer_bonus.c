/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 09:29:39 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"

int	get_lexical_type(char c)
{
	int					i;
	static const char	type[16] = {
		'\'', '\"', ' ', '<', '>', '|', '&', '(', ')', 9, 10, 11, 12, 13, 0};

	i = 0;
	while (i < 16)
	{
		if (c == type[i])
			return (i + 1);
		i++;
	}
	return (0);
}

static void	init_lexer(t_lexer **lexer)
{
	(*lexer)->quote = 0;
	(*lexer)->parentheses = 0;
	(*lexer)->token = 0;
	(*lexer)->syntex_error = 0;
}

void	do_lexer(char *str, t_lexer *lexer, int *exit_code)
{
	t_token				*tail;
	char				*bak;
	static void (*const	lex[16])(char **str, t_lexer **lexer,
			t_token **tail) = {lex_char, lex_quote, lex_quote, lex_space,
		lex_in_here, lex_out_append, lex_pipe_or, lex_and,
		lex_parentheses_open, lex_parentheses_close, lex_space, lex_space,
		lex_space, lex_space, lex_space};

	init_lexer(&lexer);
	str = lex_env(str, *exit_code);
	str = lex_asterisk(str);
	str = lex_heredoc(str, exit_code, &lexer, 0);
	tail = create_token(0);
	bak = str;
	while (*(str))
	{
		lexer->type = get_lexical_type(*(str));
		(lex[lexer->type])(&str, &lexer, &tail);
	}
	if (tail->t_str)
		append_token_back(&(lexer->token), tail);
	else
		free(tail);
	free(bak);
}
