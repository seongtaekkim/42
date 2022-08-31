/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:45:32 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/21 18:45:34 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	output(char *s)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s);
	str = ft_calloc(size + 1, sizeof(char));
	ft_memcpy(str, s, size);
	str[size] = '\n';
	str[size + 1] = '\0';
	write(1, str, size + 1);
	free(str);
}
