/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:48:14 by seongtki          #+#    #+#             */
/*   Updated: 2022/12/28 16:01:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen2(const char **s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int	ft_strlen2_ncon(char **s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}
