/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:19:29 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/20 19:16:43 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_stack *s, char *op)
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
	if (op != (void *)0)
		output(op);
}

// void	ss(t_stack *a, t_stack *b)
// {
// 	sab(a, "");
// 	sab(b, "");
// 	output("ss");
// }

void	pab(t_stack *a, t_stack *b, char *op)
{
	int	data1;

	if (a->top == -1)
		return ;
	data1 = peek(a);
	pop(a);
	push(b, data1);
	output(op);
}

void	rab(t_stack *s, char *op)
{
	int	data;
	int	top;

	top = s->top;
	if (top < -1)
		return ;
	data = peek(s);
	top--;
	while (top != -1)
	{
		s->list[top + 1] = s->list[top];
		top--;
	}
	s->list[s->bottom] = data;
	if (op != (void *)0)
		output(op);
}

// void	rr(t_stack *a, t_stack *b)
// {
// 	rab(a, "");
// 	rab(b, "");
// 	output("rr");
// }

void	rrab(t_stack *s, char *op)
{
	int	data;
	int	bottom;

	bottom = s->bottom;
	if (s->top < 1)
		return ;
	data = s->list[bottom];
	bottom++;
	while (bottom != s->top)
	{
		s->list[bottom - 1] = s->list[bottom];
		bottom++;
	}
	s->list[bottom - 1] = s->list[bottom];
	s->list[s->top] = data;
	if (op != (void *)0)
		output(op);
}

void	rrr(t_stack *a, t_stack *b)
{
	rrab(a, (void *)0);
	rrab(b, (void *)0);
	output("rrr");
}
