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



void	reverse_op(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ra_cnt && j < rb_cnt)
	{
		rrr(a, b);
		i++;
		j++;	
	}
	while (i++ < ra_cnt)
		rrab(a, "rra");
	while (j++ < rb_cnt)
		rrab(b, "rrb");
}



// int	break_ra(t_stack *a, t_stack *b, int i, int size)
// {
// 	int j=i;
// 	int k=1;
// 	int	flag = 1;
	
// 	if (i + 1 ==  size && data > a->list[a->top -1])
// 	{
// 		sab(a, "sa");
// 		pab(a, b, "pa");
// 		return (1);
// 	}

// 	while (j < size)
// 	{
// 		if (j + 1 < size && data <= a->list[a->top -k])
// 			flag = 1;
// 		else
// 		{
// 			flag = 0;
// 			break ;
// 		}
// 	j++;
// 	k--;
// 	}	
// 	if (flag == 1)
// 		return (1);
// 	return (0);
// }

void	swap_a(t_stack *a, t_stack *b, int l, int r)
{
	int	*pivot;
	int	size;
	int	i;
	int	ra_cnt;
	int	pb_cnt;
	int	data;
	int data2;

	ra_cnt = 0;
	pb_cnt = 0;
	i = 0;
	size = r - l + 1;
	if (size == 1)
		return ;
	if (confirm_ordered(a, l, r) == 1)
		return ;
	if (process1(a, b, l, r))
		return ;
	pivot = get_pivot(a, l, r);
	data = a->list[pivot[1]];
	data2 = a->list[pivot[0]];
	free(pivot);
	int	rb_cnt = 0;
	int	rr_flag = 0;
	while (i < size)
	{
		if (data <= a->list[a->top])
		{
			if (i + 1 ==  size && data > a->list[a->top -1])
			{
				sab(a, "sa");
				pab(a, b, "pa");
				break ;
			}

			int j=i;
			int k=1;
			int	flag = 1;

			while (j < size)
			{
				if (j + 1 < size && data <= a->list[a->top -k])
					flag = 1;
				else
				{
					flag = 0;
					break ;
				}
			j++;
			k--;
			}	
			if (flag == 1)
				break ;
			
			if (rr_flag == 1)
			{
				rr(a, b);
				ra_cnt++;
				rb_cnt++;
				rr_flag = 0;
			}
			else
			{
				rab(a, "ra");
				ra_cnt++;
			}
		}
		else
		{

			if (l == 0 && r == (a->capacity -1))
			{
				pab(a, b, "pb");
				pb_cnt++;
				if (data2 >= b->list[b->top])
					rab(b, "rb");
			}
			else
			{
				pab(a, b, "pb");
				pb_cnt++;
				if (data2 < b->list[b->top])
				{
					if (i + 1 <=  size && data <= b->list[b->top -1])
					{
						rr_flag = 1;
					}
					else
					{
						rab(b, "rb");
						rb_cnt++;
					}
						
				}
			}
		}
		i++;
	}
	i = 0;
	int j = 0;
	if (l == 0)
	{
		while (j++ < rb_cnt)
			rrab(b, "rrb");
	}
	else
		reverse_op(a, b, ra_cnt, rb_cnt);
	//printf("==============================================================\n");
	if (ra_cnt != 0)
		swap_a(a, b, a->top - (ra_cnt -1), a->top);// ra호출개수
	if (rb_cnt !=0)
		swap_b(a, b, 0, rb_cnt -1);// pb 호출개수 -> rb 호출횟수
	if (pb_cnt - rb_cnt != 0)
		swap_b(a, b, b->top - (pb_cnt -rb_cnt -1), b->top); // pb호출개수 - rb 호출회수
}




int	do_confirm_ordered_desc(t_stack *a, t_stack *b, int l, int r)
{
	int	i;
	int	size;

	size = r - l + 1;
	i = 0;
	int confirm = 0;
	if (b->top == r)
	{
		confirm = confirm_ordered_desc(a, l, r);
		if (confirm == 1)
		{
			while (i++ < size)
				pab(b, a, "pa");
			return (1);
		}
	}
	return (0);
}


static void	do_swap_b2(t_stack *a, t_stack *b, int data[2])
{
	pab(b, a, "pa");
	b->pa_cnt++;
	if (data[0] > a->list[a->top])
	{
		rab(a, "ra");
		b->ra_cnt++;
	}
}

static void	do_swap_b(t_stack *a, t_stack *b, int pivot[2], int size)
{
	int	i;
	int	data[2];

	data[0] = b->list[pivot[1]];
	data[1] = b->list[pivot[0]];
	i = 0;
	b->pa_cnt = 0;
	b->ra_cnt = 0;
	b->rb_cnt = 0;
	while (i < size)
	{
		if (data[1] < b->list[b->top])
			do_swap_b2(a, b, data);
		else
		{
			if (i + 1 ==  size && data[0] < b->list[b->top -1])
			{
				sab(b, "sb");
				pab(b, a, "pb");
				break ;
			}
			rab(b, "rb");
			b->rb_cnt++;
		}
		i++;
	}
	free(pivot);
}

int	pre_swap_b(t_stack *a, t_stack *b, int l, int r)
{
	int	size;

	size = r - l + 1;
	if (size == 1)
	{
		pab(b, a, "pa");
		return (1);
	}
	if (do_confirm_ordered_desc(a, b, l, r))
		return (1);
	if (process2(a, b, l, r))
		return (1);
	return (0);
}

void	swap_b(t_stack *a, t_stack *b, int l, int r)
{
	int	*pivot;
	int	size;
	int	rb_cnt;
	int	pa_cnt;
	int	ra_cnt;
	
	size = r - l + 1;
	if (pre_swap_b(a, b, l ,r))
		return ;
	pivot = get_pivot(b, l, r);
	do_swap_b(a, b, pivot,size);
	pa_cnt = b->pa_cnt;
	ra_cnt = b->ra_cnt;
	rb_cnt = b->rb_cnt;
	if (pa_cnt -ra_cnt  != 0)
		swap_a(a, b, a->top - (pa_cnt -ra_cnt -1), a->top); // pa호출횟수 - ra호출횟수
	reverse_op(a, b, ra_cnt, rb_cnt);
	if (ra_cnt != 0)
		swap_a(a, b, a->top - (ra_cnt -1), a->top); //  pa호출회수-> ra호출횟수  
	if (rb_cnt != 0)
		swap_b(a, b, b->top - (rb_cnt -1), b->top); // pb 호출회수-> rb호출횟수
}




















int	main(int argc, char **argv)
{
	if (argc < 2)
		pexit();
	t_stack	a;
	t_stack	b;
	init(&a, &b, argc, argv);
	swap_a(&a, &b, 0, (&a)->size -1);
//printf("\n======================프로그램 종료\n");	
//	show(&a);
//	show(&b);
	free((&a)->list);
	free((&b)->list);
	return (0);
}