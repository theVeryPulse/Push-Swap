/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:25:39 by Philip Li         #+#    #+#             */
/*   Updated: 2023/12/15 00:25:39 by Philip Li        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	try_revserse_rotate(t_cbl_list **top);

/* rra (reverse rotate a): Shift down all elements of stack a by 1.
   The last element becomes the first one.*/
void	rra(t_cbl_list **top_a)
{
	ft_putendl_fd("rra", STDOUT_FILENO);
	try_revserse_rotate(top_a);
}

/* rrb (reverse rotate b): Shift down all elements of stack b by 1.
   The last element becomes the first one. */
void	rrb(t_cbl_list **top_b)
{
	ft_putendl_fd("rrb", STDOUT_FILENO);
	try_revserse_rotate(top_b);
}

/* rrr : rra and rrb at the same time. */
void	rrr(t_cbl_list **top_a, t_cbl_list **top_b)
{
	ft_putendl_fd("rrr", STDOUT_FILENO);
	try_revserse_rotate(top_a);
	try_revserse_rotate(top_b);
}

static void	try_revserse_rotate(t_cbl_list **top)
{
	if (get_node_count(*top) > 1)
		*top = (*top)->prev;
}