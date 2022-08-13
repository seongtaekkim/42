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
	int	x;
	int	y;
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
	fdf->mlx.size_line = 500 * 4;
	fdf->map.x = 0;
	fdf->map.y = 0;
}

void	bresenham(int x0, int y0, int x1, int y1)
{
	int	h;
	int	w;
	int	f0;
	int	f1;
	int	ybec;
	int	xbec;

	w = (x1 - x0) > 0 ? (x1 - x0) : (x0 - x1);
	h = (y1 - y0) > 0 ? (y1 - y0) : (y0 - y1);
	xbec = x1 > 0 ? 1 : -1;
	ybec = y1 > 0 ? 1 : -1;
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
		}
	}
	else
	{
		f0 = 2 * w - h;
		while (y1 != y0)
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
		}
	}
}

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int		*img;

	img = (int*)mlx->addr;
//x += mlx->width / 2;
//	y += mlx->height / 2;
// map을 벡터로 변환하면서 벡터의 값들들 실제 표출되는 좌표로 변환을 하면 될듯
// 좌표로 변환을 하면서 직선방정식으로 변환하면서 한 직선 당 while로 putpixcel을 호출하면 될거같다.
	if (x >= 0 && x < mlx->width && y >= 0 && y < mlx->height)
	{
	x *= 11.3;
	x += mlx->width / 2;
	y *= 11.3;	
	y += mlx->height / 2;
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
				int	index;
				int	jndex;
				index = 0;
				jndex = 0;
			mlx_clear_window(fdf->mlx.mlx, fdf->mlx.win);
				while (fdf->map.y > jndex)
				{
					index = 0;
					while (fdf->map.x > index)
					{
						//my_mlx_pixel_put(fdf, index, jndex, 0x00FFFF00);
						put_pixel(&fdf->mlx, index, jndex, 0x00FF0000);
						//mlx_pixel_put(fdf->mlx.mlx, fdf->mlx.win, index, jndex, 0x0000FF00);
						index++;
					}
					jndex++;
				}
				mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.image, 0, 0);
				//add_mlx_hook(fdf);
				//draw_win(fdf);
				mlx_loop(fdf->mlx.mlx);
			}
		}
	}
}

int	*set_mapheight(char **data, t_fdf *fdf)
{
	int	*tmp;
	int	index;

	index = 0;
	tmp = (int *)malloc(sizeof(int) * fdf->map.x); 
	while (data[index])
	{
		tmp[index] = ft_atoi(data[index]);
		index++;
	}
	return (tmp);
}

int	append_line(char **data, t_fdf *fdf)
{
	int	**tmp;
	int	index;
	
	tmp = (int **)malloc(sizeof(int *) * fdf->map.y);
	index = fdf->map.y - 1;
	tmp[index] = set_mapheight(data, fdf);
	while (--index >= 0)
	{
		tmp[index] = fdf->map.h[index];
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
		// tmp생성해서 map에 누적저장하는 식으로 쌓는다.
		free(line);
		if (!line)
			break ;
		data = ft_split(line, ' ');
		int	index = 0;
		while (data[index])
			index++;
		fdf->map.x = index;
		fdf->map.y += 1;
		append_line(data, fdf);
	}
	return (0);
}

void	print_map(t_fdf *fdf)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	printf("%d", fdf->map.y);
}
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_fdf	fdf;
	
		ft_bzero(&fdf, sizeof(t_fdf));
		init(&fdf);
		read_file(argv[1], &fdf);
		//print_map(&fdf);
		
		do_mlx(&fdf);
	}
	else
		printf("error\n");
	return (0);
}
