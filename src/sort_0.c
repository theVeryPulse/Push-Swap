/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:18:13 by Philip            #+#    #+#             */
/*   Updated: 2024/01/04 16:28:22 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if the list is sorted in ascending order from input node. */
int	is_sorted(t_cdl_list *top)
{
	int			node_count;
	t_cdl_list	*node;

	node_count = list_len(top);
	if (node_count == 0)
		return (-1);
	if (node_count == 1)
		return (1);
	if (node_count == 2)
		return (top->value < top->next->value);
	node = top->next;
	while (node != top)
	{
		if (node->value < node->prev->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	sort(t_cdl_list **top_a, t_cdl_list **top_b)
{
	int	len;

	if (!top_a || !(*top_a))
		return ;
	len = list_len(*top_a);
	if (len == 2)
		sort_two_nodes_a(top_a);
	else if (len == 3)
		sort_three_nodes_a(top_a);
	else if (len == 4)
		sort_four_nodes(top_a, top_b);
	else if (len == 5)
		sort_five_nodes(top_a, top_b);
	else
		sort_more_than_five_nodes(top_a, top_b);
}

void	sort_two_nodes_a(t_cdl_list **top_a)
{
	if (!top_a || !(*top_a))
		return ;
	if ((*top_a)->value > (*top_a)->next->value)
		sa(top_a, PRINT);
}

/* Five unsorted cases: 
   321 -sa--> 231 -rra-> 123
   312 -ra--> 123
   231 -rra-> 123
   213 -sa--> 123
   132 -rra-> 213 -sa--> 123 */
void	sort_three_nodes_a(t_cdl_list **top_a)
{
	int	val_0;
	int	val_1;
	int	val_2;

	if (!top_a || !(*top_a) || list_len(*top_a) != 3 || is_sorted(*top_a))
		return ;
	val_0 = (*top_a)->value;
	val_1 = (*top_a)->next->value;
	val_2 = (*top_a)->next->next->value;
	if (val_0 > val_1 && val_1 > val_2)
	{
		sa(top_a, PRINT);
		rra(top_a, PRINT);
	}
	else if (val_0 > val_2 && val_2 > val_1)
		ra(top_a, PRINT);
	else if (val_1 > val_0 && val_0 > val_2)
		rra(top_a, PRINT);
	else if (val_2 > val_0 && val_0 > val_1)
		sa(top_a, PRINT);
	else if (val_1 > val_2 && val_2 > val_0)
	{
		rra(top_a, PRINT);
		sa(top_a, PRINT);
	}
}

void	sort_four_nodes(t_cdl_list **top_a, t_cdl_list **top_b)
{
	pb(top_a, top_b, PRINT);
	sort_three_nodes_a(top_a);
	push_to_sorted_a(top_a, top_b);
	bring_min_to_top_a(top_a);
}
