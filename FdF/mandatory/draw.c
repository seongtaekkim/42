/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:51:52 by seongtki          #+#    #+#             */
/*   Updated: 2022/12/31 17:45:18 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_mlx *mlx, int x, int y, unsigned int color)
{
	int		*img;

	img = (int *)mlx->addr;
	if (x >= 0 && x < mlx->width && y >= 0 && y < mlx->height)
	{
		img[x + mlx->width * y] = color;
	}
}

static void	draw2(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point	pixel1;
	t_point	pixel2;

	pixel1.color = fdf->map.map[p1.y][p1.x].color;
	pixel1.x = p1.x - fdf->map.x / 2;
	pixel1.x *= fdf->option.zoom;
	pixel1.z = fdf->map.map[p1.y][p1.x].z * fdf->option.zoom / 4;
	pixel1.y = p1.y - fdf->map.y / 2;
	pixel1.y *= fdf->option.zoom;
	do_project(fdf, &pixel1.x, &pixel1.y, pixel1.z);
	pixel2.color = fdf->map.map[p2.y][p2.x].color;
	pixel2.x = p2.x - fdf->map.x / 2;
	pixel2.x *= fdf->option.zoom;
	pixel2.z = fdf->map.map[p2.y][p2.x].z * fdf->option.zoom / 4;
	pixel2.y = p2.y - fdf->map.y / 2;
	pixel2.y *= fdf->option.zoom;
	do_project(fdf, &pixel2.x, &pixel2.y, pixel2.z);
	pixel1.x += fdf->option.position.x;
	pixel1.y += fdf->option.position.y;
	pixel2.x += fdf->option.position.x;
	pixel2.y += fdf->option.position.y;
	bresenham(fdf, pixel1, pixel2);
}

static void	set_position(t_fdf *fdf, int index, int jndex)
{
	t_point	p1;
	t_point	p2;
	t_point	p3;

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
	clear_image(&fdf->mlx, CLEAR_COLOR);
	set_position(fdf, 0, 0);
}
