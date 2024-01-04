/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_insertion_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:11:37 by Philip            #+#    #+#             */
/*   Updated: 2023/12/18 02:01:06 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	int			i;
// 	t_cdl_list	*top_a;
// 	t_cdl_list	*top_b;
// 	t_cdl_list	*first_node;

// 	if (is_invalid_input(argc, argv))
// 		return (0);
// 	top_a = NULL;
// 	top_b = NULL;
// 	i = 1;
// 	while (i < argc)
// 		list_append(&top_a, ft_atoi(argv[i++]));

// 	/* Insertion sort */
// 	first_node = top_a;
// 	ra(&top_a);
// 	while (top_a != first_node && is_sorted(top_a) == false)
// 	{
// 		if (top_a->prev->value > top_a->value)
// 		{
// 			pb(&top_a, &top_b);
// 			rra(&top_a);
// 			while (top_a->value > top_b->value && top_a != first_node)
// 			{
// 				if (top_b->value > top_a->prev->value && top_b->value < top_a->value)
// 				{
// 					pa(&top_a, &top_b);
// 					break ;
// 				}
// 				rra(&top_a);
// 			}
// 			if (top_a == first_node)
// 			{
// 				pa(&top_a, &top_b);
// 				first_node = top_a;
// 			}
// 		}
// 		ra(&top_a);
// 	}

// 	while (top_a != first_node)
// 		ra(&top_a);
// }

