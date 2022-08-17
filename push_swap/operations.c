/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:19:29 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/17 16:59:45 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(char *s)
{
	write(1, s, ft_strlen(s));
}

void	sa(t_stack *s)
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
	print("sa\n");
}

void	sb(t_stack *s)
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
	print("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	print("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	int	data1;
	
	if (a->top == -1)
		return ;
	data1 = peek(a);
	pop(a);
	push(b, data1);
	print("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	int	data1;
	
	if (a->top == -1)
		return ;
	data1 = peek(a);
	pop(a);
	push(b, data1);
	print("pb\n");
}

void	ra(t_stack *s)
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
	print("ra\n");
}

void	rb(t_stack *s)
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
	print("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	print("rr\n");
}

void	rra(t_stack *s)
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
	print("rra\n");
}

void	rrb(t_stack *s)
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
	print("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	print("rrr\n");
}
