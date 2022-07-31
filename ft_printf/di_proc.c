/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:27:31 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 14:38:14 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	set_proc_format_p(t_options *o, t_format *f, size_t size)
{
	if (o->p_minus)
	{
		//if (o->p_width)
		//	f->empty_size = sub_or_zero(o->p_width, size + !(!o->p_minus));
	}
	else
	{
		if (o->width && o->p_width)
		{
			if (o->p_width > size)
				f->zero_size = o->p_width - size;
			if (o->width > o->p_width)
				f->empty_size = sub_or_zero(o->width,
						size + f->zero_size + !(!f->sign));
		}
		else if (!o->width && o->p_width)
			f->zero_size = sub_or_zero(o->p_width, size);
		else if (o->width && !o->p_width)
			f->empty_size = sub_or_zero(o->width, size + !(!f->sign));
	}
}

void	set_proc_format_diu(t_options *o, t_format *f, size_t size)
{
	if (o->precision)
		set_proc_format_p(o, f, size);
	else
	{
		if (o->zero)
			f->zero_size = sub_or_zero(o->width, size + !(!f->sign));
		else
			f->empty_size = sub_or_zero(o->width, size + !(!f->sign));
	}
}

static void	set_proc_format_sign(int ret, t_options *o, t_format *f)
{
	if (ret < 0)
		f->sign = '-';
	if (o->plus || o->p_plus)
	{
		if (ret >= 0)
				f->sign = '+';
	}
	else if (o->space)
		if (ret >= 0)
			f->sign = ' ';
}

int	di_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	int		ret;
	size_t	size;
	char	*data;

	ret = va_arg(*ap, int);
	data = ft_itoa(ret);
	size = ft_strlen(data);
	set_proc_format_sign(ret, o, f);
	set_proc_format_diu(o, f, size);
	if (ret == 0 && o->precision && !o->width && !o->p_width)
	{
		free(data);
		return (0);
	}
	if (ret == 0 && o->precision && o->width && !o->p_width)
		data[0] = ' ';
	*prt_cnt += do_write(data, size, f);
	free(data);
	return (0);
}
