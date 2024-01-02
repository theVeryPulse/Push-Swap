/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:18:13 by Philip            #+#    #+#             */
/*   Updated: 2024/01/01 18:49:40 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Push two elements to stack B to form max and min.

	While there are more than 3 nodes in stack A
		Calculate the cheapest node to push into descending order. 
	Sort the 3 nodes of stack A
	While stack B is not empty
		Push nodes into ascending order in stack A */

void	sort_two_nodes_a(t_cdl_list **top_a)
{
	if (!top_a || !(*top_a))
		return ;
	if ((*top_a)->value > (*top_a)->next->value)
		sa(top_a);
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
		sa(top_a);
		rra(top_a);
	}
	else if (val_0 > val_2 && val_2 > val_1)
		ra(top_a);
	else if (val_1 > val_0 && val_0 > val_2)
		rra(top_a);
	else if (val_2 > val_0 && val_0 > val_1)
		sa(top_a);
	else if (val_1 > val_2 && val_2 > val_0)
	{
		rra(top_a);
		sa(top_a);
	}
}

bool	sort_push_ok(t_cdl_list *src, t_cdl_list *dst)
{
	int		dst_max;
	int		dst_min;
	bool	push_ready;

	if (!src || !dst)
		return (false);
	dst_max = list_max(dst);
	dst_min = list_min(dst);
	push_ready = 
	(
		(src->value > dst->value && src->value < dst->prev->value)
		|| (src->value > dst_max && dst->value == dst_max)
		|| (src->value < dst_min && dst->value == dst_min)
	);
	return (push_ready)
}

void	push_to_sorted_a(t_cdl_list **top_a, t_cdl_list **top_b)
{
	if (!top_a || !top_b || !(*top_a) || !(*top_b))
		return ;
	while (list_len(*top_b) > 0)
	{
		/* if (((*top_b)->value < (*top_a)->value && (*top_b)->value > (*top_a)->prev->value)
			|| ((*top_b)->value > list_max(*top_a) && (*top_a)->prev->value == list_max(*top_a))
			|| ((*top_b)->value < list_min(*top_a) && (*top_a)->value == list_min(*top_a)))
			pa(top_a, top_b); */
		if (sort_push_ok(*top_b, *top_a))
			pa(top_a, top_b);
		else
			rra(top_a);
	}
}

void	bring_min_to_top_a(t_cdl_list **top_a)
{
	int				min;
	t_cdl_list		*node;
	t_step_track	step_track;

	if (!top_a || !(*top_a) || list_len(*top_a) < 2 || is_sorted(*top_a))
		return ;
	min = list_min(*top_a);
	step_track = (t_step_track){.ra_steps = 1, .rra_steps = 1};
	node = (*top_a)->next;
	while (node->value != min && node != *top_a)
	{
		node = node->next;
		step_track.ra_steps++;
	}
	node = (*top_a)->prev;
	while (node->value != min && node != *top_a)
	{
		node = node->prev;
		step_track.rra_steps++;
	}
	if (step_track.ra_steps < step_track.rra_steps)
	{
		while (step_track.ra_steps)
		{
			step_track.ra_steps--;
			ra(top_a);
		}
	}
	else
	{
		while (step_track.rra_steps)
		{
			step_track.rra_steps--;
			rra(top_a);
		}
	}
}

void	sort_four_nodes(t_cdl_list **top_a, t_cdl_list **top_b)
{
	pb(top_a, top_b);
	sort_three_nodes_a(top_a);
	push_to_sorted_a(top_a, top_b);
	bring_min_to_top_a(top_a);
}

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
void	rotate_lists(t_step_track steps)
{
	return ;
}

