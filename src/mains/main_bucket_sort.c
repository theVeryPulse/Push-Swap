/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bucket_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:59:05 by Philip            #+#    #+#             */
/*   Updated: 2023/12/18 02:01:22 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// int	get_range(char **argv,int argc)
// {
// 	int	i;
// 	int	max;
// 	int	min;
// 	int	this_num;
// 	int	num_count;

// 	num_count = argc - 1;
// 	ft_printf("num_count: (%d)\n", num_count);
// 	if (num_count <= 19)
// 		return (0);
// 	i = 1;
// 	this_num = ft_atoi(argv[i++]);
// 	max = this_num;
// 	min = this_num;
// 	while (i < argc - 1)
// 	{
// 		this_num = ft_atoi(argv[i++]);
// 		if (max < this_num)
// 			max = this_num;
// 		if (min > this_num)
// 			min = this_num;
// 	}
// 	return ((max - min) / num_count + 1);
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


// 	int range = get_range(argv, argc);
// 	ft_printf("(%d)\n", range);
// }
