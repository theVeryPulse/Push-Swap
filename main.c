/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:40:57 by Philip Li         #+#    #+#             */
/*   Updated: 2023/12/22 12:10:36 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_cdl_list *top)
{
	int			node_count;
	t_cdl_list	*node;

	node_count = get_node_count(top);
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

bool	is_number(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
		s++;
	return (*s == '\0');
}

/* Argument is invalid when
   1) there is only one number argument;
   2) any of the argument is not a number; */
bool	is_invalid_input(int argc, char **argv)
{
	int	i;

	if (argc <= 2)
		return (true);
	i = 1;
	while (i < argc)
	{
		if (is_number(argv[i]) == false)
			return (true);
		i++;
	}
	return (false);
}

/* int	main(int argc, char **argv)
{
	int			i;
	t_cdl_list	*top_a;
	t_cdl_list	*top_b;

	if (is_invalid_input(argc, argv))
		return (0);
	top_a = NULL;
	top_b = NULL;
	i = 1;
	while (str_ary[i] != NULL)
		list_append(&top_a, ft_atoi(str_ary[i++]));
} 
*/