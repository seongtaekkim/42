/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_setting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:01:12 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 09:15:56 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_type(char data)
{
	const char	*type = "csdiuxXp%";
	int			index;

	index = 0;
	while (type[index])
	{
		if (type[index] == data)
			return (index);
		index++;
	}
	return (-1);
}

void	init(t_options *o, t_format *f)
{
	o->space = false;
	o->plus = false;
	o->minus = false;
	o->width = 0;
	o->p_width = 0;
	o->zero = false;
	o->hash = false;
	o->precision = false;
	o->type = 0;
	f->zero_size = 0;
	f->empty_size = 0;
	f->type_size = 0;
	f->left_align = false;
	f->sign = 0;
}

static void	set_option2(t_options *o, char data)
{
	if (o->precision == false && is_number(data))
		o->width = o->width * 10 + data - '0';
	if (o->precision == true && is_number(data))
		o->p_width = o->p_width * 10 + data - '0';
	if ('.' == data)
		o->precision = true;
	if (' ' == data)
		o->space = true;
	if ('+' == data)
		o->plus = true;
	if ('-' == data)
		o->minus = true;
	if ('#' == data)
		o->hash = true;
}

int	set_option(t_options *o, const char *target)
{
	int		index;
	char	data;

	index = 0;
	while (target[index])
	{
		data = target[index];
		set_option2(o, data);
		if ('0' == data && !is_number(target[index - 1]) && !o->precision)
			o->zero = true;
		if (!is_number(data) && get_type(data) > -1)
		{
			o->type = get_type(data);
			index++;
			break ;
		}
		index++;
	}
	return (index);
}

void	set_format(t_options *o, t_format *f)
{
	if (o->minus)
		f->left_align = true;
}
