/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:00:57 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/07 19:01:01 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_x_len(unsigned long long number, int radix, int *i, t_bool hash)
{
	unsigned int	length;

	if (hash)
		*i = 2;
	length = *i;
	while (1)
	{
		length++;
		if (number / radix == 0)
			break ;
		number /= radix;
	}
	return (length);
}

static int	num_length(unsigned long long number, int radix, int hsize)
{
	unsigned int	length;

	length = hsize;
	while (1)
	{
		length++;
		if (number / radix == 0)
			break ;
		number /= radix;
	}
	return (length);
}

char	*ft_nbr_base(unsigned int number, t_bool is_hash, char hash, int xindex)
{
	int			index;
	int			length;
	char		*string;
	const char	base[2][17] = {"0123456789abcdef", "0123456789ABCDEF"};

	index = 0;
	length = num_x_len(number, 16, &index, is_hash);
	string = (char *)malloc((length + 1) * sizeof(char));
	if (!string)
		return (0);
	if (is_hash)
	{
		string[0] = '0';
		string[1] = hash;
	}
	while (index < length)
	{
		if (is_hash)
			string[length + 1 - index++] = base[xindex][number % 16];
		else
			string[length - 1 - index++] = base[xindex][number % 16];
		number /= 16;
	}
	string[length] = '\0';
	return (string);
}

char	*ft_p_base(unsigned long long number)
{
	int			index;
	int			length;
	char		*string;
	const char	base[17] = "0123456789abcdef";
	int			hsize;

	hsize = 2;
	length = num_length(number, 16, hsize);
	string = (char *)malloc((length + 1) * sizeof(char));
	index = hsize;
	if (!string)
		return (0);
	string[0] = '0';
	string[1] = 'x';
	while (index < length)
	{
		string[length + 1 - index++] = base[number % 16];
		number /= 16;
	}
	string[length] = '\0';
	return (string);
}
