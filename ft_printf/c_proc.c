/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:27:31 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 14:38:14 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_proc_format(t_options *o, t_format *f, size_t size)
{
	if (o->precision && o->p_width)
		if (o->p_minus || o->p_plus)
			o->width = o->p_width;
	if (o->width > size)
	{
		if (o->zero && (!o->minus && !o->p_minus))
			f->zero_size = o->width - size;
		f->empty_size = o->width - size - f->zero_size;
		if (size == 0 && f->empty_size)
			f->empty_size -= 1;
	}
}

int	c_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char	c;
	size_t	size;

	size = 1;
	c = va_arg(*ap, unsigned int);
	set_proc_format(o, f, size);
	*prt_cnt += do_write_c(c, size, f);
	return (0);
}
