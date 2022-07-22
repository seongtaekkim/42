
#include "ft_printf.h"

char	*c_proc(va_list *ap, t_options *o, t_format *f)
{
	char	*data;
	char	c;
	(void)o;
	(void)f;

	c = va_arg(*ap, int);
	data = (char *)malloc(sizeof(char) + 1);
	data[0] = c;
	data[1] = '\0';
	return (data);
}

char	*s_proc(va_list *ap, t_options *o, t_format *f)
{
	char	*data;
	
	data = va_arg(*ap, char *);
	if (o->precision && !o->p_width)
		f->is_print = false;
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
	(void)ap;
	if(o->hash && (o->type == 'x' || o->type == 'X'))
	{
		f->hash_val[0] = '0';
		f->hash_val[1] = o->type;
		f->hash_val[2] = '\0';
	}
	return (NULL);
}
