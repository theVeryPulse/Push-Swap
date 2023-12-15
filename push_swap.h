/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:42:38 by Philip Li         #+#    #+#             */
/*   Updated: 2023/12/15 17:41:17 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

/* Circular doubly linked list */
typedef struct s_cdl_list
{
	int					value;
	struct s_cdl_list	*prev;
	struct s_cdl_list	*next;
}	t_cdl_list;

/* List operations */
void		list_append(t_cdl_list **top, int value);
t_cdl_list	*list_pop(t_cdl_list **top);
void		list_push(t_cdl_list **top, t_cdl_list *node_to_push);
int			get_node_count(t_cdl_list *top);
void		isolate_node(t_cdl_list *node);

/* Designated operations */
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

/* Miscellaneous */
bool		is_sign(char c);
bool		is_invalid_input(int argc, char **argv);
int			is_sorted(t_cdl_list *top);

/* Test */
void		test_print_list(t_cdl_list *top, char *message_line);

#endif