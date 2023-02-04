/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:40:01 by susong            #+#    #+#             */
/*   Updated: 2023/02/03 13:08:26 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	ft_pow(int nb, int power)
{
	int	ret;

	ret = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power-- > 0)
		ret = nb * ret;
	return (ret);
}

static float	ft_mantissa(const char *str, int *ascii)
{
	float	result;
	int		index;

	result = 0.0f;
	index = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10;
		result = result + *str - '0';
		str++;
		index++;
	}
	result = result / ft_pow(10, index);
	if (*str != 0 && *str != '\n')
		*ascii = 1;
	return (result);
}

float	ft_atof(const char *str, int *ascii)
{
	float	result;
	int		sign;

	result = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10;
		result = result + *str - '0';
		str++;
	}
	if (*str != '.' && *str != '\n' && *str != 0)
		*ascii = 1;
	if (*str == '.')
		str++;
	result = result + ft_mantissa(str, ascii);
	return (result * sign);
}
