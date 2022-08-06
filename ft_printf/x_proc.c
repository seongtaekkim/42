/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:27:31 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 14:38:14 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
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
		return (0);
	}
	if (ret == 0 && o->precision && !o->p_width)
		data[0] = ' ';
	*prt_cnt += do_write(data, size, f);
	free(data);
	return (0);
}

int	x2_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
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
		return (0);
	}
	if (ret == 0 && o->precision && !o->p_width)
		data[0] = ' ';
	*prt_cnt += do_write(data, size, f);
	free(data);
	return (0);
}
