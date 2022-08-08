/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:01:36 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 09:27:18 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_proc_format(t_options *o, t_format *f, size_t size)
{
	if (!o->minus && o->zero)
		f->zero_size = sub_or_zero(o->width, size);
	else
		f->empty_size = sub_or_zero(o->width, size + f->zero_size);
	f->type_size = size;
}

void	per_proc(t_options *o, t_format *f, int *prt_cnt)
{
	set_proc_format(o, f, 1);
	*prt_cnt += do_write_c('%', 1, f);
}
