/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:47:49 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/30 16:47:53 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_swap_b2(t_stack *a, t_stack *b, t_swapinfo info)
{
	pab(b, a, "pa", 1);
	b->pa_cnt++;
	if (info.pivot1 > a->list[a->top])
	{
		rab(a, "ra", 1);
		b->ra_cnt++;
	}
}

static void	do_swap_b(t_stack *a, t_stack *b, t_swapinfo info)
{
	int	i;

	i = 0;
	b->pa_cnt = 0;
	b->ra_cnt = 0;
	b->rb_cnt = 0;
	while (i < info.size)
	{
		if (info.pivot2 < b->list[b->top])
			do_swap_b2(a, b, info);
		else
		{
			if (i + 1 == info.size && info.pivot1 < b->list[b->top - 1])
			{
				sab(b, "sb", 1);
				pab(b, a, "pb", 1);
				break ;
			}
			rab(b, "rb", 1);
			b->rb_cnt++;
		}
		i++;
	}
}

static int	pre_swap_b(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (info.size == 1)
	{
		pab(b, a, "pa", 1);
		return (1);
	}
	if (do_confirm_ordered_desc(a, b, info))
		return (1);
	if (do_hardcode_b(a, b, info))
		return (1);
	return (0);
}

void	swap_b(t_stack *a, t_stack *b, t_swapinfo info)
{
	int	*pivot;
	int	rb_cnt;
	int	pa_cnt;
	int	ra_cnt;

	info.size = info.r - info.l + 1;
	if (pre_swap_b(a, b, info))
		return ;
	pivot = get_pivot(b, info.l, info.r);
	info.pivot1 = b->list[pivot[1]];
	info.pivot2 = b->list[pivot[0]];
	free(pivot);
	do_swap_b(a, b, info);
	pa_cnt = b->pa_cnt;
	ra_cnt = b->ra_cnt;
	rb_cnt = b->rb_cnt;
	if (pa_cnt - ra_cnt != 0)
		swap_a(a, b, set_info(a->top - (pa_cnt - ra_cnt -1), a->top));
	reverse_op(a, b, ra_cnt, rb_cnt);
	if (ra_cnt != 0)
		swap_a(a, b, set_info(a->top - (ra_cnt - 1), a->top));
	if (rb_cnt != 0)
		swap_b(a, b, set_info(b->top - (rb_cnt - 1), b->top));
}
