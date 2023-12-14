/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:38:04 by juli              #+#    #+#             */
/*   Updated: 2023/12/14 21:55:27 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_value(int *a, int *b)
{
	int	swap_tmp;

	swap_tmp = *a;
	*a = *b;
	*b = swap_tmp;
}

// SWAP =======================================================================
bool	list_needs_no_swap(t_cbl_list **top)
{
	return(!top || !(*top) || !((*top)->next));
}

bool	list_allows_swap(t_cbl_list **top)
{
	return(top && (*top) && (*top)->next);
}

void	try_swap(t_cbl_list **top)
{
	if (list_allows_swap(top))
		swap_value(&((*top)->value), &((*top)->next->value));
}

/* sa (swap a): Swap the first 2 elements at the top of stack a.
   Do nothing if there is only one or no elements. */
void	sa(t_cbl_list **top_a)
{
	ft_putendl_fd("sa", STDOUT_FILENO);
	try_swap(top_a);
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
   Do nothing if there is only one or no elements. */
void	sb(t_cbl_list **top_b)
{
	ft_putendl_fd("sb", STDOUT_FILENO);
	try_swap(top_b);
}

/* ss : sa and sb at the same time. */
void	ss(t_cbl_list **top_a, t_cbl_list **top_b)
{
	ft_putendl_fd("ss", STDOUT_FILENO);
	try_swap(top_a);
	try_swap(top_b);
}

void	try_rotate(t_cbl_list **top)
{
	if (get_node_count(*top) > 1)
		*top = (*top)->next;
}

// ROTATE =====================================================================
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

// REVERSE ROTATE =============================================================
void	try_revserse_rotate(t_cbl_list **top)
{
	if (get_node_count(*top) > 1)
		*top = (*top)->prev;
}
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