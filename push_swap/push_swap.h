/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:12:17 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/30 16:54:34 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct s_swapinfo
{
	int	size;
	int	l;
	int	r;
	int	pivot1;
	int	pivot2;
}	t_swapinfo;

typedef struct s_stack
{
	int	top;
	int	bottom;
	int	capacity;
	int	size;
	int	*list;
	int	pa_cnt;
	int	ra_cnt;
	int	rb_cnt;
	int	pb_cnt;
}	t_stack;

void		push(t_stack *s, int data);
void		pop(t_stack *s);
int			peek(t_stack *s);
void		sab(t_stack *s, char *op, int is_print);
void		ss(t_stack *a, t_stack *b, int is_print);
void		pab(t_stack *a, t_stack *b, char *op, int is_print);
void		rab(t_stack *s, char *op, int is_print);
void		rr(t_stack *a, t_stack *b, int is_print);
void		rrab(t_stack *s, char *op, int is_print);
void		rrr(t_stack *a, t_stack *b, int is_print);
void		swap_a(t_stack *a, t_stack *b, t_swapinfo info);
void		swap_b(t_stack *a, t_stack *b, t_swapinfo info);
int			pexit(void);
int			is_ordered_swap(t_stack *s, t_swapinfo info, int i);
int			confirm_ordered_desc(t_stack *a, int l, int r);
int			confirm_ordered(t_stack *a, int l, int r);
void		ft_sort_int_tab(int *tab, int size);
int			*get_pivot(t_stack *a, int l, int r);
int			search_dupl(t_stack *s, int target);
void		init(t_stack *a, t_stack *b, int num, char **data);
void		output(char *s);
int			swap_for_atoi(const char *str, int *flag);
int			*append_array_data(int *op_list, int size, int op);
void		reverse_op(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt);
int			do_confirm_ordered_desc(t_stack *a, t_stack *b, t_swapinfo info);
int			do_hardcode_a(t_stack *a, t_stack *b, t_swapinfo info);
int			do_hardcode_b(t_stack *a, t_stack *b, t_swapinfo info);
int			hard_size2_b(t_stack *a, t_stack *b, t_swapinfo info);
t_swapinfo	set_info(int l, int r);
#endif
