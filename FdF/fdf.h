/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:23:44 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/12 18:44:00 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_view
{
	void	*mlx_ptr;
	void	*win_ptr;

}	t_view;

typedef struct s_img
{
	void	*img_ptr;
	void	*data;

}	t_img;

char	*get_next_line(int fd);


#endif
