/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:23:44 by Philip            #+#    #+#             */
/*   Updated: 2024/01/02 23:26:38 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb_step_calc(t_step_track *st, t_cdl_list *node_a,
		t_cdl_list *node_b, int len_b)
{
	t_index	b_i;

	if (!st || !node_a || !node_b || len_b < 1)
		return ;
	b_i = 0;
	while (b_i < len_b && !sort_push_ok(node_a, node_b, DESCENDING))
	{
		b_i++;
		node_b = node_b->next;
		st->rb_steps++;
	}
	calc_total_steps(st);
}

void	ra_rrb_step_calc(t_step_track *st, t_cdl_list *node_a,
		t_cdl_list *node_b, int len_b)
{
	t_index	b_i;

	if (!st || !node_a || !node_b || len_b < 1)
		return ;
	b_i = 0;
	while (b_i < len_b && !sort_push_ok(node_a, node_b, DESCENDING))
	{
		b_i++;
		node_b = node_b->prev;
		st->rrb_steps++;
	}
	calc_total_steps(st);
}

void	rra_rb_step_calc(t_step_track *st, t_cdl_list *node_a,
		t_cdl_list *node_b, int len_b)
{
	t_index	b_i;

	if (!st || !node_a || !node_b || len_b < 1)
		return ;
	b_i = 0;
	while (b_i < len_b && !sort_push_ok(node_a, node_b, DESCENDING))
	{
		b_i++;
		node_b = node_b->next;
		st->rb_steps++;
	}
	calc_total_steps(st);
}

void	rra_rrb_step_calc(t_step_track *st, t_cdl_list *node_a,
		t_cdl_list *node_b, int len_b)
{
	t_index	b_i;

	if (!st || !node_a || !node_b || len_b < 1)
		return ;
	b_i = 0;
	while (b_i < len_b && !sort_push_ok(node_a, node_b, DESCENDING))
	{
		b_i++;
		node_b = node_b->prev;
		st->rrb_steps++;
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
