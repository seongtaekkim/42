/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:07:47 by susong            #+#    #+#             */
/*   Updated: 2023/02/04 18:50:27 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	key_hook(int keycode, t_mlx *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img);
		exit(0);
	}
	return (0);
}

int	end_hook(t_mlx *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	exit(0);
}

int	ft_exit(int code)
{
	write(2, "Error", 6);
	if (code == 1)
		write(2, " : Argument invalid do it again!", 32);
	if (code == 2)
		write(2, " : name of .rt file is not exist", 32);
	if (code == 4)
		write(2, "system call error : Malloc Failed", 34);
	if (code == 5)
		write(2, " : please camera information", 28);
	write(2, "\n", 1);
	exit(code);
}
