/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:24:50 by Philip Li         #+#    #+#             */
/*   Updated: 2023/12/15 00:24:50 by Philip Li        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	try_rotate(t_cbl_list **top);

/* ra (rotate a): Shift up all elements of stack a by 1.
   The first element becomes the last one. */
void	ra(t_cbl_list **top_a)
{
	ft_putendl_fd("ra", STDOUT_FILENO);
	try_rotate(top_a);
}

/* rb (rotate b): Shift up all elements of stack b by 1.
   The first element becomes the last one.*/
void	rb(t_cbl_list **top_b)
{
	ft_putendl_fd("rb", STDOUT_FILENO);
	try_rotate(top_b);
}

/* rr : ra and rb at the same time. */
void	rr(t_cbl_list **top_a, t_cbl_list **top_b)
{
	ft_putendl_fd("rr", STDOUT_FILENO);
	try_rotate(top_a);
	try_rotate(top_b);
}

static void	try_rotate(t_cbl_list **top)
{
	if (get_node_count(*top) > 1)
		*top = (*top)->next;
}