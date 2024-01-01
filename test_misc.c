/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:51:13 by Philip            #+#    #+#             */
/*   Updated: 2024/01/01 17:08:36 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_print_list(t_cdl_list *top, char *message_line)
{
	int	node_count;
	int	i;

	if (message_line)
		ft_putendl_fd(message_line, STDOUT_FILENO);
	if (!top)
		return ;
	node_count = list_len(top);
	i = 0;
	while (i < node_count)
	{
		ft_printf("\t%d\n", top->value);
		top = top->next;
		i++;
	}
}
