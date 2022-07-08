/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:59:06 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/08 17:39:55 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_left(char const *s1, char const *set)
{
	int	index;
	int	count;
	int	flag;

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

int	check_right(char const *s1, char const *set, int set_len)
{
	int	set_idx;
	int	s1_idx;
	int	count;
	int	flag;

	count = 0;
	set_idx = set_len;
	s1_idx = ft_strlen(s1) -1;
	while (s1_idx >= 0)
	{
		flag = 0;
		set_idx = set_len;
		while (set_idx > 0)
		{
			if (set[--set_idx] == s1[s1_idx])
			{
				s1_idx--;
				count++;
				flag = 1;
			}
		}
		if (flag == 0)
			break ;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		left;
	int		right;
	int		index;
	int		total;
	char	*ret;

	if (!s1)
		return (NULL);
	index = 0;
	left = check_left(s1, set);
	right = check_right(s1, set, ft_strlen(set));
	total = ft_strlen(s1) - left - right;
	if (total <= 0)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (total + 1));
	if (!ret)
		return (NULL);
	while (index < total)
		ret[index++] = s1[left++];
	ret[index] = '\0';
	return (ret);
}
