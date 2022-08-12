#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	int	**h;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	char	*addr;
	void	*image;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_fdf
{
	t_mlx	mlx;
	t_map	map;
}	t_fdf;

void	init(t_fdf *fdf)
{
	fdf->mlx.width = 1000;
	fdf->mlx.height = 1000;
	fdf->mlx.endian = 0;
	fdf->mlx.bpp = 32;
	fdf->mlx.size_line = 1000 * 4;
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
				mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win,
					fdf->mlx.image, 0, 0);
				//add_mlx_hook(fdf);
				//draw_win(fdf);
				mlx_loop(fdf->mlx.mlx);
			}
		}
	}
}

int	set_mapheight()
{

	return (0);
}

int	append_line(char **data, t_fdf *fdf)
{
	char	**tmp;
	int		index;

	tmp = (char **)malloc(sizeof(char *) * fdf->mlx->height);
	index = fdf->mlx->height - 1;
	set_mapheight(tmp[index], data);
	while (--index)
	{
		tmp
	}
	fdf->map.h = tmp;
	return (0);
}

int	read_file(char	*file, t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	**data;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		data = ft_split(line, ' ');
		// tmp생성해서 map에 누적저장하는 식으로 쌓는다.
		append_line(data, fdf);
		fdf->mlx.height += 1;
		free(line);
		if (!line)
			break ;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_fdf	fdf;
	
		ft_bzero(&fdf, sizeof(t_fdf));
		read_file(argv[1], &fdf);
		init(&fdf);
		//do_mlx(&fdf);
	}
	else
		printf("error\n");
	return (0);
}
