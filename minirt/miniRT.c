/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:04:16 by susong            #+#    #+#             */
/*   Updated: 2023/02/03 16:58:58 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static	void	init_var(int *x, int *y)
{
	*x = 0;
	*y = 0;
	return ;
}

t_mlx	init_mlx(void)
{
	t_mlx	out;

	out.mlx = mlx_init();
	out.win = mlx_new_window(out.mlx, MLX_WIDTH, MLX_HEIGHT, "MINIRT");
	out.img = mlx_new_image(out.mlx, MLX_WIDTH, MLX_HEIGHT);
	out.addr = mlx_get_data_addr(out.img, &out.bits_per_pixel, \
		&out.line_length, &out.endian);
	return (out);
}

void	mlx_put_pixel(t_mlx *m_mlx, int x, int y, t_color3 color)
{
	char	*dest;
	double	t;
	int		dest_color;

	t = 0.0f;
	if (color.x > 1)
		color.x = 1;
	if (color.y > 1)
		color.y = 1;
	if (color.z > 1)
		color.z = 1;
	dest_color = ((int)(255.0 * color.x) << 16) + \
	((int)(255.0 * color.y) << 8) + (int)(255.0 * color.z);
	dest = m_mlx->addr + (y * m_mlx->line_length + x * \
	(m_mlx->bits_per_pixel / 8));
	*(unsigned int *)dest = dest_color;
	return ;
}

int	main(int argc, char **argv)
{
	t_mlx		m_mlx;
	t_scene		m_scene;
	t_ray		ray;
	int			x;
	int			y;

	if (argc != 2 || name_check(argv[1]))
		ft_exit(1);
	m_scene = init_scene(argv[1]);
	m_mlx = init_mlx();
	init_var(&x, &y);
	while (y++ < MLX_HEIGHT)
	{
		while (x++ < MLX_WIDTH)
		{
			ray = ray_init(m_scene, x, y);
			mlx_put_pixel(&m_mlx, x, y, make_color(m_scene, ray));
		}
		x = 0;
	}
	mlx_put_image_to_window(m_mlx.mlx, m_mlx.win, m_mlx.img, 0, 0);
	mlx_key_hook(m_mlx.win, key_hook, &m_mlx);
	mlx_hook(m_mlx.win, 17, 0, end_hook, &m_mlx);
	mlx_loop(m_mlx.mlx);
	return (0);
}
