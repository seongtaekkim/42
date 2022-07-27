#include "ft_printf.h"

t_bool	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	get_type(char data)
{
	const char	*type = "csdiuxXp%";
	int			index;

	index = 0;
	while (type[index])
	{
		if (type[index] == data)
			return (index);
		index++;
	}
	return (-1);
}

void	init(t_options *o, t_format *f)
{
	o->space = false;
	o->plus = false;
	o->minus = false;
	o->p_plus = false;
	o->p_minus = false;
	o->width = 0;
	o->p_width = 0;
	o->zero = false;
	o->hash = false;
	o->precision = false;
	o->type = 0;
	f->tot_len = 0;
	f->zero = false;
	f->zero_size = 0;
	f->empty_size = 0;
	f->type_size = 0;
	f->left_align = false;
	f->hash_val[0] = '\0';
	f->is_show_sign = false;
	f->is_print = true;
	f->sign = 0;
}

int	set_option(t_options *o, const char *target)
{
	int		index;
	char	data;
	index = 0;
	while (target[index])
	{
		data = target[index];
		if (o->precision == false && is_number(data))
			o->width = o->width * 10 + data - '0';
		if (o->precision == true && is_number(data))
			o->p_width = o->p_width * 10 + data - '0';
		if ('.' == data)
			o->precision = true;
		if (o->precision == true && '-' == data)
			o->p_minus = true;
		if (o->precision == true && '+' == data)
			o->p_plus = true;
		else if ('0' == data && !is_number(target[index - 1]))
			o->zero = true;
		else if (' ' == data)
			o->space = true;
		else if('+' == data)
			o->plus = true;
		else if('-' == data)
			o->minus = true;
		else if('#' == data)
			o->hash = true;
		else if (!is_number(data) && get_type(data) > -1)
		{
			o->type = get_type(data);
			index++;
			break ;
		}
		index++;
	}
	return (index);
}

void	set_format(t_options *o, t_format *f)
{
	int	space;
	space = 0;

	// 1. format 생성
	// left_align set
	
	if (o->minus || o->p_minus)
		f->left_align = true;
	else
	{
		// zero set
		if (o->zero && (o->precision && o->p_width > 0))
		{
			f->zero = true;
			//f->zero_size = o->p_width;
		}
		else if (o->zero && !o->precision)
		{
			f->zero = true;
			//f->zero_size = o->width;
		}
	}
	// is show sign set => d,i에서만 할것
	//iif (o->plus)
	//	f->is_show_sign = true;
	//space += (o->plus || o->space);
}





