/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:26:41 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/06 19:10:19 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	count_word(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str == '\0')
			break ;
		while ((*str != c) && *str != '\0')
			str++;
		count++;
	}
	return (count);
}

char	*ft_strndup(char *str, unsigned int n)
{
	unsigned int	index;
	unsigned int	length;
	char			*dup;

	length = 0;
	while (str[length])
		length++;
	if (length > n)
		length = n;
	dup = (char *)malloc(sizeof(char) * length + 1);
	if (!dup)
		return (NULL);
	index = 0;
	while (index < length)
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

void	free_list(char	**array)
{
	int	index;

	index = 0;
	while (array[index])
		free(array[index++]);
	free(array);
}

char	**do_split(char **array, char *str, char c)
{
	char	*word_start;
	int		index;

	index = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		if (*str == '\0')
			break ;
		word_start = str;
		while ((*str != c) && *str != '\0')
			str++;
		if (str - word_start > 0)
		{
			array[index] = ft_strndup(word_start, str - word_start);
			if (!array[index])
			{
				free_list(array);
				return (NULL);
			}
		}
		index++;
	}
	return (array);
}

char	**ft_split(char *str, char c)
{
	int		word_count;
	char	**array;
	int		index;

	word_count = count_word(str, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	array = do_split(array, str, c);
	array[index] = 0;
	return (array);
}

int	main(void)
{
	char *str = "!awegaweg!awega!wegaweg!";
	//char *str = "";
	char str2[100];
	int i=0;
	while (i<37)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';

	char **strs = ft_split(str2, '!');
//free(strs);
	i = 0;
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
}
