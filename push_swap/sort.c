/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:46:28 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/30 15:49:51 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
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

int	confirm_ordered(t_stack *a, int l, int r)
{
	int	i;
	int	size;
	int	min;

	size = r - l + 1;
	i = r;
	min = a->list[r];
	while (i > 0)
	{
		if (a->list[i] > a->list[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	confirm_ordered_desc(t_stack *a, int l, int r)
{
	int	i;
	int	size;
	int	min;

	size = r - l + 1;
	i = r;
	min = a->list[r];
	while (i > 0)
	{
		if (a->list[i] < a->list[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	is_ordered_swap(t_stack *s, t_swapinfo info, int i)
{
	int	k;
	int	flag;

	k = 0;
	flag = 1;
	while (i < info.size)
	{
		if (i + 1 < info.size && info.pivot1 <= s->list[s->top - k])
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
