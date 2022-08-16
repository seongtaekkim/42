/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:06:37 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/16 16:19:45 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pexit()
{
	write(2, "Error\n", 6);
	exit(1);
}

/// 1 1 2 에서 됨, 다시짜야됨
int	binary_search(t_stack *s, int target)
{
	int	pivot;
	int	right;
	int	left;

	left = 0;
	right = s->top;
	if (right == -1)
		return (-1);
	while (right >= left)
	{
		pivot = (left+right) / 2;
		if (s->list[pivot] == target)
			return (pivot);
		else
		{
			if (s->list[pivot] > target)
				right = pivot - 1;
			else
				left = pivot + 1;
		}
	}
	return (-1);
}

void	show(t_stack *s)
{
	int	top;
	int	bottom;

	top = s->top;
	bottom = s->bottom;
	if (s->top == -1)
		return ;
	while (top >= bottom)
	{
		printf("%d ", s->list[top]);
		top--;
	}
	printf("\n");
}

void	init(t_stack *a, t_stack *b, int num, char **data)
{
	int	i;
	int	ret;
	int	sret;

	i = num - 1;
	a->list = (int *)malloc(sizeof(int) * num);
	a->top = -1;
	a->bottom = -1;
	a->size = num;
	b->list = (int *)malloc(sizeof(int) * num);
	b->top = -1;
	b->bottom = -1;
	b->size = num;
	while (i > 0)
	{
		ret = ft_atoi(data[i]); // atoi 내부에서 예외 처리하도록 해야함
		sret = binary_search(a, ret); 
		if (sret != -1)
			pexit();
		//printf("in data :%d\n",ret);
		push(a , ret);
		i--;
	}
}

int	main(int argc, char **argv)
{

	if (argc < 2)
		pexit();
	//t_node	top;
	//t_node	bottom;
	t_stack	a;
	t_stack	b;
	init(&a, &b, argc, argv);
	
	//show(&a);
	sa(&a);
	//show(&a);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	ra(&a);
	rb(&b);
	rra(&a);
	rrb(&b);
	sa(&a);
	pa(&b, &a);
	pa(&b, &a);
	pa(&b, &a);
	//show(&a);
	//show(&b);

	//printf("%d %d", (&a)->top, (&a)->list[5]);
	//sa(&top, &bottom);
	//show(&top, &bottom);
	//int aa = 1;
	//int bb = 2;
	//push(&a, aa);
	//push(&a, bb);
	//printf("%d ",*(int*)((&top)->next->data));
	//printf("%d ",*(int*)((&top)->next->next->data));
	
	
	
	return (0);
}
