/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:00:33 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 09:24:02 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_proc_format(t_options *o, t_format *f, size_t size)
{
	if (o->width > size)
	{
		if (o->zero && !o->minus)
			f->zero_size = sub_or_zero(o->width, size);
		f->empty_size = sub_or_zero(o->width, size + f->zero_size);
	}
}

void	c_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char	c;
	size_t	size;

	size = 1;
	c = va_arg(*ap, unsigned int);
	set_proc_format(o, f, size);
	*prt_cnt += do_write_c(c, size, f);
}
