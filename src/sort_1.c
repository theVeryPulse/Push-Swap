/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:12:34 by Philip            #+#    #+#             */
/*   Updated: 2024/01/03 20:29:21 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_nodes(t_cdl_list **top_a, t_cdl_list **top_b)
{
	pb(top_a, top_b);
	pb(top_a, top_b);
	if ((*top_b)->value < (*top_b)->next->value)
		sb(top_b);
	sort_three_nodes_a(top_a);
	push_to_sorted_a(top_a, top_b);
	bring_min_to_top_a(top_a);
}

/*  Note:
    - For better performance, this sort uses a simpler sort when stack B is 
      over 10 timers larger than stack A. */
void	sort_more_than_five_nodes(t_cdl_list **top_a, t_cdl_list **top_b)
{
	if (!top_a || !(*top_a))
		return ;
	pb_n_times(top_a, top_b, 2);
	while (list_len(*top_a) > 3 && list_len(*top_a) * 10 > list_len(*top_b))
		push_cheapest_node(top_a, top_b);
	if (list_len(*top_a) > 3)
		sort_the_rest(top_a, top_b);
	else
		sort_three_nodes_a(top_a);
	push_to_sorted_a(top_a, top_b);
	bring_min_to_top_a(top_a);
}

void	push_to_sorted_a(t_cdl_list **top_a, t_cdl_list **top_b)
{
	if (!top_a || !top_b || !(*top_a) || !(*top_b))
		return ;
	while (list_len(*top_b) > 0)
	{
		if (sort_push_ok(*top_b, *top_a, ASCENDING, NULL))
			pa(top_a, top_b);
		else
			rra(top_a);
	}
}

void	bring_min_to_top_a(t_cdl_list **top_a)
{
	int				min;
	t_cdl_list		*node;
	t_step_track	st;

	if (!top_a || !(*top_a) || list_len(*top_a) < 2 || is_sorted(*top_a))
		return ;
	min = list_min(*top_a);
	st = (t_step_track){.ra_steps = 1, .rra_steps = 1};
	node = (*top_a)->next;
	while (node->value != min && node != *top_a)
	{
		node = node->next;
		st.ra_steps++;
	}
	node = (*top_a)->prev;
	while (node->value != min && node != *top_a)
	{
		node = node->prev;
		st.rra_steps++;
	}
	if (st.ra_steps < st.rra_steps)
		all_ordered_rotates(st, top_a, NULL);
	else
		all_reverse_rotates(st, top_a, NULL);
}

void	push_cheapest_node(t_cdl_list **top_a, t_cdl_list **top_b)
{
	t_step_track	st;
	t_step_track	target;
	t_lists_info	li;

	if (!top_a || !top_b || !(*top_a) || !(*top_b))
		return ;
	target.total_steps = INT_MAX;
	li = (t_lists_info){.a_i = 0, .node_a = *top_a, .node_b = *top_b,
		.len_a = list_len(*top_a), .len_b = list_len(*top_b),
		.dst_max = list_max(*top_b), .dst_min = list_min(*top_b)};
	while (li.a_i < li.len_a)
	{
		calc_push_steps(li, &st, &target);
		next_node_index_add_one(&(li.node_a), &(li.a_i));
	}
	rotate_and_pb(target, top_a, top_b);
}
