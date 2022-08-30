/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:28:03 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/21 17:48:06 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *a, t_stack *b, int num, char **data)
{
	int	i;
	int	ret;
	int	flag;

	i = num - 1;
	a->list = (int *)malloc(sizeof(int) * num);
	a->top = -1;
	a->bottom = -1;
	a->size = 0;
	a->capacity = i;
	b->list = (int *)malloc(sizeof(int) * num);
	b->top = -1;
	b->bottom = -1;
	b->size = 0;
	b->capacity = i;
	flag = 1;
	while (i > 0)
	{
		ret = swap_for_atoi(ft_strtrim(data[i--], " "), &flag);
		if (flag == 0)
			pexit();
		if (search_dupl(a, ret) != -1)
			pexit();
		push(a, ret);
	}
}

t_swapinfo	set_info(int l, int r)
{
	t_swapinfo	info;

	info.l = l;
	info.r = r;
	return (info);
}
