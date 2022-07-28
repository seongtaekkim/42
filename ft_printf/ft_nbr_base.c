/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:03:06 by seongtki          #+#    #+#             */
/*   Updated: 2022/06/06 17:01:35 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	compute_number_length(unsigned long long number, int radix, int hsize)
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
	int			hsize;

	if (is_hash)
		hsize = 2;
	else
		hsize = 0;
	length = compute_number_length(number, 16, hsize);
	string = (char *)malloc((length + 1) * sizeof(char));
	index = hsize;
	if (!string)
		return (0);
	if (hsize)
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
	length = compute_number_length(number, 16, hsize);
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
