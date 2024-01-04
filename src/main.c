/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:40:57 by Philip Li         #+#    #+#             */
/*   Updated: 2024/01/04 15:08:48 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_cdl_list	*top_a;
	t_cdl_list	*top_b;

	if (is_invalid_input(argc, argv))
		return (msg(ERROR));
	top_a = NULL;
	top_b = NULL;
	i = 1;
	while (argv[i] != NULL)
		list_append(&top_a, ft_atoi(argv[i++]));
	if (list_has_duplicates(&top_a))
	{
		free_list(&top_a);
		return (msg(ERROR));
	}
	if (!is_sorted(top_a))
		sort(&top_a, &top_b);
	free_list(&top_a);
}
