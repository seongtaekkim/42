#include "ft_printf.h"

int	x_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char			*data;
	unsigned int	ret;
	size_t			size;

	ret = va_arg(*ap, unsigned int);
	data = ft_nbr_base(ret, o->hash, 'x', 0);
	size = ft_strlen(data);
	write(1, data, size);
	*prt_cnt += size;
	free(data);
	if (o->width > size)
	{
		if (o->zero && (!o->minus && !o->p_minus))
			f->zero_size = o->width - size;
		f->empty_size = o->width - size - f->zero_size;
		//printf("\nenmpty : %zu, zero : %zu\n", f->empty_size, f->zero_size);
	}
	f->type_size = size;
	f->tot_len = size + f->zero_size + f->empty_size;
	return (0);
}

int	x2_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char			*data;
	unsigned int	ret;
	size_t			size;

	ret = va_arg(*ap, unsigned int);
	data = ft_nbr_base(ret, o->hash, 'X', 1);
	size = ft_strlen(data);
	write(1, data, size);
	*prt_cnt += size;
	free(data);
	if (o->width > size)
	{
		if (o->zero && (!o->minus && !o->p_minus))
			f->zero_size = o->width - size;
		f->empty_size = o->width - size - f->zero_size;
		//printf("\nenmpty : %zu, zero : %zu\n", f->empty_size, f->zero_size);
	}
	f->type_size = size;
	f->tot_len = size + f->zero_size + f->empty_size;
	return (0);
}
