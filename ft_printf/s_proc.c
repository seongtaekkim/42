#include "ft_printf.h"

int	s_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char	*data;
	size_t	size;

	data = va_arg(*ap, char *);
	if (data == (void *)0)
	{
		write(1, "(null)", 6);
		*prt_cnt = *prt_cnt + 6;
		return (0);
	}
	size = ft_strlen(data);
	if (o->precision && !o->p_width)
		size = 0;
	else if (o->precision && (o->p_plus || o->p_minus))
	{
		size = 0;
		o->width = 0;
		f->empty_size = o->p_width;
	}
	else if (o->precision && o->p_width)
	{
		if (o->p_width < size)
			size = o->p_width;
	}
	if (o->width > size)
	{
		if (o->zero && (!o->minus && !o->p_minus))
			f->zero_size = o->width - size;
		f->empty_size = o->width - size - f->zero_size;
		//printf("\nenmpty : %zu, zero : %zu\n", f->empty_size, f->zero_size);
	}
	f->type_size = size;
	f->tot_len = size + f->zero_size + f->empty_size;
	
	int	index;
	index = 0;
	write(1, data, size);
	*prt_cnt = *prt_cnt + size;
	return (0);
}
