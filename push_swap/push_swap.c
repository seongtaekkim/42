/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:06:37 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/18 19:39:30 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		minindex;
	int		index1;
	int		index2;

	index1 = 0;
	while (index1 < size)
	{
		minindex = index1;
		index2 = index1 + 1;
		while (index2 < size)
		{
			if (tab[minindex] > tab[index2])
			{
				ft_swap(&tab[minindex], &tab[index2]);
			}
			index2++;
		}
		index1++;
	}
}

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
	a->size = num - 1;
	b->list = (int *)malloc(sizeof(int) * num);
	b->top = -1;
	b->bottom = -1;
	b->size = num - 1;
	while (i > 0)
	{
		ret = ft_atoi(data[i]); // atoi 내부에서 예외 처리하도록 해야함
		sret = binary_search(a, ret); 
		if (sret != -1)
			pexit();
		push(a , ret);
		i--;
	}
}

// 범위의 피벗을 찾기 위해 중앙값의 인덱스를 리턴.
// 일단 그냥 찾고,
// 이게 효용성 있으면
// 구조체로 a의 인덱스를 arr에 넣어서 두번 찾는걸 개선하자.
int	step1(t_stack *a, int l, int r)
{
	int	*arr;
	int	i;
	int	j;
	int	size;

	i = l;
	j = 0;
	size = r - l + 1;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (-1);
	while (j < size)
	{
		arr[j] = a->list[i];
		i++;
		j++;
	}
	ft_sort_int_tab(arr, size);
	i=0;
	while (i < size)
		printf("%d ", arr[i++]);
	printf("\n");

	int search_data = arr[size / 2];
	printf("searchdat %d\n", search_data);
	i = a->size - 1;
	while (i >= 0)
	{
		if (search_data == a->list[i])
			return (a->size -1 -i);
		i--;
	}
	return (-1);
}

void	a_to_b(t_stack *a, t_stack *b, int l, int r)
{
	int	pivot;
	int	size;
	int	i;
	int	ra_cnt;
	int	pb_cnt;
	int	data;
	ra_cnt = 0;
	pb_cnt = 0;
	i = 0;
	size = r - l + 1;
	if (size <= 1)
	{
		printf("size 1 return !!!!!!!!!!!!!!!!!!");
		return ;
	}
	pivot = step1(a, l, r);
	printf("a pivot : %d size : %d\n", pivot, size);
	data = a->list[pivot];
	while (i < size)
	{
		if (data < a->list[a->top])
		{
			ra(a);
			ra_cnt++;
		}
		else
		{
			pb(a, b);
			pb_cnt++;
		}
		i++;
	}
	/*i = 0;
	while (i < ra_cnt)
	{
		rra(a);
		i++;
	}*/
	printf("ra_cnt : %d\n",ra_cnt);
	a_to_b(a, b, 0, ra_cnt -1);
	b_to_a(a, b, 0, pb_cnt -1);
}

void	b_to_a(t_stack *a, t_stack *b, int l, int r)
{
	int	pivot;
	int	size;
	int	i;
	int	rb_cnt;
	int	pa_cnt;
	int	data;

	rb_cnt = 0;
	pa_cnt = 0;
	i = 0;
	size = r - l + 1;
	pivot = step1(a, l, r);
	if (size == 1)
	{
		pa(b, a);
		return ;
	}
	data = b->list[pivot];
	while (i < size)
	{
		if (data < b->list[b->top])
		{
			pa(b, a);
			pa_cnt++;
		}
		else
		{
			rb(b);
			rb_cnt++;
		}
		i++;
	}
	/*i = 0;
	while (i < rb_cnt)
	{
		rrb(b);
		i++;
	}*/
	a_to_b(a, b, 0, pa_cnt -1);
	b_to_a(a, b, 0, rb_cnt -1);
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
	
//	int pivot = step1(&a, 0, (&a)->size -1);	
//printf("pivot : %d\n", pivot);
	a_to_b(&a, &b, 0, (&a)->size -1);
	//show(&a);
	//show(&a);
	//show(&a);
	//show(&b);

	//printf("%d %d", (&a)->top, (&a)->list[5]);
	//printf("%d ",*(int*)((&top)->next->data));
	//printf("%d ",*(int*)((&top)->next->next->data));
	return (0);
}
