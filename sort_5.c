/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:15:43 by Philip            #+#    #+#             */
/*   Updated: 2024/01/03 19:57:00 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ordered_rotate__node_step_index(t_cdl_list **node, int *step, int *i)
{
	if (!node || !(*node) || !step || !i)
		return ;
	*node = (*node)->next;
	(*step)++;
	(*i)++;
}

void	reversed_rotate__node_step_index(t_cdl_list **node, int *step, int *i)
{
	if (!node || !(*node) || !step || !i)
		return ;
	*node = (*node)->prev;
	(*step)++;
	(*i)++;
}

void	pb_n_times(t_cdl_list **top_a, t_cdl_list **top_b, int n)
{
	if (!top_a || !(*top_a) || n <= 0)
		return ;
	while (n)
	{
		pb(top_a, top_b);
		n--;
	}
}

void	ra_rra_step_calc(t_step_track *st, t_lists_info *li, t_cdl_list **top_a,
			t_cdl_list **top_b)
{
	*st = (t_step_track){.ra_steps = 0, .rra_steps = 0};
	li->node_a = *top_a;
	li->a_i = 0;
	li->len_a = list_len(li->node_a);
	li->dst_max = list_max(li->node_a);
	li->dst_min = list_min(li->node_a);
	while (li->a_i < li->len_a
		&& !sort_push_ok(*top_b, li->node_a, ASCENDING, li))
	{
		ordered_rotate__node_step_index(&(li->node_a), &(st->ra_steps),
			&(li->a_i));
	}
	li->node_a = *top_a;
	li->a_i = 0;
	while (li->a_i < li->len_a
		&& !sort_push_ok(*top_b, li->node_a, ASCENDING, li))
	{
		reversed_rotate__node_step_index(&li->node_a, &st->rra_steps,
			&(li->a_i));
	}
}

void	sort_the_rest(t_cdl_list **top_a, t_cdl_list **top_b)
{
	int				nodes_to_sort;
	t_step_track	st;
	t_lists_info	li;

	if (!top_a || !(*top_a))
		return ;
	li.len_a = list_len(*top_a);
	nodes_to_sort = li.len_a - 3;
	pb_n_times(top_a, top_b, li.len_a - 3);
	sort_three_nodes_a(top_a);
	while (nodes_to_sort)
	{
		ra_rra_step_calc(&st, &li, top_a, top_b);
		if (st.ra_steps < st.rra_steps)
			all_ordered_rotates(st, top_a, NULL);
		else
			all_reverse_rotates(st, top_a, NULL);
		pa(top_a, top_b);
		nodes_to_sort--;
	}
}
