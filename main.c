/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:40:57 by Philip Li         #+#    #+#             */
/*   Updated: 2023/12/14 18:30:42 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sign(char c)
{
	return (c == '-' || c== '+');
}

bool	is_invalid_input(char* s)
{
	if (is_sign(*s))
		s++;
	while (ft_isdigit(*s))
	{
		s++;
		if (ft_isspace(*s) && (ft_isdigit(*(s + 1)) || is_sign(*(s + 1))))
			s++;
		if (is_sign(*s))
			s++;
	}
	return (*s != '\0');
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	char		**str_ary;
	int			i;
	t_cbl_list	*top_a;
	t_cbl_list	*top_b;
	t_cbl_list	*node;

	if (argc != 2 || is_invalid_input(argv[1]))
		return (0);
	str_ary = ft_split(argv[1], ' ');
	top_a = NULL;
	i = 0;
	while (str_ary[i] != NULL)
		list_append(&top_a, ft_atoi(str_ary[i++]));
	node = top_a;	
	while (node->next != top_a)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
	printf("%d\n", node->value);
	printf("Total nodes: %d\n", get_node_count(top_a));
}
