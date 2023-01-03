/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:08:31 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	env_strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length])
	{
		if (str[length] == '$')
			break ;
		if (get_lexical_type(str[length]))
			break ;
		length++;
	}
	return (length);
}

static char	*get_env(char *str, int length, int exit_code)
{
	int		i;
	char	*env;

	i = 0;
	if (str[i] == '?' && length == 1)
		return (ft_itoa(exit_code));
	while (*(g_envp + i))
	{
		env = *(g_envp + i);
		if (ft_strncmp(str, env, length) == 0
			&& ft_strncmp(env + length, "=", 1) == 0)
			return (ft_substr(env, length + 1, ft_strlen(env) - length - 1));
		i++;
	}
	return (ft_strdup(""));
}

static void	set_env(char **str, char *env, int length, int *cur)
{
	const int	strlen = ft_strlen((*str));
	const int	envlen = ft_strlen(env);
	const int	entire_len = strlen + envlen - length;
	char		*new;

	s_malloc((void **)&new, sizeof(char) * entire_len + 1);
	ft_memcpy(new, *str, *cur);
	ft_memcpy(new + *cur, env, envlen);
	ft_memcpy(new + *cur + envlen,
		(*str) + *cur + length, strlen - *cur - length);
	new[entire_len] = '\0';
	free(env);
	free(*str);
	*(str) = new;
	(*cur) += envlen;
	(*cur) -= 1;
}

char	*lex_env(char *str, int exit_code)
{
	int		i;
	int		quote;
	int		length;
	char	*ret;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (str[i] == quote)
			quote = 0;
		if (str[i] == '$' && quote != '\'')
		{
			length = env_strlen(str + i + 1);
			if (length > 0)
			{
				ret = get_env(str + i + 1, length, exit_code);
				set_env(&str, ret, length + 1, &i);
			}
		}
		i++;
	}
	return (str);
}
