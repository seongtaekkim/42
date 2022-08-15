/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:24:50 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/15 19:30:52 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node *stack, int data)
{
	t_node *node;
	t_node *top;
	t_node *bottom;

	top = stack->top;
	bottom = stack->bottom;
	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	if (!top->next)
	{
		node->next = bottom;
		bottom->prev = node;
		top->next = node;
		node->prev = top;
	}
	else
	{
		node->next = top->next;
		node->prev = top;
		top->next = node;
		(node->next)->prev = node;
	}
}
/*
void	push(t_node *head, t_node *tail, int data)
{
	t_node *node;
	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	if (!head->next)
	{
		node->next = tail;
		tail->prev = node;
		head->next = node;
		node->prev = head;
	}
	else
	{
		node->next = head->next;
		node->prev = head;
		head->next = node;
		(node->next)->prev = node;
	}
}
*/
void	pop(t_node *head, t_node *tail)
{
	t_node *node;
	node = head->next;
	if (head == tail)
		return ;
	head->next = node->next;
	(node->next)->prev = head;
	free(node);
}

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



