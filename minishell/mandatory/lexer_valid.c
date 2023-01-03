/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:00:39 by staek             #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	redirect_valid(t_token *t, t_lexer *lexer)
{
	while (t)
	{
		if (t->type == AST_REDIRECT_IN || t->type == AST_REDIRECT_OUT
			|| t->type == AST_APPEND || t->type == AST_HEREDOC)
		{
			if (!(t->next) || (t->next && t->next->type != AST_DATA))
			{
				(*lexer).syntex_error = -1;
				break ;
			}
		}
		t = t->next;
	}
}

static int	lex_valid1(t_token *t)
{
	if (!(t->type == AST_PARENTHESES_C && t->next->type == AST_PARENTHESES_C)
		&& !(t->type == AST_PARENTHESES_C && t->next->type == AST_PIPE)
		&& !(t->type == AST_PARENTHESES_C && t->next->type == AST_OR)
		&& !(t->type == AST_PARENTHESES_C && t->next->type == AST_AND)
		&& !(t->type == AST_PARENTHESES_O && t->next->type == AST_PARENTHESES_O)
		&& !(t->type == AST_OR && t->next->type == AST_PARENTHESES_O)
		&& !(t->type == AST_AND && t->next->type == AST_PARENTHESES_O)
		&& !(t->type == AST_PIPE && t->next->type == AST_PARENTHESES_O)
		&& !(t->type == AST_PIPE && t->next->type == AST_REDIRECT_IN)
		&& !(t->type == AST_PIPE && t->next->type == AST_REDIRECT_OUT)
		&& !(t->type == AST_PIPE && t->next->type == AST_APPEND)
		&& !(t->type == AST_OR && t->next->type == AST_REDIRECT_IN)
		&& !(t->type == AST_OR && t->next->type == AST_REDIRECT_OUT)
		&& !(t->type == AST_OR && t->next->type == AST_APPEND)
		&& !(t->type == AST_AND && t->next->type == AST_REDIRECT_IN)
		&& !(t->type == AST_AND && t->next->type == AST_REDIRECT_OUT)
		&& !(t->type == AST_AND && t->next->type == AST_APPEND)
		&& !(t->type == AST_PARENTHESES_O && t->next->type == AST_REDIRECT_IN)
		&& !(t->type == AST_PARENTHESES_O && t->next->type == AST_REDIRECT_OUT)
		&& !(t->type == AST_PARENTHESES_O && t->next->type == AST_APPEND)
		&& !(t->type == AST_PARENTHESES_C && t->next->type == AST_REDIRECT_IN)
		&& !(t->type == AST_PARENTHESES_C && t->next->type == AST_REDIRECT_OUT)
		&& !(t->type == AST_PARENTHESES_C && t->next->type == AST_APPEND))
		return (0);
	return (1);
}

static int	lex_valid2(t_token *t, t_lexer *lexer)
{
	if (lexer->quote)
	{
		(*lexer).syntex_error = -1;
		return (0);
	}
	if (t->type == AST_PIPE || t->type == AST_AND || t->type == AST_OR)
	{
		(*lexer).syntex_error = -1;
		return (0);
	}
	while (t->next)
		t = t->next;
	if (t->type == AST_PIPE || t->type == AST_AND || t->type == AST_OR)
	{
		(*lexer).syntex_error = -1;
		return (0);
	}
	return (1);
}

void	lexer_valid(t_lexer *lexer)
{
	t_lexer	*tmp;
	t_token	*t;

	tmp = lexer;
	t = tmp->token;
	if (!t)
		return ;
	if (!lex_valid2(t, lexer))
		return ;
	t = tmp->token;
	redirect_valid(t, lexer);
	t = tmp->token;
	while (t)
	{
		if (t->type != AST_DATA && t->next && t->next->type != AST_DATA)
		{
			if (!lex_valid1(t))
			{
				(*lexer).syntex_error = -1;
				break ;
			}
		}
		t = t->next;
	}
}
