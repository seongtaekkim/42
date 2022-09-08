/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:56:52 by seongtki          #+#    #+#             */
/*   Updated: 2022/09/07 17:58:06 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

void	init(t_fdf *fdf)
{
	fdf->mlx.width = 1200;
	fdf->mlx.height = 1000;
	fdf->mlx.endian = 0;
	fdf->mlx.bpp = 32;
	fdf->mlx.size_line = 1000 * 4;
	fdf->map.x = 0;
	fdf->map.y = 0;
	fdf->option.zoom = 20;
	fdf->option.projection = 0;
	fdf->option.position.x = fdf->mlx.width / 2;
	fdf->option.position.y = fdf->mlx.height / 2;
	fdf->option.rotate = 0;
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc == 2)
	{
		ft_bzero(&fdf, sizeof(t_fdf));
		init(&fdf);
		read_file(argv[1], &fdf);
		do_mlx(&fdf);
	}
	else
		printf("error\n");
	return (0);
}
