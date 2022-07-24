
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
	int		ret;
	size_t	size;
	char	*data;
	ret = va_arg(*ap, int);
	data = ft_itou(ret);
	size = ft_strlen(data);

	if (ret < 0)
		f->sign = '-';	
	if (o->plus || o->p_plus)
	{
		if (ret >= 0)
				f->sign = '+';
	}
	else if (o->space)
		if (ret >= 0)
			f->sign = ' ';

	//printf("\nutoa : %s, ret : %u\n",data, ret);
/*	if (o->width > size && !o->p_minus)
	{
		if (o->precision)
		{
			if (o->p_width >= size)
				f->zero_size = o->p_width - size;
		}
		else if (o->zero && (!o->minus && !o->p_minus))
			f->zero_size = o->width - size - !(!f->sign);
		f->empty_size = o->width - size - f->zero_size - !(!f->sign);
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
*/
	if (!o->precision && o->minus)
	{
		if (o->width > (size - !(!f->sign)))
			f->empty_size = o->width - size - !(!f->sign);
	}	
	if (o->p_minus && !o->p_width)
	{
		if (o->width > size)
			f->empty_size = o->width - size - !(!f->sign);
	}

	if (o->precision && !o->p_minus && o->width && o->p_width)
	{
		if (o->p_width > size)
			f->zero_size = o->p_width - size;
		if (o->width > o->p_width && o->width > size)
			f->empty_size = o->width - o->p_width;
		if (o->plus && f->empty_size)
			f->empty_size -= 1;
		if (f->sign == '-' && !o->plus)
			f->tot_len += 1;	
	}

	if (o->precision && o->p_minus &&  o->p_width)
	{
		if (o->p_width > size)
			f->empty_size = o->p_width - size - !(!o->p_minus);
	}


	f->type_size = size;
	f->tot_len +=  size + f->zero_size + f->empty_size + (o->plus || o->space);
	//printf("\nenmpty : %zu, zero : %zu, tot : %zu\n", f->empty_size, f->zero_size, f->tot_len);

	/*if (f->is_show_sign)
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
	}*/
	return (data);
}

char	*u_proc(va_list *ap, t_options *o, t_format *f)
{
	char			*data;
	unsigned int	ret;
	size_t			size;

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
	return (data);
}

char	*p_proc(va_list *ap, t_options *o, t_format *f)
{
	char			*data;
	unsigned long long	ret;
	size_t			size;
	
	ret = va_arg(*ap, unsigned long long);
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
	return (data);
}

char	*x_proc(va_list *ap, t_options *o, t_format *f)
{
	char			*data;
	unsigned int	ret;
	size_t			size;

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
