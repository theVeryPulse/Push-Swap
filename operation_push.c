/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:49:45 by Philip            #+#    #+#             */
/*   Updated: 2023/12/15 13:26:06 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	try_pop_and_push(t_cdl_list **src_list, t_cdl_list **dst_list);

/* pa (push a): Take the first element at the top of b and put it at the top
   of a. Do nothing if b is empty. */
void	pa(t_cdl_list **top_a, t_cdl_list **top_b)
{
	ft_putendl_fd("pa", STDOUT_FILENO);
	try_pop_and_push(top_b, top_a);
}

/* pb (push b): Take the first element at the top of a and put it at the top
   of b. Do nothing if a is empty. */
void	pb(t_cdl_list **top_a, t_cdl_list **top_b)
{
	ft_putendl_fd("pb", STDOUT_FILENO);
	try_pop_and_push(top_a, top_b);
}

static void	try_pop_and_push(t_cdl_list **src_list, t_cdl_list **dst_list)
{
	t_cdl_list	*node_to_push;

	if (!src_list || !(*src_list))
		return ;
	node_to_push = list_pop(src_list);
	list_push(dst_list, node_to_push);
}
