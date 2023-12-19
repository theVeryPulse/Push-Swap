/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_iterative_merge_sort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:03:34 by Philip            #+#    #+#             */
/*   Updated: 2023/12/19 19:00:49 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* len_a should be  */
void	merge(t_cdl_list **top_a, int len_a, t_cdl_list **top_b, int len_b)
{
	int	i;
	int	a_i;
	int	b_i;

	i = 0;
	a_i = 0;
	b_i = 0;
	while (i < len_a + len_b)
	{
		if (a_i >= len_a)
		{
			// sorted[i++] = r_half[b_i++];
			/* All nodes from a is merged, take nodes from b */
			
		}
		else if (b_i >= len_b)
		{
			// sorted[i++] = l_half[a_i++];
			/* All nodes from b is merged, take nodes from a */

		}
		else if (l_half[a_i] <= r_half[b_i])
		{

			// sorted[i++] = l_half[a_i++];
		}
		else
		{
			
			// sorted[i++] = r_half[b_i++];
		}
	}
}