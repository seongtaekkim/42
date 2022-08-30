/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_swap_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:50:11 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/30 15:56:50 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	hard_capacity3_b1(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (b->list[info.l + 1] > b->list[info.l])
	{	
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}
	else if (b->list[info.l] > b->list[info.r])
	{
		rrab(b, "rrb", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}
	else
	{
		pab(b, a, "pa", 1);
		sab(b, "sb", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}	
}

static void	hard_capacity3_b2(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (b->list[info.r] > b->list[info.l])
	{
		sab(b, "sb", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}
	else if (b->list[info.l] > b->list[info.l + 1])
	{
		rrab(b, "rrb", 1);
		pab(b, a, "pa", 1);
		sab(b, "sb", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}
	else
	{
		sab(b, "sb", 1);
		pab(b, a, "pa", 1);
		sab(b, "sb", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}
}

static void	hard_size3_b1(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (b->list[info.l + 1] > b->list[info.l])
	{	
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}
	else if (b->list[info.l] > b->list[info.r])
	{
		rab(b, "rb", 1);
		sab(b, "sb", 1);
		pab(b, a, "pa", 1);
		rrab(b, "rrb", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}
	else
	{
		pab(b, a, "pa", 1);
		sab(b, "sb", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}
}

static void	hard_size3_b2(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (b->list[info.r] > b->list[info.l])
	{
		sab(b, "sb", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}
	else if (b->list[info.l] > b->list[info.l + 1])
	{
		sab(b, "sb", 1);
		rab(b, "rb", 1);
		sab(b, "sb", 1);
		pab(b, a, "pa", 1);
		rrab(b, "rrb", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}
	else
	{
		sab(b, "sb", 1);
		pab(b, a, "pa", 1);
		sab(b, "sb", 1);
		pab(b, a, "pa", 1);
		pab(b, a, "pa", 1);
	}
}

int	do_hardcode_b(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (hard_size2_b(a, b, info))
		return (1);
	if (info.size == 3 && b->top == info.r && info.l == 0)
	{
		if (b->list[info.r] > b->list[info.l + 1])
			hard_capacity3_b1(a, b, info);
		else
			hard_capacity3_b2(a, b, info);
		return (1);
	}
	else if (info.size == 3 && b->top == info.r)
	{
		if (b->list[info.r] > b->list[info.l + 1])
			hard_size3_b1(a, b, info);
		else
			hard_size3_b2(a, b, info);
		return (1);
	}
	return (0);
}
