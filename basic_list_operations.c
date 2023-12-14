#include "push_swap.h"

void	isolate_node(t_cbl_list *node)
{
	if (!node)
		return ;
	node->next = NULL;
	node->prev = NULL;
}

int	get_node_count(t_cbl_list *top)
{
	int			count;
	t_cbl_list	*node;

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
void	list_append(t_cbl_list **top, int value)
{
	t_cbl_list	*new_node;
	t_cbl_list	*last_node;

	new_node = (t_cbl_list *)malloc(sizeof(t_cbl_list));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	if (get_node_count(*top) == 0)
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
t_cbl_list	*list_pop(t_cbl_list **top)
{
	t_cbl_list	*node_to_pop;

	node_to_pop = *top;
	if (!top || get_node_count(*top) == 0)
		return (NULL);
	else if (get_node_count(*top) == 1)
		*top = NULL;
	else if (get_node_count(*top) == 2)
	{
		*top = (*top)->next;
		isolate_node(*top);
	}
	else
	{
		(*top)->prev->next = (*top)->next;
		(*top)->next->prev = (*top)->prev;
		isolate_node(node_to_pop);
		*top = (*top)->next;
	}
	return (node_to_pop);
}
// 0, 1, 2, 3, 4, ...
/* Adds a node to the top/head of the list. */
void	list_push(t_cbl_list **top, t_cbl_list *node_to_push)
{
	if (get_node_count(*top) == 0)
		isolate_node(node_to_push);
	else if (get_node_count(*top) == 1)
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
