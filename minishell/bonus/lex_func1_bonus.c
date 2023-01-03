/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_func1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:50:13 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"

void	lex_char(char **str, t_lexer **lexer, t_token **tail)
{
	(void)lexer;
	(*tail)->type = AST_DATA;
	append_str_back(&((*tail)->t_str), create_str(**str));
	*str = *str + 1;
}

void	lex_space(char **str, t_lexer **lexer, t_token **tail)
{
	if ((*lexer)->quote)
	{
		append_str_back(&((*tail)->t_str), create_str(**str));
		(*tail)->type = AST_TOKEN;
	}
	else
	{
		if ((*tail)->t_str)
		{
			append_token_back(&((*lexer)->token), *tail);
			*tail = create_token(0);
			(*tail)->type = AST_DATA;
		}
	}
	*str = *str + 1;
}

void	lex_quote(char **str, t_lexer **lexer, t_token **tail)
{
	if (!(*lexer)->quote)
		(*lexer)->quote = **str;
	else if (**str == (*lexer)->quote)
		(*lexer)->quote = 0;
	else
		append_str_back(&((*tail)->t_str), create_str(**str));
	*str = *str + 1;
	(*tail)->type = AST_DATA;
}

void	lex_parentheses_open(char **str, t_lexer **lexer, t_token **tail)
{
	if ((*lexer)->quote)
	{
		append_str_back(&((*tail)->t_str), create_str(**str));
		*str = *str + 1;
		(*tail)->type = AST_DATA;
	}
	else
	{
		if ((*(tail))->t_str)
		{
			append_token_back(&((*lexer)->token), *tail);
			*(tail) = create_token(0);
		}
		((*lexer)->parentheses) += 1;
		(*tail)->t_str = create_str(**str);
		(*tail)->type = AST_PARENTHESES_O;
		*str = *str + 1;
		append_token_back(&((*lexer)->token), *tail);
		*(tail) = create_token(0);
	}
}

void	lex_parentheses_close(char **str, t_lexer **lexer, t_token **tail)
{
	if ((*lexer)->quote)
	{
		append_str_back(&((*tail)->t_str), create_str(**str));
		*str = *str + 1;
		(*tail)->type = AST_DATA;
	}
	else
	{
		if ((*lexer)->parentheses == 0)
			(*lexer)->syntex_error = -1;
		if ((*(tail))->t_str)
		{
			append_token_back(&((*lexer)->token), *tail);
			*(tail) = create_token(0);
		}
		((*lexer)->parentheses) -= 1;
		(*tail)->t_str = create_str(**str);
		(*tail)->type = AST_PARENTHESES_C;
		*str = *str + 1;
		append_token_back(&((*lexer)->token), *tail);
		*(tail) = create_token(0);
	}
}
