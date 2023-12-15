/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:42:38 by Philip Li         #+#    #+#             */
/*   Updated: 2023/12/15 00:42:38 by Philip Li        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

/* Circular doubly linked list */
typedef struct s_cbl_list
{
	int					value;
	struct s_cbl_list	*prev;
	struct s_cbl_list	*next;
}	t_cbl_list;

/* List operations */
void		list_append(t_cbl_list **top, int value);
t_cbl_list	*list_pop(t_cbl_list **top);
void		list_push(t_cbl_list **top, t_cbl_list *node_to_push);
int			get_node_count(t_cbl_list *top);
void		isolate_node(t_cbl_list *node);

/* Designated operations */
void		sa(t_cbl_list **top_a);
void		sb(t_cbl_list **top_b);
void		ss(t_cbl_list **top_a, t_cbl_list **top_b);
void		pa(t_cbl_list **top_a, t_cbl_list **top_b);
void		pb(t_cbl_list **top_a, t_cbl_list **top_b);
void		ra(t_cbl_list **top_a);
void		rb(t_cbl_list **top_b);
void		rr(t_cbl_list **top_a, t_cbl_list **top_b);
void		rra(t_cbl_list **top_a);
void		rrb(t_cbl_list **top_b);
void		rrr(t_cbl_list **top_a, t_cbl_list **top_b);

#endif