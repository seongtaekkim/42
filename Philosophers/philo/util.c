/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staek <staek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:28:54 by staek             #+#    #+#             */
/*   Updated: 2023/01/05 22:48:12 by staek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	s_malloc(void **ptr, size_t size)
{
	*ptr = (void *)malloc(size);
	if (!ptr)
		return (0);
	return (1);
}

t_bool	_atoi(const char *str, int *output)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == 0 || *str == '-')
		return (false);
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str++ - '0');
		else
			return (false);
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (false);
	}
	*output = result * sign;
	return (true);
}
