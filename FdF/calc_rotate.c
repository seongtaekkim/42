/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:04:54 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/07 18:05:10 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double radian)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(radian) + (*z) * sin(radian);
	*z = -prev_y * sin(radian) + (*z) * cos(radian);
}

void	rotate_y(int *x, int *z, double radian)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(radian) + (*z) * sin(radian);
	*z = -prev_x * sin(radian) + (*z) * cos(radian);
}

void	rotate_z(int *x, int *y, double radian)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(radian) - prev_y * sin(radian);
	*y = prev_x * sin(radian) + prev_y * cos(radian);
}
