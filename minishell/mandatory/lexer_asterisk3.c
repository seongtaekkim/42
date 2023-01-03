/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_asterisk3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:37:29 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:21:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*first_asterisk(char *str, char *name, t_bool *flag)
{
	char	*ret;

	ret = ft_strnstr(name, str, ft_strlen(str));
	if (!ret)
		*flag = false;
	else
	{
		*flag = true;
		ret = ret + ft_strlen(str);
	}
	return (ret);
}

static char	*mid_asterisk(char *str, char *name, t_bool *flag)
{
	const int	file_size = ft_strlen(name);
	char		*ret;

	ret = ft_strnstr(name, str, file_size);
	if (!ret)
		*flag = false;
	else
	{
		*flag = true;
		ret = ret + ft_strlen(str);
	}
	return (ret);
}

static char	*last_asterisk(char *str, char *name, t_bool *flag)
{
	char	*word;
	char	*file;
	char	*ret;

	word = ft_strdup(str);
	file = ft_strdup(name);
	reverse_str(word);
	reverse_str(file);
	ret = ft_strnstr(file, word, ft_strlen(word));
	if (ret)
	{
		free(word);
		free(file);
		*flag = true;
		ret = ret + ft_strlen(str);
	}
	else
	{
		free(word);
		free(file);
		*flag = false;
	}
	return (ret);
}

static void	except_asterisk(char *name, t_bool *flag)
{
	if (ft_strncmp(name, ".", 1) == 0)
		*flag = false;
	else
		*flag = true;
}

t_bool	is_proper_file(char *wc, char *name)
{
	char	**words;
	int		i;
	int		words_size;
	t_bool	flag;
	char	*str;

	flag = true;
	i = 0;
	words = ft_split(wc, '*');
	words_size = ft_strlen2((const char **)words);
	except_asterisk(name, &flag);
	while (flag == true && words_size > i)
	{
		str = words[i];
		if (i == 0 && wc[i] != '*')
			name = first_asterisk(str, name, &flag);
		else if (words_size == i + 1 && wc[ft_strlen(wc) - 1] != '*')
			name = last_asterisk(str, name, &flag);
		else
			name = mid_asterisk(str, name, &flag);
		i++;
	}
	free2((char **)words);
	return (flag);
}
