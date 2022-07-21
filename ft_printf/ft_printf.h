/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:06:37 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/23 17:37:09 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

/*typedef enum s_type
{
	c;
	s;
	d;
	i;
	u;
	x;
	x2;
	p;
	t_type_size;
}	t_type;
*/
typedef enum s_bool
{
	true = 1,
	false = 0
}	t_bool;

typedef struct s_options
{
	t_bool	space;
	t_bool	plus;
	t_bool	minus;
	int		width;
	int		p_width;
	t_bool	zero;
	t_bool	hash;
	t_bool	precision;
	char	type;
}	t_options;

typedef struct s_format
{
	int		tot_len;
	t_bool	zero;
	int		zero_size;
	t_bool	left_align;
	char	hash_val[3];
	t_bool	is_show_sign;
}	t_format;

typedef struct s_holder
{
	int				fd;
	char			*line;
	struct s_holder	*prev;
	struct s_holder	*next;
}	t_holder;

int	ft_printf(const char *data, ...);
#endif
