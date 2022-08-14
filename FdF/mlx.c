/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:14:51 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/14 17:59:40 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
				//add_mlx_hook(fdf);
				do_draw(fdf);	
				mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.image, 0, 0);
				mlx_loop(fdf->mlx.mlx);
			}
			
		}
	}
}

