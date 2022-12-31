/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:26:41 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/05 14:36:32 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	change_flag(const char **str, char c2, int *flag)
{
	*flag = 0;
	if (**str == c2)
	{
		*flag = 1;
		(*str)++;
	}
}

int	next_word(const char **str, char c, char c2, int *flag)
{
	if (*flag)
		while (**str != c2 && **str != '\0')
			(*str)++;
	else
	{
		if (**str == '\0')
			return (0);
		while ((**str != c) && **str != '\0')
			(*str)++;
	}
	*flag = 0;
	return (1);
}
