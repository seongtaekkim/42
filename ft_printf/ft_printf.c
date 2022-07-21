/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:30:57 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/20 13:52:34 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

void	set_format(va_list *ap, const char *data)
{
	if (*data == '%')
	{
		write(1,  "%", 1);
	}
	else
	{
		if (*data == 'c')
		{
			char ret = va_arg(*ap, int);
			write(1, &ret, 1);
		}
		else if(*data == 's')
		{
			char *ret2 = va_arg(*ap, char*);
			while (*ret2)
			{
				write(1, &(*ret2), 1);
				ret2++;
			}
		}
		else if (*data == 'i' || *data == 'd')
		{
			// atoi 적용 후 출력
		}
		else if (*data == 'u')
		{
			// atou 적용 후  출력 하는데 음수처리필요
		}
		else if (*data == 'x' || *data == 'X')
		{
			// 16진수로 변환하여 출력하는 로직 추가 
		}
		else if (*data == 'p')
		{
			// 주소 출력
		}
		else
			write(1,"?",1);
	}
}

t_bool	is_number(char c)
{
	return (c >= '0' && c <= '9');
}


char	get_type(char data)
{
	const char	*type = "csdiuxXp%";
	while (*type)
	{
		if (*type == data)
			return (data);
		type++;
	}
	return (0);
}

int	set_option(t_options *options, const char *target)
{
	int		index;
	char	data;
	index = 0;
	while (target[index])
	{
		data = target[index];
		if (options->precision == false && is_number(data))
			options->width = options->width * 10 + data - '0';
		if (options->precision == true && is_number(data))
			options->p_width = options->p_width * 10 + data - '0';
		if ('.' == data)
			options->precision = true;
		else if ('0' == data && !is_number(target[index - 1]))
			options->zero = true;
		else if (' ' == data)
			options->space = true;
		else if('+' == data)
			options->plus = true;
		else if('-' == data)
			options->minus = true;
		else if('#' == data)
			options->hash = true;
		else if (!is_number(data) && get_type(data))
		{
			options->type = get_type(data);
			break ;
		}
		index++;
	}
	return (index);
}

char	*set_print_data(t_format *f, t_options *o, va_list *ap)
{
	int	space;
	space = 0;

	// 1. format 생성
	// left_align set
	if (o->minus)
		f->left_align = true;
	else
	{	
		// zero set
		if (o->zero && ((o->precision && o->p_width > 0) || !o->precision))
		{
			f->zero = true;
			f->zero_size = o->p_width;
		}
	}
	// is show sign set
	if (o->plus)
		f->is_show_sign = true;
	space += (o->plus || o->space);
	if(o->hash && (o->type == 'x' || o->type == 'X'))
	{
		f->hash_val[0] = '0';
		f->hash_val[1] = o->type;
		f->hash_val[2] = '\0';
	}
	if (o->width && (o->width > o->p_width))
		space += o->width;
	else
		space += o->p_width;
	f->tot_len = space;
	/*
	printf("format : ==========\n");
	printf("format.tot_len : %d\n",f->tot_len);
	printf("format.zero : %d\n",f->zero);
	printf("format.zero_size : %d\n",f->zero_size);
	printf("format.left_align : %d\n",f->left_align);
	printf("format.hash_val : %s\n",f->hash_val);
	printf("format.is_show_sign : %d\n",f->is_show_sign);
	printf("format : ==========\n");
*/
	char	*data;
	char	type_data;
	// 2. 타입데이터 생성
	if ('c' == o->type)
	{
		//type_data = (char *)malloc(sizeof(char)) + 1;
		type_data = va_arg(*ap, int);
	}


	// 3. 포맷에 맞게 출력데이터 생성 
	// 정렬여부, 
	// 우측정렬 : 오른쪽부터 타입테이터, 부호, zero, 빈칸 순서로 넣는다. 
	// 왼쪾정렬 : 왼쪽부터 부호, 타입데이터를 넣는다.
	data = (char *)malloc(sizeof(char) * (f->tot_len + 1));
	int index = 0;
	if (f->left_align)
	{
		data[index++] = type_data;
		while (index < f->tot_len)
		{
			data[index] = ' ';
			index++;
		}
	}
	else
	{
	}
	return (data);
}

void	init(t_options *options, t_format *format)
{
	options->space = false;
	options->plus = false;
	options->minus = false;
	options->width = 0;
	options->p_width = 0;
	options->zero = false;
	options->hash = false;
	options->precision = false;
	options->type = 0;
	format->tot_len = 0;
	format->zero = false;
	format->zero_size = 0;
	format->left_align = false;
	format->hash_val[0] = '\0';
	format->is_show_sign = false;
}

int	do_printf(va_list *ap, const char *format_syntax)
{
	char		*data;
	t_options	options;
	t_format	format;
	int			format_len;

	init(&options, &format);
	format_len = set_option(&options, format_syntax);
	/*
	printf("=================\n");
	printf("options.space : %d\n", options.space);
	printf("options.plus : %d\n", options.plus);
	printf("options.minus : %d\n", options.minus);
	printf("options.width : %d\n", options.width);
	printf("options.p_width : %d\n", options.p_width);
	printf("options.zero : %d\n", options.zero);
	printf("options.hash : %d\n", options.hash);
	printf("options.precision : %d\n", options.precision);
	printf("options.type: %c\n", options.type);
	printf("=================\n");
	*/
	data = set_print_data(&format, &options, ap);
	printf("%s$\n", data);
	//show(data);
	return (format_len);
}

int	ft_printf(const char *data, ...)
{
	va_list ap;
	int	format_len;

	va_start(ap, data);
	while (*data)
	{
		if (*data == '%')
		{
			format_len = do_printf(&ap, ++data);
			data = data + format_len;
			//set_format(&ap, ++data);
		
		}
		else
			write(1, &(*data), 1);
		data++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	//sumAll(2, 10, 20);
	const char	a = 'a';
	//const char	*str = "abcde";	
	ft_printf("test%+-1.04c", a);
	return (0);
}
