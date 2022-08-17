#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

void	init(t_fdf *fdf)
{
	fdf->mlx.width = 1000;
	fdf->mlx.height = 1000;
	fdf->mlx.endian = 0;
	fdf->mlx.bpp = 32;
	fdf->mlx.size_line = 1000 * 4;
	fdf->map.x = 0;
	fdf->map.y = 0;
	fdf->option.zoom = 30;
	fdf->option.projection = 1;
	fdf->option.position.x = fdf->mlx.width / 2;
	fdf->option.position.y = fdf->mlx.height / 2;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_fdf	fdf;
	
		ft_bzero(&fdf, sizeof(t_fdf));
		init(&fdf);
		read_file(argv[1], &fdf);
		do_mlx(&fdf);
	}
	else
		printf("error\n");
	return (0);
}
