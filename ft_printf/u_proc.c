#include "ft_printf.h"
int	u_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char			*data;
	unsigned int	ret;
	size_t			size;
	ssize_t			prt;

	prt = 0;
	ret = va_arg(*ap, unsigned int);
	data = ft_utoa(ret);
	//printf("\nutoa : %s, ret : %u\n",data, ret);
	size = ft_strlen(data);
	//if (o->p_minus && o->p_width)
	//	o->width = o->p_width;
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
		//printf("\nenmpty : %zu, zero : %zu\n", f->empty_size, f->zero_size);
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

	if (o->p_minus && !o->p_width)
	{
		if (o->width > size)
			f->empty_size = o->width - size;
	}
	//printf("\nenmpty : %zu, zero : %zu\n", f->empty_size, f->zero_size);

	f->type_size = size;
	f->tot_len = size + f->zero_size + f->empty_size;
	
	while (o->width > size)
	{
		prt += write(1, " ", 1);
		o->width += -1;
	}
	*prt_cnt += prt;
	write(1, data, size);
	*prt_cnt += size;
	free(data);	
	
	return (0);
}

