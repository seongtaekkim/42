/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:01:49 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 09:26:48 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char			*data;
	unsigned int	ret;
	size_t			size;
	ssize_t			prt;

	prt = 0;
	ret = va_arg(*ap, unsigned int);
	data = ft_utoa(ret);
	size = ft_strlen(data);
	set_proc_format_diu(o, f, size);
	if (ret == 0 && o->precision && !o->width && !o->p_width)
	{
		free(data);
		return ;
	}
	if (ret == 0 && o->precision && o->width && !o->p_width)
		data[0] = ' ';
	*prt_cnt += do_write(data, size, f);
	free(data);
}
