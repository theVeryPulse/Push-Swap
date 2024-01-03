/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:18:36 by Philip            #+#    #+#             */
/*   Updated: 2024/01/02 23:43:50 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	less_likely_to_have_better_solutions(t_lists_info li)
{
	int	margin;

	margin = (li.len_a + li.len_b) / 10;
	return (li.a_i > margin && li.a_i < li.len_a - margin);
}

bool	likely_to_have_better_solutions(t_lists_info li)
{
	return (!less_likely_to_have_better_solutions(li));
}

void	calc_push_steps(t_lists_info li, t_step_track *st, t_step_track *target)
{
	if (!st || !target)
		return ;
	*st = (t_step_track){
		.rotate_case = RA_RB, .ra_steps = li.a_i};
	ra_rb_step_calc(st, li.node_a, li.node_b, li.len_b);
	update_total_steps(st, target);
	*st = (t_step_track){
		.rotate_case = RA_RRB, .ra_steps = li.a_i};
	ra_rrb_step_calc(st, li.node_a, li.node_b, li.len_b);
	update_total_steps(st, target);
	*st = (t_step_track){
		.rotate_case = RRA_RB, .rra_steps = li.len_a - li.a_i};
	rra_rb_step_calc(st, li.node_a, li.node_b, li.len_b);
	update_total_steps(st, target);
	*st = (t_step_track){
		.rotate_case = RRA_RRB, .rra_steps = li.len_a - li.a_i};
	rra_rrb_step_calc(st, li.node_a, li.node_b, li.len_b);
	update_total_steps(st, target);
}

void	next_node_index_add_one(t_cdl_list **node, int *i)
{
	if (!node || !(*node) || !i)
		return ;
	*node = (*node)->next;
	(*i)++;
}

void	rotate_and_pb(t_step_track target, t_cdl_list **top_a,
	t_cdl_list **top_b)
{
	all_ordered_rotates(target, top_a, top_b);
	all_reverse_rotates(target, top_a, top_b);
	pb(top_a, top_b);
}
