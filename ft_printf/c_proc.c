#include "ft_printf.h"

int	c_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char	c;
	size_t	size;
	ssize_t	prt;

	prt = 0;
	size = 1;
	c = va_arg(*ap, unsigned int);
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
	f->type_size = size;
	f->tot_len = size + f->zero_size + f->empty_size;

	if (f->left_align)
	{
		// 0 + type + ' '
		while (f->zero_size--)
			prt += write(1, "0", 1);
		prt += write(1, &c, 1);
		while (f->empty_size--)
			prt += write(1, " ", 1);
	}
	else
	{
		// ' ' + 0 + type
		while (f->empty_size--)
			prt += write(1, " ", 1);
		while (f->zero_size--)
			prt += write(1, "0", 1);
		prt += write(1, &c, 1);
	}
/*
	while (o->width > size)
	{
		prt += write(1, " ", 1);
		o->width += -1;
	}*/
	*prt_cnt += prt;
	return (0);
}

