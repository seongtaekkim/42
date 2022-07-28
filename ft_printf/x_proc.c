#include "ft_printf.h"

int	x_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char			*data;
	unsigned int	ret;
	size_t			size;
	ssize_t			prt;

	prt = 0;
	ret = va_arg(*ap, unsigned int);
	data = ft_nbr_base(ret, o->hash, 'x', 0);
	size = ft_strlen(data);
	if (o->width > size)
	{
		if (o->zero && (!o->minus && !o->p_minus))
			f->zero_size = o->width - size;
		f->empty_size = o->width - size - f->zero_size;
	}
	f->type_size = size;
	f->tot_len = size + f->zero_size + f->empty_size;

	while (o->width > size)
	{
		prt += write(1, " ", 1);
		o->width += -1;
	}
	while (o->p_width > size)
	{
		prt += write(1, "0", 1);
		o->p_width--;
	}
	while (f->zero_size--)
	{
		prt += write(1, "0", 1);
	}
	*prt_cnt += prt;
	write(1, data, size);
	*prt_cnt += size;
	free(data);
	return (0);
}

int	x2_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char			*data;
	unsigned int	ret;
	size_t			size;
	ssize_t			prt;

	prt = 0;
	ret = va_arg(*ap, unsigned int);
	data = ft_nbr_base(ret, o->hash, 'X', 1);
	size = ft_strlen(data);
	if (o->width > size)
	{
		if (o->zero && (!o->minus && !o->p_minus))
			f->zero_size = o->width - size;
		f->empty_size = o->width - size - f->zero_size;
		//printf("\nenmpty : %zu, zero : %zu\n", f->empty_size, f->zero_size);
	}
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
