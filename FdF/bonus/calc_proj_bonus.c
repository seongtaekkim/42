/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_proj_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:40:42 by seongtki          #+#    #+#             */
/*   Updated: 2022/12/31 17:56:25 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
	int	theta;

	theta = fdf->option.rotate;
	rotate_x(y, &z, degree_to_radian(theta));
	rotate_y(x, &z, degree_to_radian(theta));
	rotate_z(x, y, degree_to_radian(theta));
	conv_to_iso(x, y, z);
}

static void	orthographic(t_fdf *fdf, int *x, int *y, int z)
{
	int	theta;

	theta = fdf->option.rotate;
	rotate_x(y, &z, degree_to_radian(theta));
	rotate_y(x, &z, degree_to_radian(theta));
	rotate_z(x, y, degree_to_radian(theta));
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
