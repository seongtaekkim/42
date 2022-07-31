/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:27:31 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 14:38:14 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	sub_or_zero(size_t a, size_t b)
{
	if (a > b)
		return (a - b);
	else
		return (0);
}

t_bool	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
