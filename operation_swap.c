/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:38:04 by juli              #+#    #+#             */
/*   Updated: 2023/12/15 13:26:06 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	try_swap(t_cdl_list **top);

/* sa (swap a): Swap the first 2 elements at the top of stack a.
   Do nothing if there is only one or no elements. */
void	sa(t_cdl_list **top_a)
{
	ft_putendl_fd("sa", STDOUT_FILENO);
	try_swap(top_a);
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
   Do nothing if there is only one or no elements. */
void	sb(t_cdl_list **top_b)
{
	ft_putendl_fd("sb", STDOUT_FILENO);
	try_swap(top_b);
}

/* ss : sa and sb at the same time. */
void	ss(t_cdl_list **top_a, t_cdl_list **top_b)
{
	ft_putendl_fd("ss", STDOUT_FILENO);
	try_swap(top_a);
	try_swap(top_b);
}

static void	try_swap(t_cdl_list **top)
{
	int	swap_tmp;

	if (get_node_count(*top) < 2)
		return ;
	swap_tmp = (*top)->value;
	(*top)->value = (*top)->next->value;
	(*top)->next->value = swap_tmp;
}
