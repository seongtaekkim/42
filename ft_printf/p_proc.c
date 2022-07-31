/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_proc.c                                           :+:      :+:    :+:   */
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
	if (o->width > size && !o->p_minus)
	{
		if (o->precision)
		{
			if (o->p_width >= size)
				f->zero_size = o->p_width - size;
		}
		else if (o->zero && (!o->minus && !o->p_minus))
			f->zero_size = o->width - size;
		f->empty_size = sub_or_zero(o->width - size, f->zero_size);
	}
	else if (o->p_width >= size)
	{
		if (o->p_width > o->width)
			o->width = o->p_width;
		if (o->p_minus)
			f->empty_size = o->p_width - size;
		else
		{
			f->zero_size = o->width - size;
			f->empty_size = sub_or_zero(o->width - size, f->zero_size);
		}
	}
}

int	p_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char					*data;
	unsigned long long		ret;
	size_t					size;

	ret = va_arg(*ap, unsigned long long);
	data = ft_p_base(ret);
	size = ft_strlen(data);
	set_proc_format(o, f, size);
	*prt_cnt += do_write(data, size, f);
	free(data);
	return (0);
}
