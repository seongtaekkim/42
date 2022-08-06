/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:27:31 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 14:38:14 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
{
	char					*data;
	unsigned long long		ret;
	size_t					size;

	ret = va_arg(*ap, unsigned long long);
	data = ft_p_base(ret);
	size = ft_strlen(data);
	set_proc_format_diu(o, f, size);
	*prt_cnt += do_write(data, size, f);
	free(data);
	return (0);
}
