/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:47:38 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/30 16:47:44 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pre_swap_a(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (info.size == 1)
		return (1);
	if (confirm_ordered(a, info.l, info.r) == 1)
		return (1);
	if (do_hardcode_a(a, b, info))
		return (1);
	return (0);
}

int	do_swap_a2(t_stack *a, t_stack *b, t_swapinfo info, int i)
{
	if (i + 1 == info.size && info.pivot1 > a->list[a->top - 1])
	{
		sab(a, "sa", 1);
		pab(a, b, "pa", 1);
		return (1);
	}
	if (is_ordered_swap(a, info, i))
		return (1);
	rab(a, "ra", 1);
	a->ra_cnt++;
	return (0);
}

void	do_swap_a3(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (info.l == 0 && info.r == (a->capacity - 1))
	{
		pab(a, b, "pb", 1);
		a->pb_cnt++;
		if (info.pivot2 >= b->list[b->top])
			rab(b, "rb", 1);
	}
	else
	{
		pab(a, b, "pb", 1);
		a->pb_cnt++;
		if (info.pivot2 < b->list[b->top])
		{
			rab(b, "rb", 1);
			a->rb_cnt++;
		}
	}
}

void	do_swap_a(t_stack *a, t_stack *b, t_swapinfo info)
{
	int	*pivot;
	int	i;

	i = 0;
	pivot = get_pivot(a, info.l, info.r);
	info.pivot1 = a->list[pivot[1]];
	info.pivot2 = a->list[pivot[0]];
	a->pb_cnt = 0;
	a->rb_cnt = 0;
	a->ra_cnt = 0;
	while (i < info.size)
	{
		if (info.pivot1 <= a->list[a->top])
		{
			if (do_swap_a2(a, b, info, i))
				break ;
		}
		else
			do_swap_a3(a, b, info);
		i++;
	}
	free(pivot);
}

void	swap_a(t_stack *a, t_stack *b, t_swapinfo info)
{
	int	i;
	int	ra_cnt;
	int	pb_cnt;
	int	rb_cnt;

	info.size = info.r - info.l + 1;
	if (pre_swap_a(a, b, info))
		return ;
	do_swap_a(a, b, info);
	pb_cnt = a->pb_cnt;
	rb_cnt = a->rb_cnt;
	ra_cnt = a->ra_cnt;
	i = 0;
	if (info.l == 0)
		while (i++ < rb_cnt)
			rrab(b, "rrb", 1);
	else
		reverse_op(a, b, ra_cnt, rb_cnt);
	if (ra_cnt != 0)
		swap_a(a, b, set_info(a->top - (ra_cnt - 1), a->top));
	if (rb_cnt != 0)
		swap_b(a, b, set_info(0, rb_cnt - 1));
	if (pb_cnt - rb_cnt != 0)
		swap_b(a, b, set_info(b->top - (pb_cnt - rb_cnt - 1), b->top));
}
