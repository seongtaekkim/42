/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:00:50 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/07 19:00:54 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	number_size(long number)
{
	int	size;

	size = 0;
	while (1)
	{
		number /= 10;
		size++;
		if (number == 0)
			break ;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	number;
	char	*array;
	int		size;

	number = n;
	size = number_size(n);
	if (number < 0)
		number = number * -1;
	array = malloc(sizeof(char) * (size + 1));
	if (!array)
		return (NULL);
	array[size] = '\0';
	while (1)
	{
		array[size - 1] = (number % 10) + '0';
		number /= 10;
		size--;
		if (number == 0)
			break ;
	}
	return (array);
}
