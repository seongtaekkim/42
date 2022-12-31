/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:13:21 by seongtki          #+#    #+#             */
/*   Updated: 2022/12/31 17:56:51 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	is_base(char str, char *base)
{
	int		index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == str)
			return (index);
		index++;
	}
	return (-1);
}

static int	is_space(char c)
{
	int	flag;

	flag = (c == ' ' || c == '\n' || c == '\r');
	flag += (c == '\t' || c == '\v' || c == '\f');
	return (flag);
}

static int	chk_base(char *str)
{
	int		index;
	int		jndex;

	if (*str == '\0' || ft_strlen(str) == 1)
		return (0);
	index = 0;
	jndex = 1;
	while (str[index] != '\0')
	{
		jndex = 0;
		while (str[jndex] != '\0')
		{
			if (str[index] == str[jndex] && index != jndex)
				return (0);
			jndex++;
		}
		if (is_space(str[index]) || str[index] == '+' || str[index] == '-')
			return (0);
		index++;
	}
	return (1);
}

static int	ft_atoi_base(char *str, char *base)
{
	int		length;
	int		result;
	int		sign;

	sign = 1;
	result = 0;
	if (!chk_base(base))
		return (0);
	length = ft_strlen(base);
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str != '\0')
	{
		if (is_base(*str, base) > -1)
		{
			result = result * length;
			result = result + is_base(*str++, base);
		}
		else
			break ;
	}
	return (result * sign);
}

int	str_to_hexa(char *str)
{
	char	*tmp;
	int		result;

	tmp = ft_substr(str, 2, ft_strlen(str) - 2);
	result = ft_atoi_base(tmp, "0123456789abcdef");
	if (result == 0)
		result = ft_atoi_base(tmp, "0123456789ABCDEF");
	free(tmp);
	return (result);
}
