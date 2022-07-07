/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:27:31 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/07 10:40:34 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	number_size(long number)
{
	size_t	size;

	size = (number < 0 ? 1 : 0);
	while (1)
	{
		number /= 10;
		size++;
		if (number  == 0)
			break;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	number;
	char	*array;
	size_t	size;

	number = n;
	size = number_size(n);
	array = malloc(sizeof(char) * (size + 1));
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
		if (number ==0)
			break ;
	}
	return (array);
}
