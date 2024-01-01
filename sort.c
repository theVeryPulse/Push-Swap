/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:18:13 by Philip            #+#    #+#             */
/*   Updated: 2024/01/01 16:13:49 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Push two elements to stack B to form max and min.

	While there are more than 3 nodes in stack A
		Calculate the cheapest node to push into descending order. 
	Sort the 3 nodes of stack A
	While stack B is not empty
		Push nodes into ascending order in stack A

	
*/

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

	if (!top_a || !(*top_a) || get_node_count(*top_a) != 3 || is_sorted(*top_a))
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

/* 
   4 elements:
   1 2 3 | 4 pa rra
   1 2 4 | 3 ra ra pa rra rra
   1 3 4 | 2 ra pa rra
   2 3 4 | 1 pa  */
void	push_to_sorted_a(t_cdl_list **top_a, t_cdl_list **top_b)
{
	if (!top_a || !top_b || !(*top_a) || !(*top_b))
		return ;
	while (get_node_count(*top_b) > 0)
	{
		if (((*top_b)->value < (*top_a)->value && (*top_b)->value > (*top_a)->prev->value)
			|| ((*top_b)->value > list_max(*top_a) && (*top_a)->prev->value == list_max(*top_a))
			|| ((*top_b)->value < list_min(*top_a) && (*top_a)->value == list_min(*top_a)))
			pa(top_a, top_b);
		else
			rra(top_a);
	}
}

