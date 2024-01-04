/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:32:04 by Philip            #+#    #+#             */
/*   Updated: 2023/12/29 17:33:05 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_msg(void)
{
	ft_putendl_fd("Error", STDOUT_FILENO);
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
