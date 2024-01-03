/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:11:50 by Philip            #+#    #+#             */
/*   Updated: 2024/01/03 21:46:34 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if a string represents a number.
   Allows for one '-' or one '+' in front of the digits. */
static bool	is_number(char *s)
{
	if (!s || *s == '\0')
		return (false);
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
		s++;
	return (*s == '\0');
}

/* Checks if the numeric value of a digit string is out of the range of INT. */
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

int	list_has_duplicates(t_cdl_list **top)
{
	t_cdl_list	*node_i;
	t_cdl_list	*node_j;

	if (!top || !(*top))
		return (-1);
	if (list_len(*top) < 2)
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
