/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:01:04 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 09:23:38 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	do_write_c(char data, size_t size, t_format *f)
{
	ssize_t	prt;

	prt = 0;
	if (f->left_align)
	{
		while (f->zero_size--)
			prt += write(1, "0", 1);
		prt += write(1, &data, size);
		while (f->empty_size--)
			prt += write(1, " ", 1);
	}
	else
	{
		while (f->empty_size--)
			prt += write(1, " ", 1);
		while (f->zero_size--)
			prt += write(1, "0", 1);
		prt += write(1, &data, size);
	}
	return (prt);
}

ssize_t	do_write(char *data, size_t size, t_format *f)
{
	ssize_t	prt;

	prt = 0;
	if (f->left_align)
	{
		if (f->sign)
			prt += write(1, &(f->sign), 1);
		while (f->zero_size--)
			prt += write(1, "0", 1);
		prt += write(1, data, size);
		while (f->empty_size--)
			prt += write(1, " ", 1);
	}
	else
	{
		while (f->empty_size--)
			prt += write(1, " ", 1);
		if (f->sign)
			prt += write(1, &(f->sign), 1);
		while (f->zero_size--)
			prt += write(1, "0", 1);
		prt += write(1, data, size);
	}
	return (prt);
}

static int	set_print_data(t_format *f, t_options *o, va_list *ap, int *prt_cnt)
{
	void	(*fp[8])(va_list *, t_options *, t_format *, int *);

	fp[0] = &c_proc;
	fp[1] = &s_proc;
	fp[2] = &di_proc;
	fp[3] = &di_proc;
	fp[4] = &u_proc;
	fp[5] = &x_proc;
	fp[6] = &x2_proc;
	fp[7] = &p_proc;
	set_format(o, f);
	(*fp[o->type])(ap, o, f, prt_cnt);
	return (0);
}

static int	do_printf(va_list *ap, const char *format_syntax, int *prt_cnt)
{
	t_options	options;
	t_format	format;
	int			format_len;
	char		type;

	init(&options, &format);
	format_len = set_option(&options, format_syntax);
	type = format_syntax[format_len - 1];
	if (type == '%')
	{
		set_format(&options, &format);
		per_proc(&options, &format, prt_cnt);
	}
	else
		set_print_data(&format, &options, ap, prt_cnt);
	return (format_len);
}

int	ft_printf(const char *data, ...)
{
	va_list	ap;
	int		i;
	int		prt_cnt;

	i = 0;
	prt_cnt = 0;
	va_start(ap, data);
	while (data[i])
	{
		if (data[i] == '%')
		{
			i++;
			if (data[i])
				i += do_printf(&ap, &data[i], &prt_cnt);
		}
		else
			prt_cnt += write(1, &(data[i++]), 1);
	}
	va_end(ap);
	return (prt_cnt);
}
