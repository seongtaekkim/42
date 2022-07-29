#include "ft_printf.h"


int	di_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	int		ret;
	size_t	size;
	char	*data;
	ssize_t	prt;

	prt = 0;
	ret = va_arg(*ap, int);
	data = ft_itou(ret);
	size = ft_strlen(data);

	if (ret < 0)
	{
		f->sign = '-';
	}
	if (o->plus || o->p_plus)
	{
		if (ret >= 0)
				f->sign = '+';
	}
	else if (o->space)
		if (ret >= 0)
			f->sign = ' ';

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
	if (o->precision && !o->p_minus && o->p_width)
	{
		if (o->p_width > size)
			f->zero_size = o->p_width - size - !(!o->p_minus);
	}
	f->type_size = size;
	f->tot_len +=  size + f->zero_size + f->empty_size + (o->plus || o->space);
	
	if ( data[0] == '0' && size == 1 && o->precision && !o->width && !o->p_width)
	{
		free(data);
		return (0);
	}

	if (f->left_align)
	{
		// sign + 0 + type + ' '
		if (f->sign == '-')
			prt += write(1, "-", 1);
		
		while (f->zero_size--)
			prt += write(1, "0", 1);
		/*while (o->precision && !o->width && o->p_width > size)
		{
			prt += write(1, "0", 1);
			o->p_width--;
		}*/
		prt += write(1, data, size);
		while (o->width-- > (size + !(!f->sign)))
			prt += write(1, " ", 1);
	}
	else
	{
		// ' ' + sign + 0 + type
		while (o->width > (size + !(!f->sign)))
		{
			prt += write(1, " ", 1);
			o->width--;
		}
		if (f->sign == '-')
			prt += write(1, "-", 1);
		while (f->zero_size--)
			prt += write(1, "0", 1);
		/*while (o->precision && !o->width && o->p_width > size)
		{
			prt += write(1, "0", 1);
			o->p_width--;
		}*/
		prt += write(1, data, size);
	}
	/*if (f->left_align)
	{
		// 0 + type + ' '
		if (f->sign == '-')
			prt += write(1, "-", 1);
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
		if (f->sign == '-')
			prt += write(1, "-", 1);
		while (f->zero_size--)
			prt += write(1, "0", 1);
		prt += write(1, data, size);
	}*/

	*prt_cnt += prt;
		free(data);

	return (0);
}
