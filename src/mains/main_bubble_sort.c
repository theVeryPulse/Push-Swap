/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bubble_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:54:45 by Philip            #+#    #+#             */
/*   Updated: 2023/12/15 19:41:03 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	int			i;
// 	t_cdl_list	*top_a;
// 	t_cdl_list	*top_b;
// 	t_cdl_list	*start_point;

// 	if (is_invalid_input(argc, argv))
// 		return (0);
// 	// ft_printf("%s\n", __FILE__); /* test */
// 	top_a = NULL;
// 	top_b = NULL;
// 	i = 1;
// 	while (i < argc)
// 		list_append(&top_a, ft_atoi(argv[i++]));
// 	// test_print_list(top_a, "A___"); ft_printf("sorted: %d\n", is_sorted(top_a)); /* test */
// 	start_point = top_a;
// 	while (is_sorted(top_a) != 1)
// 	{
// 		if (top_a->next != start_point && top_a->value > top_a->next->value)
// 		{
// 			sa(&top_a);
// 			// test_print_list(top_a, "A___"); ft_printf("sorted: %d\n", is_sorted(top_a)); /* test */
// 		}
// 		ra(&top_a);
// 		// test_print_list(top_a, "A___"); ft_printf("sorted: %d\n", is_sorted(top_a)); /* test */
// 	}
// 	while (top_a != start_point)
// 	{
// 		ra(&top_a);
// 		top_a = top_a->next;
// 	}
// }