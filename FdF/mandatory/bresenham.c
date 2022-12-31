/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:07:22 by seongtki          #+#    #+#             */
/*   Updated: 2022/12/31 16:20:56 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	octagonal2367(t_fdf *fdf, t_point p0, t_point p1, t_bh bh)
{
	int	f0;
	int	f1;

	f0 = 2 * bh.w - bh.h;
	while (p1.y != p0.y)
	{
		if (f0 > 0)
		{
			f1 = f0 + 2 * (bh.w - bh.h);
			p0.x += bh.xbec;
		}
		else
			f1 = f0 + 2 * bh.w;
		f0 = f1;
		p0.y += bh.ybec;
		put_pixel(&fdf->mlx, p0.x, p0.y, p0.color);
	}
}

static void	octagonal1458(t_fdf *fdf, t_point p0, t_point p1, t_bh bh)
{
	int	f0;
	int	f1;

	f0 = 2 * bh.h - bh.w;
	while (p1.x != p0.x)
	{
		if (f0 > 0)
		{
			f1 = f0 + 2 * (bh.h - bh.w);
			p0.y += bh.ybec;
		}
		else
			f1 = f0 + 2 * bh.h;
		f0 = f1;
		p0.x += bh.xbec;
		put_pixel(&fdf->mlx, p0.x, p0.y, p0.color);
	}
}

void	bresenham(t_fdf *fdf, t_point p0, t_point p1)
{	
	t_bh	bh;

	bh.w = _abs(p1.x - p0.x);
	bh.h = _abs(p1.y - p0.y);
	bh.xbec = abs_one(p1.x > p0.x);
	bh.ybec = abs_one(p1.y > p0.y);
	if (bh.w > bh.h)
		octagonal1458(fdf, p0, p1, bh);
	else
		octagonal2367(fdf, p0, p1, bh);
}
