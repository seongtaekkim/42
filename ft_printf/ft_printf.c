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
#include "ft_printf.h"


char	*set_print_data(t_format *f, t_options *o, va_list *ap)
{
	int	space;
	char *(*fp[10])(va_list *, t_options *, t_format *) 
		= {c_proc, s_proc, di_proc, di_proc, u_proc, x_proc, x2_proc, p_proc};
	space = 0;

	// 1. format 생성
	set_format(o, f);
	
	char	*data;
	char	*type_data;
	type_data = (*fp[o->type])(ap, o, f);
	if (!f->is_print)
	{
		data = (char *)malloc(sizeof(char));
		data[0] = '\0';
		return (data);
	}
	//printf("type data : %s\n", type_data);
	//f->tot_len += str_size;
	data = (char *)malloc(sizeof(char) * (f->tot_len + 1 + (o->plus || o->space)));
	size_t index = 0;
	size_t	jndex = 0;
	//printf("zero : %zu, type : %zu, sign : %c\n", f->zero_size,f->type_size,f->sign);
	//	printf("\n\ntot : %zu, empt: %zu, index : %zu, data : $%s$\n\n",f->tot_len,f->empty_size, index, data);
	if (f->left_align)
	{
		if (f->sign)
			data[index++] = f->sign;
		while ( jndex++ < f->zero_size) 
			data[index++] = '0';
		jndex = 0;
		while (jndex < f->type_size)
		{
			data[index] = type_data[jndex++];
			index++;
		}
		jndex = 0;
		while (jndex++ < f->empty_size)
			data[index++] = ' ';
		data[index] = '\0';
		//printf("\n\ntot : %zu, empt: %zu, index : %zu, data : $%s$\n\n",f->tot_len,f->empty_size, index, data);
	}
	else
	{
		while (jndex++ < f->empty_size)
			data[index++] = ' ';
		if (f->sign)
			data[index++] = f->sign;
		jndex = 0;
		//printf("\nzero_size : %zu\n", f->zero_size);
		while ( jndex++ < f->zero_size) 
			data[index++] = '0';
		jndex = 0;
		while (jndex < f->type_size)
		{
			data[index] = type_data[jndex];
			index++;
			jndex++;
		}
		data[index] = '\0';
	}
	return (data);
}

int	show(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		write(1, &(str[index]), 1);
		index++;
	}
	return (index);
}

int	do_printf(va_list *ap, const char *format_syntax, int *prt_cnt)
{
	char		*data;
	t_options	options;
	t_format	format;
	int			format_len;

	init(&options, &format);
	format_len = set_option(&options, format_syntax);
	data = set_print_data(&format, &options, ap);
	*prt_cnt = show(data);
	return (format_len);
}

int	ft_printf(const char *data, ...)
{
	va_list ap;
	int	format_len;
	int	i;
	int	prt_cnt;
	int	prt_cnt_b;

	i = 0;
	prt_cnt = 0;
	va_start(ap, data);
	while (1)
	{
		prt_cnt_b = prt_cnt;
		if (data[i] == '%')
		{
			//if ((&data[i + 1]) == NULL)
			//	return (0);
			if (data[i + 1] == '%')
			{
				write(1, &(data[i]), 1);
				i += 2;
				continue;
			}
			format_len = do_printf(&ap, &data[++i], &prt_cnt);
			i = i + format_len; 
		}
		else
		{
			printf("p");
			write(1, &(data[i]), 1);
			prt_cnt += 1;
			i++;
		}
		if (prt_cnt_b == prt_cnt)
			break ;
	}
	va_end(ap);
	return (prt_cnt);
}
