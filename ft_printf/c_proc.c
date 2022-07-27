#include "ft_printf.h"

int	c_proc(va_list *ap, t_options *o, t_format *f)
{
	char	*data;
	char	c;
	size_t	size;

	c = va_arg(*ap, unsigned int);
	/*if (c == 0)
	{
		data = (char *)malloc(sizeof(char));
		data[0] = '\0';
		size = 0;
	}
	else
	{*/
		data = (char *)malloc(sizeof(char) + 1);
		data[0] = c;
		data[1] = '\0';
		size = 1;
	//}
	//	printf("dddd : %d\n", printf("%s","\0\0"));
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
	return (0);
}

