/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:40:57 by Philip Li         #+#    #+#             */
/*   Updated: 2024/01/01 17:15:26 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if the list is sorted in ascending order from input node. */
int	is_sorted(t_cdl_list *top)
{
	int			node_count;
	t_cdl_list	*node;

	node_count = list_len(top);
	if (node_count == 0)
		return (-1);
	if (node_count == 1)
		return (1);
	if (node_count == 2)
		return (top->value < top->next->value);
	node = top->next;
	while (node != top)
	{
		if (node->value < node->prev->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_cdl_list	*top_a;
	t_cdl_list	*top_b;

	if (is_invalid_input(argc, argv))
		return (error_msg());
	top_a = NULL;
	top_b = NULL;
	i = 1;
	while (argv[i] != NULL)
		list_append(&top_a, ft_atoi(argv[i++]));
	if (list_has_duplicates(&top_a))
	{
		free_list(&top_a);
		return (error_msg());
	}
	if (!is_sorted(top_a))
		sort(&top_a, &top_b);
	free_list(&top_a);
}
