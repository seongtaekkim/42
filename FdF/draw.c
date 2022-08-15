/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:51:52 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/15 17:56:16 by seongtki         ###   ########.fr       */
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

void	clear_image(t_mlx *mlx, int color)
{
	int x;
	int y;

	x = 0;
	while (x < mlx->width)
	{
		y = 0;
		while (y < mlx->height)
		{
			put_pixel(mlx, x, y, color);
			++y;
		}
		++x;
	}
}

double	deg_to_rad(int degree)
{
	return (degree * 3.14159265F / 180.0F);
}

double	fpart(double x)
{
	return (x > 0 ? x - (int)x : x - (int)x - 1);
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
	//printf("%d %d -> ", *x, *y);
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
	//printf("%d %d -> ", *x, *y);
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
	//(void)z;
	int theta = 120;
	//int angle = 0 ;
	//rotate_x(y, &z, PI / 6);
	//rotate_y(x, &z, PI / 6);
	rotate_z(x, y, theta * PI / 180);	
	prev_x = *x;
	prev_y = *y;
	//*x = (prev_x - prev_y) * round(cos(PI / 6));
	//*y = (prev_x + prev_y) * round(sin(PI / 6)) - z;
	//printf("%d %d\n", *x, *y);
	//int theta2 = 0;
	
	t_point base;
	base.x = fdf->mlx.width / 2;
	base.y = fdf->mlx.height / 2;
	//*x += base.x;
	//*y += base.y;
	//*x = (prev_x - base.x)*cos(theta*PI/180) - (prev_y - base.y)*sin(theta*PI/180) + base.x;
    //*y = (prev_x - base.x)*sin(theta2*PI/180) + (prev_y - base.y)*cos(theta2*PI/180) + base.y;
	//*x = (1/2) * (prev_y - fdf->map.y / 2) - (1/2 * (prev_x - fdf->map.x / 2));
	//*x = (cos(deg_to_rad(angle)) * (prev_y - fdf->map.y / 2)) - (cos(deg_to_rad(angle)) * (prev_x - fdf->map.x / 2));
	conv_to_iso(x, y, z);	
	//printf("%d %d %d\n", *x, *y, z);
	*x += base.x + 700;
	*y += base.y;
	//*y += base.y / 2;
	//*y = -z * (cos(90) + (sin(45) * (prev_x - fdf->map.x / 2)) + (sin(45) * (prev_y - fdf->map.y / 2)));
	
	//*y = -z * (cos(deg_to_rad(angle * 2)) + (sin(deg_to_rad(angle)) * (prev_x - fdf->map.x / 2)) + (sin(deg_to_rad(angle)) * (prev_y - fdf->map.y / 2)));
(void)fdf;
	//	*x += fdf->map.x / 2 + 400;
	//	//*y += fdf->map.y / 2 + 400;
	
//	printf("*x : %d ", *x);
}
 void		fdf_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
int	ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}
void	draw2(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point pixel1;
	t_point pixel2;
	// iso
//printf("%d, %d\n", p1.x, fdf->map.map[p1.y][p1.x].z);	
//printf("%d, %d\n", p1.x, p1.y);	
	pixel1.z = fdf->map.map[p1.y][p1.x].z * 5;
	
	pixel1.x = p1.x - fdf->map.x / 2;
	pixel1.x *= 30;
	pixel1.x += 500;
	
	pixel1.y = p1.y - fdf->map.y / 2;
	pixel1.y *= 30;
	pixel1.y += 500;
	isometric(fdf, &pixel1.x, &pixel1.y, pixel1.z);
	
	pixel2.z = fdf->map.map[p2.y][p2.x].z * 5;
	
	pixel2.x = p2.x - fdf->map.x / 2;
	pixel2.x *= 30;
	pixel2.x += 500;
	
	pixel2.y = p2.y - fdf->map.y / 2;
	pixel2.y *= 30;
	pixel2.y += 500;
	

	isometric(fdf, &pixel2.x, &pixel2.y, pixel2.z);
	//bresenham(fdf, pixel1.x, pixel1.y, pixel2.x, pixel2.y);	
	/*int	steep;

	steep = ft_abs(pixel2.y - pixel1.y) > ft_abs(pixel2.x - pixel1.x);
	if (steep)
	{
		fdf_swap(&pixel1.x, &pixel1.y);
		fdf_swap(&pixel2.x, &pixel2.y);
	}
	if (pixel1.x > pixel2.x)
	{
		fdf_swap(&pixel1.x, &pixel2.x);
		fdf_swap(&pixel1.y, &pixel2.y);
	}*/
	//if (fdf->mlx.width > pixel1.x && fdf->mlx.width > pixel2.x
	//		&& fdf->mlx.height > pixel1.y && fdf->mlx.height > pixel2.y)

	printf("pixel : %d %d %d %d\n",pixel1.x,pixel1.y, pixel2.x, pixel2.y); 
	bresenham(fdf, pixel1.x, pixel1.y, pixel2.x, pixel2.y);	
	//printf("p1 : (%d, %d, %d), p2 : (%d, %d, %d\n", pixel1.x, pixel1.y,pixel1.z, pixel2.x, pixel2.y, pixel2.z);
}


void	set_position(t_fdf *fdf)
{
	int	index;
	int	jndex;
	index = 0;
	jndex = 0;
	while (fdf->map.y > jndex)
	{
		index = 0;
		while (fdf->map.x > index)
		{
			t_point	p1;
			p1.x = index - 1;
			p1.y = jndex;

			t_point p2;
			p2.x = index;
			p2.y = jndex - 1;
			
			t_point pc;
			pc.x = index;
			pc.y  =jndex;
			
			t_point pc2;
			pc2.x = index;
			pc2.y  =jndex;
		//printf("* %d %d %d -> ", pc.x, pc.y,fdf->map.map[jndex][index].z); 
		if (index != 0)
	draw2(fdf, p1, pc);
		if (jndex != 0)
	draw2(fdf, p2, pc2);	
			//mlx_pixel_put(fdf->mlx.mlx, fdf->mlx.win, index, jndex, 0x0000FF00);
			index++;
			//if (index == 5)
			//	break ;
		}
		jndex++;
		//if (jndex == 1)
		//	break ;
	}

}

void	do_draw(t_fdf *fdf)
{

	//iso
	//position
	//bresen
	mlx_clear_window(fdf->mlx.mlx, fdf->mlx.win);
	set_position(fdf);
}
