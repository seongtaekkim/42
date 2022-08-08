/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:01:29 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/08 09:24:38 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_proc(va_list *ap, t_options *o, t_format *f, int *prt_cnt)
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
}
