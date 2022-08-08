/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:02:03 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 09:27:06 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char			*data;
	unsigned int	ret;
	size_t			size;

	ret = va_arg(*ap, unsigned int);
	if (ret == 0 && o->hash)
		o->hash = false;
	data = ft_nbr_base(ret, o->hash, 'x', 0);
	size = ft_strlen(data);
	set_proc_format_diu(o, f, size);
	if (ret == 0 && o->precision && !o->width && !o->p_width)
	{
		free(data);
		return ;
	}
	if (ret == 0 && o->precision && !o->p_width)
		data[0] = ' ';
	*prt_cnt += do_write(data, size, f);
	free(data);
}

void	x2_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char			*data;
	unsigned int	ret;
	size_t			size;

	ret = va_arg(*ap, unsigned int);
	if (ret == 0 && o->hash)
		o->hash = false;
	data = ft_nbr_base(ret, o->hash, 'X', 1);
	size = ft_strlen(data);
	set_proc_format_diu(o, f, size);
	if (ret == 0 && o->precision && !o->width && !o->p_width)
	{
		free(data);
		return ;
	}
	if (ret == 0 && o->precision && !o->p_width)
		data[0] = ' ';
	*prt_cnt += do_write(data, size, f);
	free(data);
}
