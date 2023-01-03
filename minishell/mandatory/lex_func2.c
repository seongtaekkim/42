/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:47:59 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	lex_and(char **str, t_lexer **lexer, t_token **tail)
{
	if ((*lexer)->quote || get_lexical_type(*(*str + 1)) != (*lexer)->type)
	{
		append_str_back(&((*tail)->t_str), create_str(**str));
		*str = *str + 1;
		(*tail)->type = AST_DATA;
	}
	else
	{
		*str = *str + 1;
		if (get_lexical_type(**str) == (*lexer)->type)
		{
			if ((*(tail))->t_str)
			{
				append_token_back(&((*lexer)->token), *tail);
				*(tail) = create_token(0);
			}
			(*tail)->type = AST_AND;
			(*tail)->t_str = create_str(**str);
			append_str_back(&((*tail)->t_str), create_str(**str));
			*str = *str + 1;
			append_token_back(&((*lexer)->token), *tail);
			*(tail) = create_token(0);
		}
	}
}

void	lex_pipe_or(char **str, t_lexer **lexer, t_token **tail)
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
		(*tail)->t_str = create_str(**str);
		(*tail)->type = AST_PIPE;
		*str = *str + 1;
		if (get_lexical_type(**str) == (*lexer)->type)
		{
			append_str_back(&((*tail)->t_str), create_str(**str));
			*str = *str + 1;
			(*tail)->type = AST_OR;
		}
		append_token_back(&((*lexer)->token), *tail);
		*(tail) = create_token(0);
	}
}

void	lex_in_here(char **str, t_lexer **lexer, t_token **tail)
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
		(*tail)->t_str = create_str(**str);
		(*tail)->type = AST_REDIRECT_IN;
		*str = *str + 1;
		if (get_lexical_type(**str) == (*lexer)->type)
		{
			append_str_back(&((*tail)->t_str), create_str(**str));
			*str = *str + 1;
			(*tail)->type = AST_HEREDOC;
		}
		append_token_back(&((*lexer)->token), *tail);
		*(tail) = create_token(0);
	}
}

void	lex_out_append(char **str, t_lexer **lexer, t_token **tail)
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
		(*tail)->t_str = create_str(**str);
		(*tail)->type = AST_REDIRECT_OUT;
		*str = *str + 1;
		if (get_lexical_type(**str) == (*lexer)->type)
		{
			append_str_back(&((*tail)->t_str), create_str(**str));
			*str = *str + 1;
			(*tail)->type = AST_APPEND;
		}
		append_token_back(&((*lexer)->token), *tail);
		*(tail) = create_token(0);
	}
}
