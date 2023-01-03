/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:59:15 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	get_size_token_str(t_token *cursor)
{
	int		length;
	t_str	*str;

	length = 0;
	str = cursor->t_str;
	while (str)
	{
		str = str->next;
		length++;
	}
	return (length);
}

t_bool	term(t_token **cursor, int toketype, char **bufferptr)
{
	int		i;
	t_str	*str;

	if (!(*cursor))
		return (false);
	if ((*cursor)->type == toketype)
	{
		if (bufferptr != NULL)
		{
			s_malloc((void **)&(*bufferptr), get_size_token_str(*cursor) + 1);
			str = (*cursor)->t_str;
			i = 0;
			while (str)
			{
				(*bufferptr)[i++] = str->c;
				str = str->next;
			}
			(*bufferptr)[i] = '\0';
		}
		(*cursor) = (*cursor)->next;
		return (true);
	}
	return (false);
}

void	set_is_last(t_astree **ast, int *finish)
{
	if (!(*ast))
		return ;
	if (*finish == 1)
		return ;
	if ((*ast)->type == AST_CMDPATH)
	{
		(*ast)->is_last = true;
		*finish = 1;
	}
	set_is_last(&((*ast)->right), finish);
	set_is_last(&((*ast)->left), finish);
}

int	parse(t_lexer *lexer, t_astree **ast)
{
	t_token	*cursor;
	int		finish;

	cursor = lexer->token;
	*ast = job(&cursor);
	finish = 0;
	set_is_last(ast, &finish);
	return (0);
}
