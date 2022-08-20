/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:24:50 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/20 14:35:20 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *s, int data)
{
	int	top;
	int	bottom;

	top = s->top;
	bottom = s->bottom;
	if (top == s->capacity - 1)
		return ;
	if (top == -1)
		bottom++;
	s->list[++top] = data;
	s->top = top;
	s->bottom = bottom;
	s->size += 1;
}

void	pop(t_stack *s)
{
	int	top;

	top = s->top;
	if (top == -1)
		return ;
	if (top == 0)
		s->bottom += -1;
	s->list[s->top] = 0;
	s->top = --top;
	s->size--;
}

int	peek(t_stack *s)
{
	if (s->top == -1)
		pexit();
	return (s->list[s->top]);
}
/*

t_node	*peek(t_node *head, t_node *tail)
{
	t_node	*node;
	node = head->next;
	if (node != NULL && node != tail)
		return (node);
	return (NULL);
}


void	show_r(t_node *head, t_node *tail)
{
	t_node *node;
	node = tail->prev;
	
	while (node != NULL && node != head)
	{
		printf("%d ",node->data);
		node = node->prev;
	}
	printf("\n");
}

void	show_d_r(t_node *head, t_node *tail)
{
	t_node *node;
	node = tail->prev;
	
	while (node != NULL && node != head)
	{
		printf("%d ",node->data);
		node = node->prev;
	}
	printf("\n");
}
*/


