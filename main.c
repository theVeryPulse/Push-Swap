/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:40:57 by Philip Li         #+#    #+#             */
/*   Updated: 2023/12/14 00:40:57 by Philip Li        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_invalid_input(char* s)
{
	while (ft_isdigit(*s))
	{
		s++;
		if (*s == ' ' && ft_isdigit(*(s + 1)))
			s++;
	}
	return (*s != '\0');
}

// #include <stdio.h>
void	list_append(t_cbl_list **top, int number)
{
	t_cbl_list	*new_node;
	t_cbl_list	*this_node;

	new_node = (t_cbl_list *)malloc(sizeof(t_cbl_list));
	if (new_node == NULL)
		return ;
	new_node->number = number;
	if (*top == NULL)
	{
		*top = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else if ((*top)->prev == NULL && (*top)->next == NULL)
	{
		(*top)->next = new_node;
		(*top)->prev = new_node;
		new_node->next = *top;
		new_node->prev = *top;
	}
	else
	{
		(*top)->prev->next = new_node;
		new_node->prev = (*top)->prev;
		new_node->next = *top;
		(*top)->prev = new_node;
	}
}

int	main(int argc, char **argv)
{
	char		**str_ary;
	int			i;
	t_cbl_list	*top;

	if (argc != 2)
		return (0);
	if (is_invalid_input(argv[1]))
		return (0);
	str_ary = ft_split(argv[1], ' ');
	top = NULL;
	i = 0;
	while (str_ary[i] != NULL)
	{
		// printf("%d\n", ft_atoi(str_ary[i++]));
		list_append(&top, ft_itoa(str_ary[i++]));
	}
	
}
