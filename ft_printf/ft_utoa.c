/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:01:21 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/07 19:01:25 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	number_size(unsigned int number)
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

char	*ft_utoa(unsigned int n)
{
	unsigned int	number;
	char			*array;
	int				size;

	number = n;
	size = number_size(n);
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
