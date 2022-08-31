/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:06:37 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/31 16:19:51 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_op(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ra_cnt && j < rb_cnt)
	{
		rrr(a, b, 1);
		i++;
		j++;
	}
	while (i++ < ra_cnt)
		rrab(a, "rra", 1);
	while (j++ < rb_cnt)
		rrab(b, "rrb", 1);
}

int	do_confirm_ordered_desc(t_stack *a, t_stack *b, t_swapinfo info)
{
	int	i;
	int	confirm;

	i = 0;
	confirm = 0;
	if (b->top == info.r)
	{
		confirm = confirm_ordered_desc(a, info.l, info.r);
		if (confirm == 1)
		{
			while (i++ < info.size)
				pab(b, a, "pa", 1);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;

	if (argc < 2)
		return (0);
	init(&a, &b, argc, argv);
	swap_a(&a, &b, set_info(0, (&a)->size -1));
	free((&a)->list);
	free((&b)->list);
	return (0);
}
