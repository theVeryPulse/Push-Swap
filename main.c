/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:40:57 by Philip Li         #+#    #+#             */
/*   Updated: 2023/12/30 17:15:55 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if the list is sorted and the minimal value is at the top. */
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

/* Allows for one '-' or one '+' in front of the digits. */
bool	is_number(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
		s++;
	return (*s == '\0');
}

int	is_beyond_int(char *s)
{
	long long	val;
	long long	sign;
	size_t		i;

	if (!s)
		return (-1);
	sign = 1;
	i = 0;
	if (s[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	val = 0;
	while (i < ft_strlen(s) && ft_isdigit(s[i]))
	{
		val = val * 10 + num(s[i++]);
		if (val >= 10 * (long long)INT_MAX)
			return (1);
	}
	val *= sign;
	if (val > (long long)INT_MAX || val < (long long)INT_MIN)
		return (1);
	return (0);
}

/* An argument is invalid when
   1) it contains any non-digit character excpet '+' and '-';
   2) it is out of int range; 
   
   If an argument's string length is longer than 11 (-2147483647), skips
   examining its numeric value. */
bool	is_invalid_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_number(argv[i]) == false
			|| ft_strlen(argv[i]) > 11
			|| is_beyond_int(argv[i]))
			return (true);
		i++;
	}
	return (false);
}

int	input_has_duplicates(t_cdl_list **top)
{
	t_cdl_list	*node_i;
	t_cdl_list	*node_j;

	if (!top || !(*top))
		return (-1);
	if (get_node_count(*top) < 2)
		return (0);
	node_i = (*top);
	while (node_i->next != (*top))
	{
		node_j = node_i->next;
		while (node_j != (*top))
		{
			if (node_i->value == node_j->value)
				return (1);
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	return (0);
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
	if (input_has_duplicates(&top_a))
	{
		free_list(&top_a);
		return (error_msg());
	}
	if (!is_sorted(top_a))
		sort(&top_a, &top_b);
	free_list(&top_a);
}
