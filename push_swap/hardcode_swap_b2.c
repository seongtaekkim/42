/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_swap_b2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:56:05 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/30 15:56:28 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hard_size2_b(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (info.size == 2 && b->top == info.r)
	{
		if (b->list[info.r] > b->list[info.l])
		{
			pab(b, a, "pa", 1);
			pab(b, a, "pa", 1);
			return (1);
		}
		else
		{
			sab(b, "sb", 1);
			pab(b, a, "pa", 1);
			pab(b, a, "pa", 1);
			return (1);
		}
	}
	return (0);
}
