/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:49:45 by Philip            #+#    #+#             */
/*   Updated: 2023/12/29 14:51:27 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pa (push a): Take the first element at the top of b and put it at the top
   of a. Do nothing if b is empty. */
void	pa(t_cdl_list **top_a, t_cdl_list **top_b)
{
	if (!top_b || !(*top_b))
		return ;
	ft_putendl_fd("pa", STDOUT_FILENO);
	list_push(top_a, list_pop(top_b));
}

/* pb (push b): Take the first element at the top of a and put it at the top
   of b. Do nothing if a is empty. */
void	pb(t_cdl_list **top_a, t_cdl_list **top_b)
{
	if (!top_a || !(*top_a))
		return ;
	ft_putendl_fd("pb", STDOUT_FILENO);
	list_push(top_b, list_pop(top_a));
}
