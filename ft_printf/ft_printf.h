/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:00:23 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 09:26:04 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

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
	size_t	width;
	size_t	p_width;
	t_bool	zero;
	t_bool	hash;
	t_bool	precision;
	int		type;
}	t_options;

typedef struct s_format
{
	size_t	zero_size;
	size_t	empty_size;
	size_t	type_size;
	t_bool	left_align;
	char	sign;
}	t_format;

int		ft_printf(const char *data, ...);
ssize_t	do_write(char *data, size_t size, t_format *f);
ssize_t	do_write_c(char data, size_t size, t_format *f);
void	init(t_options *o, t_format *f);
int		set_option(t_options *o, const char *target);
void	set_format(t_options *o, t_format *f);
size_t	ft_strlen(char *str);
t_bool	is_number(char c);
size_t	sub_or_zero(size_t a, size_t b);
char	*ft_strndup(const char *s1, size_t n);
void	c_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt);
void	s_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt);
void	p_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt);
void	di_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt);
void	u_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt);
void	x_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt);
void	x2_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt);
void	per_proc(t_options *o, t_format *f, int *prt_cnt);
void	set_proc_format_p(t_options *o, t_format *f, size_t size);
void	set_proc_format_diu(t_options *o, t_format *f, size_t size);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_nbr_base(unsigned int number, t_bool is_hash,
			char hash, int xindex);
char	*ft_p_base(unsigned long long number);
#endif
