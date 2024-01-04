/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:32:04 by Philip            #+#    #+#             */
/*   Updated: 2024/01/04 17:44:31 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	msg(t_msg msg)
{
	if (msg == OK)
		write(STDOUT_FILENO, "OK\n", 3);
	else if (msg == KO)
		write(STDOUT_FILENO, "KO\n", 3);
	else if (msg == ERROR)
		write(STDERR_FILENO, "Error\n", 6);
	return (0);
}

/* Returns the numeric value of a character between '0' and '9'. */
int	num(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else
		return (0);
}
