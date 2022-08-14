/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:23:44 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/14 18:43:31 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# define PI 3.141592

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

typedef struct	s_option
{
	//bool		disp_helper;
	//int			height_mod;
	//t_vec2	pos;
	int		zoom;
	int		rotate;
	//int			angle_mod;
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

char	*get_next_line(int fd);
int		read_file(char	*file, t_fdf *fdf);
void	do_mlx(t_fdf *fdf);
void	do_draw(t_fdf *fdf);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
void	bresenham(t_fdf *fdf, int x0, int y0, int x1, int y1);

#endif
