/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:42:38 by Philip Li         #+#    #+#             */
/*   Updated: 2024/01/03 20:12:25 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef int	t_index;

/* Circular Doubly Linked list */
typedef struct s_cdl_list
{
	int					value;
	struct s_cdl_list	*prev;
	struct s_cdl_list	*next;
}	t_cdl_list;

typedef enum e_rotate_case
{
	RA_RB,
	RA_RRB,
	RRA_RB,
	RRA_RRB
}	t_rotate_case;

/* Note: 'rotate_case' item is not used for the algorithm, but helps to
   improve readability. */
typedef struct s_step_track
{
	t_rotate_case	rotate_case;
	int				ra_steps;
	int				rb_steps;
	int				rr_steps;
	int				rra_steps;
	int				rrb_steps;
	int				rrr_steps;
	int				total_steps;
}	t_step_track;

typedef enum e_order
{
	ASCENDING,
	DESCENDING
}	t_order;

typedef struct s_lists_info
{
	t_index		a_i;
	t_cdl_list	*node_a;
	t_cdl_list	*node_b;
	int			len_a;
	int			len_b;
	int			dst_max;
	int			dst_min;
}	t_lists_info;

/* List operations ========================================================== */

void		list_append(t_cdl_list **top, int value);
t_cdl_list	*list_pop(t_cdl_list **top);
void		list_push(t_cdl_list **top, t_cdl_list *node_to_push);
int			list_len(t_cdl_list *top);
void		isolate_node(t_cdl_list *node);
void		free_list(t_cdl_list **top);
int			list_min(t_cdl_list *top);
int			list_max(t_cdl_list *top);

/* Input check ============================================================== */

bool		is_invalid_input(int argc, char **argv);
int			is_sorted(t_cdl_list *top);
int			list_has_duplicates(t_cdl_list **top);
int			is_beyond_int(char *s);

/* Designated operations ==================================================== */

void		sa(t_cdl_list **top_a);
void		sb(t_cdl_list **top_b);
void		ss(t_cdl_list **top_a, t_cdl_list **top_b);
void		pa(t_cdl_list **top_a, t_cdl_list **top_b);
void		pb(t_cdl_list **top_a, t_cdl_list **top_b);
void		ra(t_cdl_list **top_a);
void		rb(t_cdl_list **top_b);
void		rr(t_cdl_list **top_a, t_cdl_list **top_b);
void		rra(t_cdl_list **top_a);
void		rrb(t_cdl_list **top_b);
void		rrr(t_cdl_list **top_a, t_cdl_list **top_b);

/* Sorting related ========================================================== */

void		all_ordered_rotates(t_step_track st, t_cdl_list **top_a,
				t_cdl_list **top_b);
void		all_reverse_rotates(t_step_track st, t_cdl_list **top_a,
				t_cdl_list **top_b);
void		bring_min_to_top_a(t_cdl_list **top_a);
void		calc_push_steps(t_lists_info li, t_step_track *st,
				t_step_track *target);
void		calc_total_steps(t_step_track *track);
int			is_sorted(t_cdl_list *top);
void		next_node_index_add_one(t_cdl_list **node, int *i);
void		ordered_rotate__node_step_index(t_cdl_list **node, int *step,
				int *i);
void		pb_n_times(t_cdl_list **top_a, t_cdl_list **top_b, int n);
void		push_cheapest_node(t_cdl_list **top_a, t_cdl_list **top_b);
void		push_to_sorted_a(t_cdl_list **top_a, t_cdl_list **top_b);
void		ra_rb_step_calc(t_step_track *st, t_lists_info li);
void		ra_rra_step_calc(t_step_track *st, t_lists_info *li,
				t_cdl_list **top_a, t_cdl_list **top_b);
void		ra_rrb_step_calc(t_step_track *st, t_lists_info li);
void		reversed_rotate__node_step_index(t_cdl_list **node, int *step,
				int *i);
void		rotate_and_pb(t_step_track target, t_cdl_list **top_a,
				t_cdl_list **top_b);
void		rra_rb_step_calc(t_step_track *st, t_lists_info li);
void		rra_rrb_step_calc(t_step_track *st, t_lists_info li);
void		sort(t_cdl_list **top_a, t_cdl_list **top_b);
void		sort_five_nodes(t_cdl_list **top_a, t_cdl_list **top_b);
void		sort_four_nodes(t_cdl_list **top_a, t_cdl_list **top_b);
void		sort_the_rest(t_cdl_list **top_a, t_cdl_list **top_b);
void		sort_three_nodes_a(t_cdl_list **top_a);
void		sort_two_nodes_a(t_cdl_list **top_a);
void		sort_more_than_five_nodes(t_cdl_list **top_a, t_cdl_list **top_b);
bool		sort_push_ok(t_cdl_list *src, t_cdl_list *dst, t_order order,
				t_lists_info *li);
void		update_total_steps(t_step_track *step_track, t_step_track *target);

/* Miscellaneous ------------------------------------------------------------ */

int			error_msg(void);
int			num(char c);

#endif