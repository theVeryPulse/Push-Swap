/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_merge_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:46:02 by Philip            #+#    #+#             */
/*   Updated: 2024/01/03 17:48:54 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef enum e_merge_onto
{
	A,
	B
}	t_merge_onto;

/* Only sorts numbers of 2's powers. 2, 4,...128, etc. */

/* To be called when top_a is at the start of two sorted parts that awaits
   merging. */
void	merge(t_merge_onto onto, t_cdl_list **top_a, int len_a,
		t_cdl_list **top_b, int len_b)
{
	t_index	a_i;
	t_index	b_i;

	a_i = 0;
	b_i = 0;
	if (onto == A) // Bottom half from A, Top half from B
	{
		while (a_i < len_a || b_i < len_b)
		{
			if (a_i >= len_a) // A side empty, next value from b
			{
				pa(top_a, top_b);
				b_i++;
				// ra(top_a);
			}
			else if (b_i >= len_b) // B side empty, next value from a
			{
				rra(top_a);
				a_i++;
			}
			else if ((*top_a)->prev->value > (*top_b)->value) // Choose A
			{
				rra(top_a);
				a_i++;
			}
			else // Choose B
			{
				pa(top_a, top_b);
				b_i++;
			}
		}
	}
	else // B in descending order
	{
		while (a_i < len_a || b_i < len_b)
		{
			if (a_i >= len_a) // A side empty, next value from b
			{
				rrb(top_b);
				b_i++;
			}
			else if (b_i >= len_b) // B side empty, next value from a
			{
				pb(top_a, top_b);
				a_i++;
			}
			else if ((*top_a)->value > (*top_b)->value) // Choose A
			{
				pb(top_a, top_b);
				a_i++;
			}
			else // Choose B
			{
				rb(top_b);
				b_i++;
			}
		}
	}
}

void	merge_sort(t_cdl_list **top_a, t_cdl_list **top_b, int len)
{
	t_index	i;
	int		merge_counter;
	int		merge_size;

	/* Initial sort of size 2 using both lists */
	i = 0;
	pb_n_times(top_a, top_b, len / 2);
	while (i + 1 < len / 2)
	{
		bool needs_sa = (*top_a)->value > (*top_a)->next->value;
		bool needs_sb = (*top_b)->value < (*top_b)->next->value;
		if (needs_sa && needs_sb)
			ss(top_a, top_b);
		else if (needs_sa && !needs_sb)
			sa(top_a);
		else if (!needs_sa && needs_sb)
			sb(top_b);
		rr(top_a, top_b);
		rr(top_a, top_b);
		i += 2;
	}
	// if (i == len - 1)
	// 	ra(top_a);

	merge_size = 2;
	
	merge(A, top_a, merge_size, top_b, merge_size);
	rra(top_a);
	rra(top_a);
	merge(B, top_a, merge_size, top_b, merge_size);

	


	// while ((2 * merge_size) <= len)
	// {
	// 	merge_counter = 0;
	// 	while (merge_counter < len / (2 * merge_size))
	// 	{
	// 		merge(A, top_a, merge_size, top_b, merge_size);
	// 		merge(B, top_a, merge_size, top_b, merge_size);
	// 		merge_counter++;
		// }
		// if (merge_counter * (2 * merge_size) != len) /* Bug */
		// 	merge(top_a, merge_size, top_b, len - (2 * merge_size) * merge_counter - merge_size); /* Bug */
		// merge_size *= 2;
	// }
	// if ((2 * merge_size) != len) /* Bug */
	// 		merge(top_a, merge_size, top_b, len - (2 * merge_size) * merge_counter - merge_size); /* Bug */
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
	if (list_has_duplicates(&top_a))
	{
		free_list(&top_a);
		return (error_msg());
	}
	if (!is_sorted(top_a))
	{
		/* Experiment: 32 numbers */
		int size = list_len(top_a);
		merge_sort(&top_a, &top_b, size);
	}
	free_list(&top_a);
}


