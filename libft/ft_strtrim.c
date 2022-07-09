/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:59:06 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/09 19:39:22 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_left(char const *s1, char const *set)
{
	size_t	index;
	size_t	count;
	int		flag;

	count = 0;
	index = 0;
	while (*s1)
	{
		index = 0;
		flag = 0;
		while (set[index])
		{
			if (set[index++] == *s1)
			{
				s1++;
				count++;
				flag = 1;
			}
		}
		if (flag == 0)
			break ;
	}
	return (count);
}

size_t	check_right(char const *s1, char const *set
		, size_t set_idx, size_t s1_idx)
{
	size_t		count;
	int			flag;

	count = 0;
	while (s1_idx >= 0)
	{
		flag = 0;
		set_idx = 0;
		while (set[set_idx])
		{
			if (set[set_idx++] == s1[s1_idx])
			{
				count++;
				if (s1_idx == 0)
					break ;
				flag = 1;
				s1_idx--;
			}
		}
		if (flag == 0)
			break ;
	}
	return (count);
}

size_t	set_total(size_t length, size_t left, size_t right)
{
	if (length * 2 <= (left + right))
		return (0);
	else
		return (length - left - right);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;
	size_t	index;
	size_t	total;
	char	*ret;

	if (!s1)
		return (NULL);
	index = 0;
	left = check_left(s1, set);
	right = check_right(s1, set, 0, ft_strlen(s1) - 1);
	total = set_total(ft_strlen(s1), left, right);
	if (total <= 0)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (total + 1));
	if (!ret)
		return (NULL);
	while (index < total)
	{
		ret[index++] = s1[left];
		left++;
	}
	ret[index] = '\0';
	return (ret);
}
