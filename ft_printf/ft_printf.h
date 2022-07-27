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
# include <stdarg.h>
#include <stdio.h>
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
	t_bool	p_minus;
	t_bool	p_plus;
	size_t	width;
	size_t	p_width;
	t_bool	zero;
	t_bool	hash;
	t_bool	precision;
	int		type;
}	t_options;

typedef struct s_format
{
	size_t	tot_len;
	t_bool	zero;
	size_t	zero_size;
	size_t	empty_size;
	size_t	type_size;
	t_bool	left_align;
	char	hash_val[3];
	t_bool	is_show_sign;
	t_bool	is_print;
	char	sign;
}	t_format;

int	ft_printf(const char *data, ...);
void	init(t_options *o, t_format *f);
int	set_option(t_options *o, const char *target);
void	set_format(t_options *o, t_format *f);

size_t	ft_strlen(char *str);
char	*ft_strndup(const char *s1, size_t n);

int	c_proc(va_list *ap, t_options *o, t_format *f);
char	*s_proc(va_list *ap, t_options *o, t_format *f);
char	*di_proc(va_list *ap, t_options *o, t_format *f);
char	*u_proc(va_list *ap, t_options *o, t_format *f);
char	*p_proc(va_list *ap, t_options *o, t_format *f);
char	*x_proc(va_list *ap, t_options *o, t_format *f);
char	*x2_proc(va_list *ap, t_options *o, t_format *f);

char	*ft_itou(int n);
char	*ft_utoa(unsigned int n);
char	*ft_nbr_base(unsigned int number, t_bool is_hash, char hash);
char	*ft_p_base(unsigned long long number);
#endif
