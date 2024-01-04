/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_shaker_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:54:45 by Philip            #+#    #+#             */
/*   Updated: 2024/01/04 16:33:37 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// static void	compare_and_swap(t_cdl_list *top_a)
// {
// 	if (top_a->value > top_a->next->value)
// 		sa(&top_a, PRINT);
// }

// int	main(int argc, char **argv)
// {
// 	int			i;
// 	t_cdl_list	*top_a;
// 	t_cdl_list	*top_b;
// 	t_cdl_list	*start_point;

// 	if (is_invalid_input(argc, argv))
// 		return (0);
// 	top_a = NULL;
// 	i = 1;
// 	while (i < argc)
// 		list_append(&top_a, ft_atoi(argv[i++]));
// 	start_point = top_a;

// 	/* Shaker sort */
// 	int	r_sorted = argc - 3; // argc offset 1, index offst 1, compare offset 1
// 	int	l_sorted = 0;
// 	i = l_sorted;
// 	while (r_sorted > l_sorted)
// 	{
// 		while (i <= r_sorted)
// 		{
// 			i++;
// 			if (top_a->value > top_a->next->value)
// 				sa(&top_a, PRINT);
// 			if (is_sorted(start_point))
// 				break ;
// 			ra(&top_a);
// 		}
// 		if (is_sorted(start_point))
// 			break ;
// 		r_sorted--;
// 		i--;
// 		rra(&top_a);
// 		while (i >= l_sorted)
// 		{
// 			i--;
// 			if (top_a->value > top_a->next->value)
// 				sa(&top_a, PRINT);
// 			if (is_sorted(start_point))
// 				break ;
// 			rra(&top_a);
// 		}
// 		if (is_sorted(start_point))
// 			break ;
// 		l_sorted++;
// 		i++;
// 		ra(&top_a);
// 	}
// 	while (top_a != start_point)
// 		ra(&top_a);
// }
	// 5 4 3 2 1 | argc: 6 | index: 0 1 2 3 4 | right sort to index: 3
/*  i: 0, 1, 2, 3,  r_sorted--:2;   sorted: <-----> 4
    i: 2, 1, 0,     l_sorted++:1;   sorted: 0 <---> 4
    i: 1, 2,        r_sorted--:2;   sorted: 0 <-> 3 4
    i: 1,l          l_sorted++:2;   sorted: 0 1 2 3 4
 */