/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:26:41 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 14:36:32 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *str, char c, char c2, int flag)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		change_flag(&str, c2, &flag);
		if (flag)
			while (*str != c2 && *str != '\0')
				str++;
		else
		{
			if (*str == '\0')
				break ;
			while ((*str != c) && *str != '\0')
				str++;
		}
		count++;
		flag = 0;
	}
	return (count);
}

static char	*ft_strndup(char const *str, size_t n)
{
	size_t	index;
	char	*dup;

	dup = (char *)malloc(sizeof(char) * n + 1);
	if (!dup)
		return (NULL);
	index = 0;
	while (index < n)
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

static void	free_list(char	**array)
{
	int	index;

	index = 0;
	while (array[index])
		free(array[index++]);
	free(array);
}

static char	**do_split(char **array, char const *str, char c, char c2)
{
	char	*word_start;
	size_t	index;
	int		flag;

	index = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		change_flag(&str, c2, &flag);
		word_start = (char *)str;
		if (!next_word(&str, c, c2, &flag))
			break ;
		if (str - word_start > 0)
		{
			array[index] = ft_strndup(word_start, (size_t)(str - word_start));
			if (!array[index++])
			{
				free_list(array);
				return (NULL);
			}
		}
	}
	array[index] = 0;
	return (array);
}

char	**ft_split2(char const *s, char c, char c2)
{
	size_t	word_count;
	char	**array;

	if (!s)
		return (NULL);
	word_count = count_word(s, c, c2, 0);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	array = do_split(array, s, c, c2);
	return (array);
}
