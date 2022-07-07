/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:19:55 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/06 17:36:15 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_space(char c)
{
	int	flag;

	flag = (c == ' ' || c == '\n' || c == '\r')	\
			|| (c == '\t' || c == '\v' || c == '\f');
	return (flag);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (is_sign(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_number(*str))
	{
		result = result * 10;
		result = result + *str - '0';
		str++;
	}
	return (result * sign);
}
