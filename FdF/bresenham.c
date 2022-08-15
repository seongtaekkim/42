/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:07:22 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/15 17:44:20 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
	int	h;
	int	w;
	int	f0;
	int	f1;
	int	ybec;
	int	xbec;


	//int tmp = 0;
	w = (x1 - x0) > 0 ? (x1 - x0) : (x0 - x1);
	h = (y1 - y0) > 0 ? (y1 - y0) : (y0 - y1);
	//printf("( %d , %d )\n", x0, y0);
	put_pixel(&fdf->mlx, x0, y0, 0x00FF0000);
	xbec = x1 > x0 ? 1 : -1;
	ybec = y1 > y0 ? 1 : -1;
	// 1,4,5,8
	if (w > h)
	{

		f0 = 2 * h - w;
		while (x1 != x0 )
		{
			if (f0 > 0)
			{
				f1 = f0 + 2 * (h - w);
				y0 += ybec;
			}
			else 
				f1 = f0 + 2 * h;
			f0 = f1;
			x0 += xbec;
			put_pixel(&fdf->mlx, x0, y0, 0x00FF0000);
			//printf("( %d , %d )\n", x0, x1);
		}
	}
	else
	{	
if (y0 > y1)
		f0 = 2 * w - h;
		while (y1 != y0 )
		{
			if (f0 > 0)
			{
				f1 = f0 + 2 * (w - h);
				x0 += xbec;
			}
			else
				f1 = f0 + 2 * w;
			f0 = f1;
			y0 += ybec;
			put_pixel(&fdf->mlx, x0, y0, 0x00FF0000);
			//printf("( %d , %d )\n", x0, y0);
		}
	}
}

/*
void	bresenham2(int x0, int y0, int x1, int y1)
{
	int	h;
	int	w;
	int	f0;
	int	f1;
	int	ybec;
	int	xbec;


	int tmp = 0;
	w = (x1 - x0) > 0 ? (x1 - x0) : (x0 - x1);
	h = (y1 - y0) > 0 ? (y1 - y0) : (y0 - y1);
	printf("( %d , %d )\n", x0, y0);
	//put_pixel(&fdf->mlx, x0, y0, 0x00FF0000);
	xbec = x1 > x0 ? 1 : -1;
	ybec = y1 > y0 ? 1 : -1;
	printf("h: %d w: %d\n",h, w);
	// 1,4,5,8
	if (w > h)
	{
		f0 = 2 * h - w;
		while (x1 != x0)
		{
			if (f0 > 0)
			{
				f1 = f0 + 2 * (h - w);
				y0 += ybec;
			}
			else 
				f1 = f0 + 2 * h;
			f0 = f1;
			x0 += xbec;
			//put_pixel(&fdf->mlx, x0, y0, 0x00FF0000);
			printf("( %d , %d )\n", x0, x1);
		}
	}
	else
	{	if (y0 > y1)
		{
			tmp = x1;
		x1 = x0;
		x0 = tmp;
		tmp = y1;
		y1 = y0;
		y0 = tmp;

		}
	printf("%d %d %d %d\n", x0,y0,x1,y1);
		f0 = 2 * w - h;
		while (y1 != y0 && y1 >= y0)
		{
			if (f0 > 0)
			{
				f1 = f0 + 2 * (w - h);
				x0 += xbec;
			}
			else
				f1 = f0 + 2 * w;
			f0 = f1;
			y0 += ybec;
	//put_pixel(&fdf->mlx, x0, y0, 0x00FF0000);
			printf("( %d , %d )\n", x0, y0);
		}
	}
}

int	main(void)
{
	bresenham2(397, 290, 371, 305);
}
*/
