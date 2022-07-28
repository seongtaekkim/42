#include "ft_printf.h"

int	p_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char			*data;
	long long	ret;
	size_t			size;
	ssize_t		prt;

	prt = 0;
	ret = va_arg(*ap, long long);
	/*if (ret == NULL)
	{
		write(1, "(null)", 6);
		*prt_cnt = *prt_cnt + 1;
		return (0);
	}*/
	data = ft_p_base(ret);
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
	*prt_cnt += prt;
	write(1, data, size);
	*prt_cnt = *prt_cnt + size;
	free(data);
	return (0);
}
