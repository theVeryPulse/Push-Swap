/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:26:48 by Philip            #+#    #+#             */
/*   Updated: 2024/01/02 23:35:10 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort_push_ok(t_cdl_list *src, t_cdl_list *dst, t_order order)
{
	int		dst_max;
	int		dst_min;
	bool	push_ready;

	if (!src)
		return (false);
	dst_max = list_max(dst);
	dst_min = list_min(dst);
	if (order == DESCENDING)
		push_ready = ((src->value > dst->value && src->value < dst->prev->value)
				|| (src->value > dst_max && dst->value == dst_max)
				|| (src->value < dst_min && dst->value == dst_max));
	if (order == ASCENDING)
		push_ready = ((src->value < dst->value && src->value > dst->prev->value)
				|| (src->value > dst_max && dst->value == dst_min)
				|| (src->value < dst_min && dst->value == dst_min));
	return (push_ready);
}

/* Calculates the total steps for a specific rotating case. It assumes all 
   irrelevant items (fields) are set to zeros. */
void	calc_total_steps(t_step_track *track)
{
	if (!track)
		return ;
	while (track->ra_steps && track->rb_steps)
	{
		track->rr_steps++;
		track->ra_steps--;
		track->rb_steps--;
	}
	while (track->rra_steps && track->rrb_steps)
	{
		track->rrr_steps++;
		track->rra_steps--;
		track->rrb_steps--;
	}
	track->total_steps = track->ra_steps + track->rb_steps + track->rr_steps
		+ track->rra_steps + track->rrb_steps + track->rrr_steps;
}

void	all_ordered_rotates(t_step_track st, t_cdl_list **top_a,
	t_cdl_list **top_b)
{
	while (st.ra_steps)
	{
		ra(top_a);
		st.ra_steps--;
	}
	while (st.rb_steps)
	{
		rb(top_b);
		st.rb_steps--;
	}
	while (st.rr_steps)
	{
		rr(top_a, top_b);
		st.rr_steps--;
	}
}

void	all_reverse_rotates(t_step_track st, t_cdl_list **top_a,
	t_cdl_list **top_b)
{
	while (st.rra_steps)
	{
		rra(top_a);
		st.rra_steps--;
	}
	while (st.rrb_steps)
	{
		rrb(top_b);
		st.rrb_steps--;
	}
	while (st.rrr_steps)
	{
		rrr(top_a, top_b);
		st.rrr_steps--;
	}
}
