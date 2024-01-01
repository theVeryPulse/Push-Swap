/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_merge_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:46:02 by Philip            #+#    #+#             */
/*   Updated: 2024/01/01 17:08:36 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Only sorts numbers of 2's powers. 2, 4,...128, etc. */

/* To be called when top_a is at the start of two sorted parts that awaits
   merging. */
void	merge(t_cdl_list **top_a, int len_a, t_cdl_list **top_b, int len_b)
{
	t_index	a_i;
	t_index	b_i;

	b_i = 0;
	while (b_i < len_b)
	{
		pb(top_a, top_b);
		b_i++;
	}
	rrb(top_b);
	a_i = 0;
	b_i = 0;
	while (a_i < len_a || b_i < len_b)
	{
		if (a_i >= len_a)
		{
			pa(top_a, top_b);
			b_i++;
			rrb(top_b);
			ra(top_a);
		}
		else if (b_i >= len_b)
		{
			ra(top_a);
			a_i++;
		}
		else if ((*top_a)->value < (*top_b)->value)
		{
			ra(top_a);
			a_i++;
		}
		else
		{
			pa(top_a, top_b);
			b_i++;
			rrb(top_b);
			ra(top_a);
		}
	}
}

void	merge_sort(t_cdl_list **top_a, t_cdl_list **top_b, int len)
{
	t_index	i;
	int		merge_counter;
	int		merge_size;

	/* Initial sort of size 2 using only swaps */
	i = 0;
	while (i + 1 < len)
	{
		if ((*top_a)->value > (*top_a)->next->value)
			sa(top_a);
		ra(top_a);
		ra(top_a);
		i += 2;
	}
	if (i == len - 1)
		ra(top_a);

	merge_size = 2;
	while ((2 * merge_size) <= len)
	{
		merge_counter = 0;
		while (merge_counter < len / (2 * merge_size))
		{
			merge(top_a, merge_size, top_b, merge_size);
			merge_counter++;
		}
		if (merge_counter * (2 * merge_size) != len) /* Bug */
			merge(top_a, merge_size, top_b, len - (2 * merge_size) * merge_counter - merge_size); /* Bug */
		merge_size *= 2;
	}
	if ((2 * merge_size) != len) /* Bug */
			merge(top_a, merge_size, top_b, len - (2 * merge_size) * merge_counter - merge_size); /* Bug */
}

int	main(int argc, char **argv)
{
	int			i;
	t_cdl_list	*top_a;
	t_cdl_list	*top_b;

	if (is_invalid_input(argc, argv))
		return (0);
	top_a = NULL;
	top_b = NULL;
	i = 1;
	while (argv[i] != NULL)
		list_append(&top_a, ft_atoi(argv[i++]));


	/* Hybrid sort */
	/* Experiment: 32 numbers */
	int size = list_len(top_a);
	merge_sort(&top_a, &top_b, size);

}


