/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_asterisk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:37:29 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	start_condition(char *str, int *cur, int *start)
{
	int	i;

	i = *cur - 1;
	while (i >= 0)
	{
		if (get_lexical_type(str[i]) != 0)
			break ;
		i--;
		(*start)++;
	}
	i += 1;
	return (i);
}

static char	*condition_string(char *str, int *cur)
{
	int		i;
	int		post_len;
	int		pre_len;
	char	*ret;

	pre_len = 0;
	post_len = 0;
	i = start_condition(str, cur, &pre_len);
	while (str[i])
	{
		if (get_lexical_type(str[i]) != 0)
			break ;
		i++;
		post_len++;
	}
	ret = ft_substr(str, *cur - pre_len, post_len);
	(*cur) += (post_len - pre_len);
	return (ret);
}

void	set_asterisk(char **str, char *env, int length, int *cur)
{
	const int	strlen = ft_strlen((*str));
	const int	envlen = ft_strlen(env);
	const int	entire_len = strlen + envlen - length;
	char		*new;
	int			pre_index;

	pre_index = *cur - length;
	if (pre_index < 0)
		pre_index = 0;
	s_malloc((void **)&new, sizeof(char) * entire_len + 1);
	ft_memcpy(new, *str, pre_index);
	ft_memcpy(new + pre_index, env, envlen);
	ft_memcpy(new + pre_index + envlen,
		(*str) + pre_index + length, strlen - pre_index - length);
	new[entire_len] = '\0';
	free(env);
	free(*str);
	(*cur) += (envlen - length);
	(*cur) -= 1;
	(*str) = new;
}

char	*lex_asterisk(char *str)
{
	int		i;
	int		quote;
	char	*ret;
	char	*cond;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (str[i] == quote)
			quote = 0;
		if (str[i] == '*' && quote == 0)
		{
			cond = condition_string(str, &i);
			ret = dir_to_string(cond);
			if (ret)
				set_asterisk(&str, ret, ft_strlen(cond), &i);
			free(cond);
		}
		else
			i++;
	}
	return (str);
}