void	bring_min_to_top_a(t_cdl_list **top_a)
{
	int			min;
	t_cdl_list	*node;
	int			ra_steps;
	int			rra_steps;

	if (!top_a || !(*top_a) || get_node_count(*top_a) < 2 || is_sorted(*top_a))
		return ;
	min = list_min(*top_a);

	/* Calculate steps for ordered rotate. */
	node = (*top_a)->next;
	ra_steps = 1;
	while (node->value != min && node != *top_a)
	{
		node = node->next;
		ra_steps++;
	}

	/* Calculate steps for reversed rotate. */
	node = (*top_a)->prev;
	rra_steps = 1;
	while (node->value != min && node != *top_a)
	{
		node = node->prev;
		rra_steps++;
	}
	if (ra_steps < rra_steps)
	{
		while ((*top_a)->value != min)
			ra(top_a);
	}
	else
	{
		while ((*top_a)->value != min)
			rra(top_a);
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

enum	e_rotate_case
{
	RA_RB,
	RA_RRB,
	RRA_RB,
	RRA_RRB
};
typedef enum e_rotate_case t_rotate_case;

struct	s_step_track
{
	int				node_value;
	t_rotate_case	rotate_case;
	int				ra_steps;
	int				rb_steps;
	int				rr_steps;
	int				rra_steps;
	int				rrb_steps;
	int				rrr_steps;
	int				total_steps;
};
/* Tracking steps and rotate case */
typedef struct s_step_track t_step_track;

// int	ready_for_pb(t_cdl_list *top_a, t_cdl_list *top_b)
// {
// 	if (!top_a || !top_b)
// 		return (-1);

// 	int	b_i;
// 	int	correct_top_b_val_for_pb;
// 	t_cdl_list	*node_b;
// 	b_i = 0;
// 	node_b = top_b;
// 	correct_top_b_val_for_pb = top_b->value;
// 	while (b_i < get_node_count(top_b))
// 	{
// 		if (top_a->value > top_b->value
// 			&& top_a->value < top_b->prev->value
// 			&& )
// 		{

// 		}
// 		node_b = node_b->next;
// 		b_i++;
// 	}

// 	if ((top_a->value > top_b->value && top_a->value < top_b->prev->value)
// 		|| (top_a->value > list_max(top_b) && top_b->value == list_max(top_b))
// 		|| (top_a->value < list_min(top_b) && top_b->value == list_max(top_b)))
// }
/* 15 12 8 1 10 20 16 17 11 5 14 18 13 2 19 9 7 3 6 4  */
/* 
   When calling the function, there should be more than 3 nodes in list a and
   exactly 2 nodes in descending order in list b.
   
   Information for pushing cheapest node:
   - total steps for pushing
   - the price of pushing each node,
   - the case for pushing that node (ra-rb, ra-rrb etc.)
   */
void	push_cheapest_node(t_cdl_list **top_a, t_cdl_list **top_b)
{
	t_step_track	step_track;
	t_step_track	target_rotates;
	t_cdl_list		*node_a;
	t_cdl_list		*node_b;
	t_index			a_i;
	t_index			b_i;

	if (!top_a || !top_b || !(*top_a) || !(*top_b))
		return ;
	/* Find the cheapest node */
	a_i = 0;
	node_a = *top_a;
	target_rotates.total_steps = INT_MAX;
	/* 15 12 8 1 10 20 16 17 11 5 14 18 13 2 19 9 7 3 6 4  */
	/* For each node(value) in list a */
	while (a_i < get_node_count(*top_a))
	{
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

		while (b_i < get_node_count(*top_b))
		{
			if ((node_a->value > node_b->value && node_a->value < node_b->prev->value)
				|| (node_a->value > list_max(node_b) && node_b->value == list_max(node_b))
				|| (node_a->value < list_min(node_b) && node_b->value == list_max(node_b)))
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
		// step_track.ra_steps = a_i;

		b_i = 0;
		node_b = *top_b;
		// step_track.rrb_steps = 0;

		while (b_i < get_node_count(*top_b))
		{
			if ((node_a->value > node_b->value && node_a->value < node_b->prev->value)
				|| (node_a->value > list_max(node_b) && node_b->value == list_max(node_b))
				|| (node_a->value < list_min(node_b) && node_b->value == list_max(node_b)))
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
			.rra_steps = get_node_count(node_a) - a_i,
			.rb_steps = 0,
		};
		// step_track.rra_steps = get_node_count(node_a) - a_i;

		b_i = 0;
		node_b = *top_b;
		// step_track.rb_steps = 0;

		while (b_i < get_node_count(*top_b))
		{
			if ((node_a->value > node_b->value && node_a->value < node_b->prev->value)
				|| (node_a->value > list_max(node_b) && node_b->value == list_max(node_b))
				|| (node_a->value < list_min(node_b) && node_b->value == list_max(node_b)))
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
			.rra_steps = get_node_count(node_a) - a_i,
			.rrb_steps = 0
		};
		// step_track.rra_steps = get_node_count(node_a) - a_i;
		// step_track.rrb_steps = 0;
		// step_track.rrr_steps = 0;

		b_i = 0;
		node_b = *top_b;

		while (b_i < get_node_count(*top_b))
		{
			if ((node_a->value > node_b->value && node_a->value < node_b->prev->value)
				|| (node_a->value > list_max(node_b) && node_b->value == list_max(node_b))
				|| (node_a->value < list_min(node_b) && node_b->value == list_max(node_b)))
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
		/* Possible refactor: total_steps(&step_track) */
		step_track.total_steps = step_track.rra_steps + step_track.rrb_steps + step_track.rrr_steps;
		if (step_track.total_steps < target_rotates.total_steps)
		{
			target_rotates = step_track;
			step_track.node_value = node_a->value;
			// step_track.total_steps = step_track.rra_steps + step_track.rrb_steps + step_track.rrr_steps;
			// step_track.rotate_case = RRA_RRB;
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
	if (target_rotates.rotate_case == RA_RRB)
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
	if (target_rotates.rotate_case == RRA_RB)
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
	if (target_rotates.rotate_case == RRA_RRB)
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

void	sort(t_cdl_list **top_a, t_cdl_list **top_b)
{
	if (!top_a || !(*top_a))
		return ;
	if (get_node_count(*top_a) == 2)
		return (sort_two_nodes_a(top_a));
	else if (get_node_count(*top_a) == 3)
		return (sort_three_nodes_a(top_a));
	else if (get_node_count(*top_a) == 4)
		return (sort_four_nodes(top_a, top_b));
	else if (get_node_count(*top_a) == 5)
		return (sort_five_nodes(top_a, top_b));
	else // > 5 nodes
	{
		pb(top_a, top_b);
		pb(top_a, top_b);
		if ((*top_b)->value < (*top_b)->next->value)
			sb(top_b);
		while (get_node_count(*top_a) > 3)
		{
			push_cheapest_node(top_a, top_b);	
		}
		sort_three_nodes_a(top_a);
		push_to_sorted_a(top_a, top_b);
		bring_min_to_top_a(top_a);
	}
}
