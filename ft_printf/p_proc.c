#include "ft_printf.h"

int	p_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char			*data;
	long long	ret;
	size_t			size;
	ssize_t		prt;

	prt = 0;
	ret = va_arg(*ap, long long);
	data = ft_p_base(ret);
	size = ft_strlen(data);
	if (o->width > size && !o->p_minus)
	{
		if (o->precision)
		{
			if (o->p_width >= size)
				f->zero_size = o->p_width - size;
		}
		else if (o->zero && (!o->minus && !o->p_minus))
			f->zero_size = o->width - size;
		f->empty_size = o->width - size - f->zero_size;
	}
	else if (o->p_width >= size)
	{
		if (o->p_width > o->width)
			o->width = o->p_width;
		if (o->p_minus)
		{
			f->empty_size = o->p_width - size;
		}
		else
		{
			f->zero_size = o->width - size;
			f->empty_size = o->width - size - f->zero_size;
		}
	}

	f->type_size = size;
	f->tot_len = size + f->zero_size + f->empty_size;



	if (f->left_align)
	{
		// 0 + type + ' '
		while (f->zero_size--)
			prt += write(1, "0", 1);
		prt += write(1, data, size);
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
		prt += write(1, data, size);
	}

	*prt_cnt += prt;
	//write(1, data, size);
	//*prt_cnt = *prt_cnt + size;
	free(data);
	return (0);
}
