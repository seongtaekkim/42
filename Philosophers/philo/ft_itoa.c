/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:27:31 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/09 14:38:00 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	number_size(long long number)
{
	size_t	size;

	if (number < 0)
		size = 1;
	else
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

char	*ft_itoa(long long n)
{
	long long	number;
	char		*array;
	size_t		size;

	number = n;
	size = number_size(n);
	if (!s_malloc((void **)&array, sizeof(char) * (size + 1)))
		return (NULL);
	if (number < 0)
	{
		array[0] = '-';
		number *= -1;
	}
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
