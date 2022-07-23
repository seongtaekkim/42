
#include "ft_printf.h"

char	*c_proc(va_list *ap, t_options *o, t_format *f)
{
	char	*data;
	char	c;
	size_t	size;

	c = va_arg(*ap, unsigned int);
	if (c == 0)
	{
		data = (char *)malloc(sizeof(char));
		data[0] = '\0';
		size = 0;
	}
	else
	{
		data = (char *)malloc(sizeof(char) + 1);
		data[0] = c;
		data[1] = '\0';
		size = 1;
	}
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
	return (data);
}

char	*s_proc(va_list *ap, t_options *o, t_format *f)
{
	char	*data;
	size_t	size;

	data = va_arg(*ap, char *);
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
	return (data);
}

char	*di_proc(va_list *ap, t_options *o, t_format *f)
{
	int		data;
	size_t	size;
	char	*c_data;
	data = va_arg(*ap, int);
	c_data = ft_itou(data);
	/*
	size = ft_strlen(c_data);
	if (!o->procision)
	{
		if (f->is_show_sign)
		{
			if (data >= 0)
				f->sign = '+';
			else
				f->sign = '-';
		}
		else if (o->space)
			if (data >= 0)
				f->sign = ' ';
		if (o->width > (f->is_show_sign + size))
			

	}
	else if (o->precision && !o->p_width)
	{

	}
	else
	{
	}
	*/		



	if (f->is_show_sign)
	{
		if (data >= 0)
			f->sign = '+';
	}
	else if (o->space)
		if (data >= 0)
			f->sign = ' ';
	if (o->precision && o->p_width)
	{
		f->zero = true;
		f->zero_size = o->p_width;
		f->left_align = false;
	}
	return (c_data);
}

char	*u_proc(va_list *ap, t_options *o, t_format *f)
{
	(void)ap;
	(void)o;
	(void)f;
	return (NULL);
}

char	*p_proc(va_list *ap, t_options *o, t_format *f)
{
	(void)ap;
	(void)o;
	(void)f;
	return (NULL);
}

char	*x_proc(va_list *ap, t_options *o, t_format *f)
{
	char			*data;
	unsigned int	ret;
	size_t			size;
	int				negetive;
	ret = va_arg(*ap, unsigned int);
	data = ft_nbr_base(ret, o->hash, 'x');
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
	return (data);
}

char	*x2_proc(va_list *ap, t_options *o, t_format *f)
{
	char			*data;
	unsigned int	ret;
	size_t			size;
	int				negetive;
	ret = va_arg(*ap, unsigned int);
	data = ft_nbr_base(ret, o->hash, 'X');
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
	return (data);
}
