/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_proj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:40:42 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/07 17:42:08 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	conv_to_iso(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;
	int	degree;

	degree = 30;
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(degree_to_radian(degree));
	*y = (prev_x + prev_y + 1) * sin(degree_to_radian(degree)) - z;
}

static void	isometric(t_fdf *fdf, int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;
	int	theta;

	theta = fdf->option.rotate;
	rotate_x(y, &z, degree_to_radian(theta));
	rotate_y(x, &z, degree_to_radian(theta));
	rotate_z(x, y, degree_to_radian(theta));
	prev_x = *x;
	prev_y = *y;
	conv_to_iso(x, y, z);
}

static void	orthographic(t_fdf *fdf, int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;
	int	theta;

	theta = fdf->option.rotate;
	rotate_x(y, &z, degree_to_radian(theta));
	rotate_y(x, &z, degree_to_radian(theta));
	rotate_z(x, y, degree_to_radian(theta));
	prev_x = *x;
	prev_y = *y;
}

void	do_project(t_fdf *fdf, int *x, int *y, int z)
{
	if (fdf->option.projection == 0)
		isometric(fdf, x, y, z);
	else if (fdf->option.projection == 1)
		orthographic(fdf, x, y, z);
	else
		return ;
}
