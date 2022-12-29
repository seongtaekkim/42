/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:23:44 by seongtki          #+#    #+#             */
/*   Updated: 2022/12/29 21:56:58 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# define DEFAULT_COLOR 0x00FF0000
# define CLEAR_COLOR 0x00000000

typedef struct s_bh
{
	int	h;
	int	w;
	int	xbec;
	int	ybec;
}	t_bh;

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	t_point	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_option
{
	t_vec	position;
	int		zoom;
	int		rotate;
	int		exit_code;
	int		projection;
}	t_option;

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
	t_mlx		mlx;
	t_map		map;
	t_option	option;
}	t_fdf;

int		read_file(char	*file, t_fdf *fdf);
void	do_mlx(t_fdf *fdf);
void	do_draw(t_fdf *fdf);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
void	bresenham(t_fdf *fdf, t_point p0, t_point p1);
int		_abs(int n);
int		abs_one(int n);
void	clear_image(t_mlx *mlx, int color);
void	do_exit(t_fdf *fdf);
void	free_map(t_map *map);
void	free_arr2(char **arr);
void	line_free(char **data, char *trim_line, char *line);
float	degree_to_radian(int degree);
void	exit_motion(t_fdf *fdf);
int		key_motion(int keycode, t_fdf *fdf);
void	rotate_x(int *y, int *z, float radian);
void	rotate_y(int *x, int *z, float radian);
void	rotate_z(int *x, int *y, float radian);
void	do_project(t_fdf *fdf, int *x, int *y, int z);

#endif
