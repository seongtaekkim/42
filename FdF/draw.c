/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:51:52 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/18 14:37:57 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int		*img;

	img = (int*)mlx->addr;
	if (x >= 0 && x < mlx->width && y >= 0 && y < mlx->height)
	{
		img[x + mlx->width * y] = color;
	}
}

void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + (*z) * sin(alpha);
	*z = -prev_y * sin(alpha) + (*z) * cos(alpha);
}

 void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + (*z) * sin(beta);
	*z = -prev_x * sin(beta) + (*z) * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

void	conv_to_iso(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.5236);
	*y = (prev_x + prev_y) * sin(0.5236) - z;
}

void	isometric(t_fdf *fdf, int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;
	int theta = fdf->option.rotate;
	//rotate_x(y, &z, PI / 6);
	//rotate_y(x, &z, PI / 6);
	rotate_z(x, y, theta * PI / 180);
	prev_x = *x;
	prev_y = *y;

	conv_to_iso(x, y, z);
	*x += fdf->mlx.width / 2 ;
	*y += fdf->mlx.height / 2 - 300;
}

void	draw2(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point pixel1;
	t_point pixel2;

	pixel1.x = p1.x - fdf->map.x / 2;
	pixel1.x *= fdf->option.zoom;
	pixel1.z = fdf->map.map[p1.y][p1.x].z * fdf->option.zoom / 4;
	pixel1.y = p1.y - fdf->map.y / 2;
	pixel1.y *= fdf->option.zoom;
	isometric(fdf, &pixel1.x, &pixel1.y, pixel1.z);
	pixel2.x = p2.x - fdf->map.x / 2;
	pixel2.x *= fdf->option.zoom;
	pixel2.z = fdf->map.map[p2.y][p2.x].z * fdf->option.zoom / 4;
	pixel2.y = p2.y - fdf->map.y / 2;
	pixel2.y *= fdf->option.zoom;
	isometric(fdf, &pixel2.x, &pixel2.y, pixel2.z);
	pixel1.x += fdf->option.position.x;
	pixel1.y += fdf->option.position.y;
	pixel2.x += fdf->option.position.x;
	pixel2.y += fdf->option.position.y;
	bresenham(fdf, pixel1, pixel2);
}


void	set_position(t_fdf *fdf)
{
	int		index;
	int		jndex;
	t_point	p1;
	t_point	p2;
	t_point	p3;

	jndex = 0;
	while (fdf->map.y > jndex)
	{
		index = 0;
		while (fdf->map.x > index)
		{
			p1.x = index - 1;
			p1.y = jndex;
			p2.x = index;
			p2.y = jndex - 1;
			p3.x = index;
			p3.y = jndex;
			if (index != 0)
				draw2(fdf, p1, p3);
			if (jndex != 0)
				draw2(fdf, p2, p3);
			index++;
		}
		jndex++;
	}
}

void	do_draw(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx.mlx, fdf->mlx.win);
	clear_image(&fdf->mlx, 0x00000000);
	set_position(fdf);
}
