/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:07:22 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/18 11:11:13 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_fdf *fdf, t_point p0, t_point p1)
{
	int	h;
	int	w;
	int	f0;
	int	f1;
	int	ybec;
	int	xbec;

	w = _abs(p1.x - p0.x);
	h = _abs(p1.y - p0.y);
	//printf("( %d , %d )\n", x0, y0);
	put_pixel(&fdf->mlx, p0.x, p0.y, 0x00FF0000);
	xbec = abs_one(p1.x > p0.x);
	ybec = abs_one(p1.y > p0.y);
	// 1,4,5,8
	if (w > h)
	{
		f0 = 2 * h - w;
		while (p1.x != p0.x )
		{
			if (f0 > 0)
			{
				f1 = f0 + 2 * (h - w);
				p0.y += ybec;
			}
			else 
				f1 = f0 + 2 * h;
			f0 = f1;
			p0.x += xbec;
			put_pixel(&fdf->mlx, p0.x, p0.y, 0x00FF0000);
			//printf("1( %d , %d )\n", p0.x, p1.x);
			//break ;
		}
	}
	else
	{	
		f0 = 2 * w - h;
		while (p1.y != p0.y)
		{
			if (f0 > 0)
			{
				f1 = f0 + 2 * (w - h);
				p0.x += xbec;
			}
			else
				f1 = f0 + 2 * w;
			f0 = f1;
			p0.y += ybec;
			put_pixel(&fdf->mlx, p0.x, p0.y, 0x00FF0000);
			//printf("2( %d , %d )\n", p0.y, p1.y);
			//break ;
		}
	}
}
