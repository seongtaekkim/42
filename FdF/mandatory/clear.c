/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:41:58 by seongtki          #+#    #+#             */
/*   Updated: 2022/12/31 17:34:55 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_mlx *mlx, unsigned int color)
{
	int	x;
	int	y;

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

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	free_arr2(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	line_free(char **data, char *trim_line, char *line)
{
	free(line);
	free(trim_line);
	free_arr2(data);
}

void	do_exit(t_fdf *fdf)
{
	free_map(&fdf->map);
	if (fdf->mlx.mlx && fdf->mlx.win)
		mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.win);
	if (fdf->mlx.mlx && fdf->mlx.image)
		mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.image);
	exit(0);
}