void	push_cheapest_node(t_cdl_list **top_a, t_cdl_list **top_b)
{
	t_step_track	step_track;
	t_step_track	target_rotates;
	t_cdl_list		*node_a;
	t_cdl_list		*node_b;
	t_index			a_i;
	t_index			b_i;
	int				len_a;
	int				len_b;

	if (!top_a || !top_b || !(*top_a) || !(*top_b))
		return ;
	len_a = list_len(*top_a);
	len_b = list_len(*top_b);
	/* Find the cheapest node */
	a_i = 0;
	node_a = *top_a;
	target_rotates.total_steps = INT_MAX;
	/* For each node(value) in list a */
	while (a_i < len_a)
	{
		if (a_i > 30 && a_i < len_a - 30)
		{
			a_i++;
			node_a = node_a->next;
			continue ;
		}
		/* ra rb ================================= */
		step_track = (t_step_track)
		{
			.rotate_case = RA_RB,
			.ra_steps = a_i,
			.rb_steps = 0,
			.rr_steps = 0,
		};
		b_i = 0;
		node_b = *top_b;

		while (b_i < len_b)
		{
			/* if ((node_a->value > node_b->value && node_a->value < node_b->prev->value)
				|| (node_a->value > list_max(node_b) && node_b->value == list_max(node_b))
				|| (node_a->value < list_min(node_b) && node_b->value == list_max(node_b))) */
			if (sort_push_ok(node_a, node_b))	
				break;
			b_i++;
			node_b = node_b->next;
			step_track.rb_steps++;
		}
		while (step_track.ra_steps && step_track.rb_steps)
		{
			step_track.rr_steps++;
			step_track.ra_steps--;
			step_track.rb_steps--;
		}
		step_track.total_steps = step_track.ra_steps + step_track.rb_steps + step_track.rr_steps;
		if (step_track.total_steps < target_rotates.total_steps)
		{
			target_rotates = step_track;
			target_rotates.node_value = node_a->value;
		}

		/* ra rrb ================================= */
		step_track = (t_step_track)
		{
			.rotate_case = RA_RRB,
			.ra_steps = a_i,
			.rrb_steps = 0,
		};
		b_i = 0;
		node_b = *top_b;
		while (b_i < len_b)
		{
/* 			if ((node_a->value > node_b->value && node_a->value < node_b->prev->value)
				|| (node_a->value > list_max(node_b) && node_b->value == list_max(node_b))
				|| (node_a->value < list_min(node_b) && node_b->value == list_max(node_b))) */
			if (sort_push_ok(node_a, node_b))	
				break;
			b_i++;
			node_b = node_b->prev;
			step_track.rrb_steps++;
		}
		step_track.total_steps = step_track.ra_steps + step_track.rrb_steps;
		if (step_track.total_steps < target_rotates.total_steps)
		{
			target_rotates = step_track;
			target_rotates.node_value = node_a->value;
		}

		/* rra rb [0, 1, 2, 3] ================================= */
		step_track = (t_step_track)
		{
			.rotate_case = RRA_RB,
			.rra_steps = list_len(node_a) - a_i,
			.rb_steps = 0,
		};
		b_i = 0;
		node_b = *top_b;
		while (b_i < len_b)
		{
/* 			if ((node_a->value > node_b->value && node_a->value < node_b->prev->value)
				|| (node_a->value > list_max(node_b) && node_b->value == list_max(node_b))
				|| (node_a->value < list_min(node_b) && node_b->value == list_max(node_b))) */
			if (sort_push_ok(node_a, node_b))	
				break;
			b_i++;
			node_b = node_b->next;
			step_track.rb_steps++;
		}
		step_track.total_steps = step_track.rra_steps + step_track.rb_steps;
		if (step_track.total_steps < target_rotates.total_steps)
		{
			target_rotates = step_track;
			step_track.node_value = node_a->value;
		}


		/* rra rrb ================================= */
		step_track = (t_step_track)
		{
			.rotate_case = RRA_RRB,
			.rra_steps = list_len(node_a) - a_i,
			.rrb_steps = 0
		};
		b_i = 0;
		node_b = *top_b;
		while (b_i < len_b)
		{
		/* 	if ((node_a->value > node_b->value && node_a->value < node_b->prev->value)
				|| (node_a->value > list_max(node_b) && node_b->value == list_max(node_b))
				|| (node_a->value < list_min(node_b) && node_b->value == list_max(node_b))) */
			if (sort_push_ok(node_a, node_b))	
				break;
			b_i++;
			node_b = node_b->prev;
			step_track.rrb_steps++;
		}
		while (step_track.rra_steps && step_track.rrb_steps)
		{
			step_track.rrr_steps++;
			step_track.rra_steps--;
			step_track.rrb_steps--;
		}
		step_track.total_steps = step_track.rra_steps + step_track.rrb_steps + step_track.rrr_steps;
		if (step_track.total_steps < target_rotates.total_steps)
		{
			target_rotates = step_track;
			step_track.node_value = node_a->value;
		}

		a_i++;
		node_a = node_a->next;
	}
	
	/* Push the cheapest node */
	if (target_rotates.rotate_case == RA_RB)
	{
		while (target_rotates.rr_steps)
		{
			rr(top_a, top_b);
			target_rotates.rr_steps--;
		}
		while (target_rotates.ra_steps)
		{
			ra(top_a);
			target_rotates.ra_steps--;
		}
		while (target_rotates.rb_steps)
		{
			rb(top_b);
			target_rotates.rb_steps--;
		}
	}
	else if (target_rotates.rotate_case == RA_RRB)
	{
		while (target_rotates.ra_steps)
		{
			ra(top_a);
			target_rotates.ra_steps--;
		}
		while (target_rotates.rrb_steps)
		{
			rrb(top_b);
			target_rotates.rrb_steps--;
		}
	}
	else if (target_rotates.rotate_case == RRA_RB)
	{
		while (target_rotates.rra_steps)
		{
			rra(top_a);
			target_rotates.rra_steps--;
		}
		while (target_rotates.rb_steps)
		{
			rb(top_b);
			target_rotates.rb_steps--;
		}
	}
	else
	{
		while (target_rotates.rrr_steps)
		{
			rrr(top_a, top_b);
			target_rotates.rrr_steps--;
		}
		while (target_rotates.rra_steps)
		{
			rra(top_a);
			target_rotates.rra_steps--;
		}
		while (target_rotates.rrb_steps)
		{
			rrb(top_b);
			target_rotates.rrb_steps--;
		}
	}
	pb(top_a, top_b);
}

void	sort_more_than_five_nodes(t_cdl_list **top_a, t_cdl_list **top_b)
{
	if (!top_a || !(*top_a))
		return ;
	pb(top_a, top_b);
	pb(top_a, top_b);
	while (list_len(*top_a) > 3)
		push_cheapest_node(top_a, top_b);
	sort_three_nodes_a(top_a);
	push_to_sorted_a(top_a, top_b);
	bring_min_to_top_a(top_a);
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
