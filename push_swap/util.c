/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:59:17 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/30 16:48:06 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_for_atoi(const char *str, int *flag)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str)
	{
		if (ft_isdigit(*str))
			result = result * 10 + (*str++ - '0');
		else
		{
			*flag = 0;
			return (-1);
		}
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			*flag = 0;
	}
	return (result * sign);
}

int	*append_array_data(int *op_list, int size, int op)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * size);
	while (i < size - 1)
	{
		tmp[i] = op_list[i];
		i++;
	}
	tmp[i] = op;
	free(op_list);
	return (tmp);
}
