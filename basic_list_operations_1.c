/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_list_operations_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:31:20 by Philip            #+#    #+#             */
/*   Updated: 2023/12/29 17:31:34 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_cdl_list **top)
{
	t_cdl_list	*node;

	if(!top || !(*top))
		return ;
	if (get_node_count(*top) == 1)
		free(*top);
	else
	{
		node = (*top)->next;
		while (node && node->next != *top)
		{
			free(node->prev);
			node = node->next;
		}
		free(node->prev);
		free(node);
	}
	*top = NULL;
}