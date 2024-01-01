/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_list_operations_0.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:52:05 by Philip            #+#    #+#             */
/*   Updated: 2024/01/01 17:08:38 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	isolate_node(t_cdl_list *node)
{
	if (!node)
		return ;
	node->next = NULL;
	node->prev = NULL;
}

int	list_len(t_cdl_list *top)
{
	int			count;
	t_cdl_list	*node;

	if (top == NULL)
		return (0);
	if (top->next == NULL)
		return (1);
	count = 2;
	node = top->next;
	while (node->next != top)
	{
		node = node->next;
		count++;
	}
	return (count);
}

/* Add a node containing (value) to the bottom/tail of the list. */
void	list_append(t_cdl_list **top, int value)
{
	t_cdl_list	*new_node;
	t_cdl_list	*last_node;

	new_node = (t_cdl_list *)malloc(sizeof(t_cdl_list));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	if (list_len(*top) == 0)
	{
		*top = new_node;
		isolate_node(new_node);
	}
	else
	{
		if ((*top)->prev)
			last_node = (*top)->prev;
		else
			last_node = *top;
		last_node->next = new_node;
		(*top)->prev = new_node;
		new_node->prev = last_node;
		new_node->next = *top;
	}
}

/* Removes and returns the first node of the list.*/
t_cdl_list	*list_pop(t_cdl_list **top)
{
	int			node_count;
	t_cdl_list	*node_to_pop;

	node_to_pop = *top;
	node_count = list_len(*top);
	if (!top || node_count == 0)
		return (NULL);
	else if (node_count == 1)
		*top = NULL;
	else if (node_count == 2)
	{
		*top = (*top)->next;
		isolate_node(*top);
	}
	else
	{
		(*top)->prev->next = (*top)->next;
		(*top)->next->prev = (*top)->prev;
		*top = (*top)->next;
		isolate_node(node_to_pop);
	}
	return (node_to_pop);
}

/* Adds a node to the top/head of the list. */
void	list_push(t_cdl_list **top, t_cdl_list *node_to_push)
{
	int	node_count;

	node_count = list_len(*top);
	if (node_count == 0)
		isolate_node(node_to_push);
	else if (node_count == 1)
	{
		node_to_push->next = *top;
		node_to_push->prev = *top;
		(*top)->next = node_to_push;
		(*top)->prev = node_to_push;
	}
	else
	{
		node_to_push->next = *top;
		node_to_push->prev = (*top)->prev;
		(*top)->prev->next = node_to_push;
		(*top)->prev = node_to_push;
	}
	*top = node_to_push;
}
