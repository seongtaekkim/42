/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:12:17 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/15 19:38:14 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	struct s_stack	*top;
	struct s_stack	*bottom;
}	t_node;

typedef struct s_stack
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}	t_stack;

void	push(t_node *stack, int data);
void	pop(t_node *head, t_node *tail);
t_node	*peek(t_node *head, t_node *tail);

void	sa(t_node *top, t_node *tail);
#endif
