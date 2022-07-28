#include "ft_printf.h"

int	c_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char	c;
	size_t	size;

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
	write(1, &c, 1);
	//write(1, "\0", 1);
	*prt_cnt = *prt_cnt + 1;
	return (0);
}

