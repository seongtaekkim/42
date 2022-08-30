/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:19:29 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/30 16:03:48 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_stack *s, char *op, int is_print)
{
	int	data1;
	int	data2;

	if (s->top < 1)
		return ;
	data1 = s->list[s->top];
	pop(s);
	data2 = s->list[s->top];
	pop(s);
	push(s, data1);
	push(s, data2);
	if (op != (void *)0 && is_print)
		output(op);
}

void	ss(t_stack *a, t_stack *b, int is_print)
{
	sab(a, (void *)0, is_print);
	sab(b, (void *)0, is_print);
	if (is_print)
		output("ss");
}
