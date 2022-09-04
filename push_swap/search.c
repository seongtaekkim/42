/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:41:43 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/29 17:33:21 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_dupl(t_stack *s, int target)
{
	int	right;
	int	left;

	left = 0;
	right = s->top;
	if (right == -1)
		return (-1);
	while (right >= left)
	{
		if (s->list[left] == target)
			return (left);
		left++;
	}
	return (-1);
}

static int	*set_pivot_ratio(int *search_data, int *arr, t_stack *a, int size)
{
	if (size == a->capacity && size > 9)
	{
		search_data[0] = arr[size * 5 / 100];
		search_data[1] = arr[size * 50 / 100];
	}
	else if (size > 9)
	{	
		search_data[0] = arr[size * 35 / 100];
		search_data[1] = arr[size * 60 / 100];
	}
	else
	{
		search_data[0] = arr[size * 1 / 3];
		search_data[1] = arr[size * 2 / 3];
	}
	return (search_data);
}

static int	*find_pivot(int *arr, t_stack *a, int size)
{
	int	*search_data;
	int	*pivot;
	int	i;

	pivot = (int *)malloc(sizeof(int) * 2);
	pivot[0] = -1;
	pivot[1] = -1;
	search_data = (int *)malloc(sizeof(int) * 2);
	set_pivot_ratio(search_data, arr, a, size);
	i = a->size - 1;
	while (i >= 0)
	{
		if (search_data[0] == a->list[i])
			pivot[0] = i;
		if (search_data[1] == a->list[i])
			pivot[1] = i;
		if (pivot[0] != -1 && pivot[1] != -1)
		{
			free(search_data);
			return (pivot);
		}
		i--;
	}
	free(pivot);
	return ((void *)0);
}

int	*get_pivot(t_stack *a, int l, int r)
{
	int	*arr;
	int	i;
	int	j;
	int	size;
	int	*pivot;

	i = l;
	j = 0;
	size = r - l + 1;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return ((void *)0);
	while (j < size)
	{
		arr[j] = a->list[i];
		i++;
		j++;
	}
	ft_sort_int_tab(arr, size);
	pivot = find_pivot(arr, a, size);
	free(arr);
	if (pivot != (void *)0)
		return (pivot);
	return ((void *)0);
}
