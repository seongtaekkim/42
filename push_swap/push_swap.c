/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:06:37 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/20 19:47:56 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 삭제 
void	show(t_stack *s)
{
	int	top;
	int	bottom;

	top = s->top;
	bottom = s->bottom;
	if (s->top == -1)
		return ;
	printf("show data =============\n");
	while (top >= bottom)
	{
		printf("%d ", s->list[top]);
		top--;
	}
	printf("\n");
	printf("=======================\n");
}

t_swapinfo	set_info(int l, int r)
{
	t_swapinfo info;

	info.l = l;
	info.r = r;
	return (info);
}



void	reverse_op(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ra_cnt && j < rb_cnt)
	{
		rrr(a, b, 1);
		i++;
		j++;	
	}
	while (i++ < ra_cnt)
		rrab(a, "rra", 1);
	while (j++ < rb_cnt)
		rrab(b, "rrb", 1);
}

int	pre_swap_a(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (info.size == 1)
		return (1);
	if (confirm_ordered(a, info.l, info.r) == 1)
		return (1);
	if (process1(a, b, info.l, info.r))
		return (1);
	return (0);
}

int	is_ordered_swap_a(t_stack *a, t_swapinfo info, int i)
{
	int	k;
	int	flag;

	k = 0;
	flag = 1;
	while (i < info.size)
	{
		if (i + 1 < info.size && info.pivot1 <= a->list[a->top -k])
			flag = 1;
		else
		{
			flag = 0;
			break ;
		}
	i++;
	k--;
	}	
	if (flag == 1)
		return (1);
	return (0);
}
int	do_swap_a2(t_stack *a, t_stack *b, t_swapinfo info, int i)
{
	if (i + 1 ==  info.size && info.pivot1 > a->list[a->top -1])
	{
		sab(a, "sa", 1);
		pab(a, b, "pa", 1);
		return (1);
	}
	if (is_ordered_swap_a(a, info, i))
		return (1);
	rab(a, "ra", 1);
	a->ra_cnt++;
	return (0);
}

void	do_swap_a3(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (info.l == 0 && info.r == (a->capacity -1))
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
		swap_a(a, b, set_info(a->top - (ra_cnt -1), a->top));// ra호출개수
	if (rb_cnt !=0)
		swap_b(a, b, set_info(0, rb_cnt -1));// pb 호출개수 -> rb 호출횟수
	if (pb_cnt - rb_cnt != 0)
		swap_b(a, b, set_info(b->top - (pb_cnt -rb_cnt -1), b->top)); // pb호출개수 - rb 호출회수
}


int	do_confirm_ordered_desc(t_stack *a, t_stack *b, t_swapinfo info)
{
	int	i;

	i = 0;
	int confirm = 0;
	if (b->top == info.r)
	{
		confirm = confirm_ordered_desc(a, info.l, info.r);
		if (confirm == 1)
		{
			while (i++ < info.size)
				pab(b, a, "pa", 1);
			return (1);
		}
	}
	return (0);
}


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
			if (i + 1 ==  info.size && info.pivot1 < b->list[b->top -1])
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

int	pre_swap_b(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (info.size == 1)
	{
		pab(b, a, "pa", 1);
		return (1);
	}
	if (do_confirm_ordered_desc(a, b, info))
		return (1);
	if (process2(a, b, info.l, info.r))
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
	if (pa_cnt -ra_cnt  != 0)
		swap_a(a, b, set_info(a->top - (pa_cnt -ra_cnt -1), a->top)); // pa호출횟수 - ra호출횟수
	reverse_op(a, b, ra_cnt, rb_cnt);
	if (ra_cnt != 0)
		swap_a(a, b, set_info(a->top - (ra_cnt -1), a->top)); //  pa호출회수-> ra호출횟수  
	if (rb_cnt != 0)
		swap_b(a, b, set_info(b->top - (rb_cnt -1), b->top)); // pb 호출회수-> rb호출횟수
}







int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;

	if (argc < 2)
		pexit();
	init(&a, &b, argc, argv);
	swap_a(&a, &b, set_info(0, (&a)->size -1));
//printf("\n======================프로그램 종료\n");	
//	show(&a);
//	show(&b);
	free((&a)->list);
	free((&b)->list);
	return (0);
}