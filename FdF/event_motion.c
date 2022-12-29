/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:54:39 by seongtki          #+#    #+#             */
/*   Updated: 2022/12/29 21:55:33 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_motion_move(int keycode, t_fdf *fdf)
{
	if (keycode == 123)
		fdf->option.position.x -= 20;
	if (keycode == 124)
		fdf->option.position.x += 20;
	if (keycode == 125)
		fdf->option.position.y += 20;
	if (keycode == 126)
		fdf->option.position.y -= 20;
	if (keycode == 35)
	{
		fdf->option.projection ^= 1;
		fdf->option.rotate = 0;
	}
}

static void	key_motion_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == 15)
		fdf->option.rotate += 5;
	if (keycode == 17)
		fdf->option.rotate -= 5;
}

static void	key_motion_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 69)
		fdf->option.zoom += 2;
	if (keycode == 78)
		fdf->option.zoom -= 2;
}

int	key_motion(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		do_exit(fdf);
	else
	{
		key_motion_move(keycode, fdf);
		key_motion_rotate(keycode, fdf);
		key_motion_zoom(keycode, fdf);
		do_draw(fdf);
		mlx_put_image_to_window(fdf->mlx.mlx,
			fdf->mlx.win, fdf->mlx.image, 0, 0);
	}
	return (0);
}

void	exit_motion(t_fdf *fdf)
{
	do_exit(fdf);
}
