/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_proc.c                                           :+:      :+:    :+:   */
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
	if (o->precision && !o->p_width)
		size = 0;
	else if (o->precision && (o->p_plus || o->p_minus))
	{
		size = 0;
		o->width = 0;
		f->empty_size = o->p_width;
	}
	else if (o->precision && o->p_width)
	{
		if (o->p_width < size)
			size = o->p_width;
	}
	if (o->width > size)
	{
		if (o->zero && (!o->minus && !o->p_minus))
			f->zero_size = o->width - size;
		f->empty_size = o->width - size - f->zero_size;
	}
	f->type_size = size;
}

int	s_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char	*data;
	size_t	size;

	data = va_arg(*ap, char *);
	if (data == (void *)0)
	{
		size = 6;
		data = "(null)";
	}
	else
		size = ft_strlen(data);
	set_proc_format(o, f, size);
	*prt_cnt += do_write(data, f->type_size, f);
	return (0);
}
