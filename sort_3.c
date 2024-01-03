/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:23:44 by Philip            #+#    #+#             */
/*   Updated: 2024/01/03 19:56:43 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb_step_calc(t_step_track *st, t_lists_info li)
{
	t_index	b_i;

	if (!st || !li.node_a || !li.node_b || li.len_b < 1)
		return ;
	b_i = 0;
	while (b_i < li.len_b
		&& !sort_push_ok(li.node_a, li.node_b, DESCENDING, &li))
	{
		ordered_rotate__node_step_index(&(li.node_b), &(st->rb_steps), &b_i);
	}
	calc_total_steps(st);
}

void	ra_rrb_step_calc(t_step_track *st, t_lists_info li)
{
	t_index	b_i;

	if (!st || !li.node_a || !li.node_b || li.len_b < 1)
		return ;
	b_i = 0;
	while (b_i < li.len_b
		&& !sort_push_ok(li.node_a, li.node_b, DESCENDING, &li))
	{
		reversed_rotate__node_step_index(&(li.node_b), &(st->rrb_steps), &b_i);
	}
	calc_total_steps(st);
}

void	rra_rb_step_calc(t_step_track *st, t_lists_info li)
{
	t_index	b_i;

	if (!st || !li.node_a || !li.node_b || li.len_b < 1)
		return ;
	b_i = 0;
	while (b_i < li.len_b
		&& !sort_push_ok(li.node_a, li.node_b, DESCENDING, &li))
	{
		ordered_rotate__node_step_index(&(li.node_b), &(st->rb_steps), &b_i);
	}
	calc_total_steps(st);
}

void	rra_rrb_step_calc(t_step_track *st, t_lists_info li)
{
	t_index	b_i;

	if (!st || !li.node_a || !li.node_b || li.len_b < 1)
		return ;
	b_i = 0;
	while (b_i < li.len_b
		&& !sort_push_ok(li.node_a, li.node_b, DESCENDING, &li))
	{
		reversed_rotate__node_step_index(&(li.node_b), &(st->rrb_steps), &b_i);
	}
	calc_total_steps(st);
}

void	update_total_steps(t_step_track *step_track, t_step_track *target)
{
	if (!step_track || !target)
		return ;
	if (step_track->total_steps < target->total_steps)
		*target = *step_track;
}
