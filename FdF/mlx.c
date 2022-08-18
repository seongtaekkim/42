/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:14:51 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/18 16:04:45 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_motion(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		do_exit(fdf);
	else if (keycode == 69)
	{
		fdf->option.zoom += 2;
		do_draw(fdf);	
		mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.image, 0, 0);

	}
	else if (keycode == 78)
	{
		fdf->option.zoom -= 2;;
		do_draw(fdf);	
		mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.image, 0, 0);

	}
	if (keycode == 123)
	{
		fdf->option.position.x -= 20;
		do_draw(fdf);	
		mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.image, 0, 0);

	}
	if (keycode == 124)
	{
		fdf->option.position.x += 20;
		do_draw(fdf);	
		mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.image, 0, 0);

	}
	if (keycode == 125)
	{
		fdf->option.position.y += 20;
		do_draw(fdf);	
		mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.image, 0, 0);

	}
	if (keycode == 126)
	{
		fdf->option.position.y -= 20;
		do_draw(fdf);	
		mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.image, 0, 0);

	}
	if (keycode == 15)
	{
		fdf->option.rotate += 5;
		do_draw(fdf);	
		mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.image, 0, 0);

	}
	if (keycode == 17)
	{
		fdf->option.rotate -= 5;
		do_draw(fdf);	
		mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.image, 0, 0);

	}





	return (0);
}


void	add_mlx_hook(t_fdf *fdf)
{
	//mlx_key_hook(fdf->mlx.win, mlx_close, fdf);
	mlx_hook(fdf->mlx.win, 2, 0, key_motion, fdf);
}

void	do_mlx(t_fdf *fdf)
{
	fdf->mlx.mlx = mlx_init();
	if (fdf->mlx.mlx != NULL)
	{
		fdf->mlx.win = mlx_new_window(fdf->mlx.mlx, fdf->mlx.width,
									fdf->mlx.height, "FdF");
		if (fdf->mlx.win != NULL)
		{
			fdf->mlx.image = mlx_new_image(fdf->mlx.mlx,
				fdf->mlx.width, fdf->mlx.height);

			if (fdf->mlx.image != NULL)
			{
				fdf->mlx.addr = mlx_get_data_addr(fdf->mlx.image,
					&fdf->mlx.bpp, &fdf->mlx.size_line, &fdf->mlx.endian);
				add_mlx_hook(fdf);
				do_draw(fdf);	
				mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.image, 0, 0);
				mlx_loop(fdf->mlx.mlx);
			}
			
		}
	}
}

