/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:24:50 by Philip Li         #+#    #+#             */
/*   Updated: 2024/01/04 16:20:54 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	try_rotate(t_cdl_list **top);

/* ra (rotate a): Shift up all elements of stack a by 1.
   The first element becomes the last one. */
void	ra(t_cdl_list **top_a, t_print p)
{
	if (!top_a || list_len(*top_a) < 2)
		return ;
	if (p == PRINT)
		ft_putendl_fd("ra", STDOUT_FILENO);
	*top_a = (*top_a)->next;
}

/* rb (rotate b): Shift up all elements of stack b by 1.
   The first element becomes the last one.*/
void	rb(t_cdl_list **top_b, t_print p)
{
	if (!top_b || list_len(*top_b) < 2)
		return ;
	if (p == PRINT)
		ft_putendl_fd("rb", STDOUT_FILENO);
	*top_b = (*top_b)->next;
}

/* rr : ra and rb at the same time. */
void	rr(t_cdl_list **top_a, t_cdl_list **top_b, t_print p)
{
	if (p == PRINT)
		ft_putendl_fd("rr", STDOUT_FILENO);
	try_rotate(top_a);
	try_rotate(top_b);
}

static void	try_rotate(t_cdl_list **top)
{
	if (!top || list_len(*top) > 1)
		*top = (*top)->next;
}
