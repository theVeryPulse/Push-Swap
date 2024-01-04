/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:16:52 by Philip            #+#    #+#             */
/*   Updated: 2024/01/04 18:32:09 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Usage:
   (bash) ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG 

   Press <ctrl d> to exit inputing in terminal. */

static bool	correct_cmds_sorted_stack(t_cdl_list **top_a,
				t_cdl_list **top_b);
static bool	correct_cmd__exec(char *cmd, t_cdl_list **top_a,
				t_cdl_list **top_b);
static void	check_and_exec_cmd(char *cmd, t_cdl_list **top_a,
				t_cdl_list **top_b);
static bool	cmd_correct_check(char *cmd);

int	main(int argc, char **argv)
{
	t_cdl_list	*top_a;
	t_cdl_list	*top_b;
	t_index		i;

	if (argc == 1)
		return (0);
	if (is_invalid_input(argc, argv))
		return (msg(ERROR));
	top_a = NULL;
	top_b = NULL;
	i = 1;
	while (argv[i])
		list_append(&top_a, ft_atoi(argv[i++]));
	if (list_has_duplicates(&top_a))
	{
		list_free(&top_a);
		return (msg(ERROR));
	}
	if (correct_cmds_sorted_stack(&top_a, &top_b))
		msg(OK);
	else
		msg(KO);
	list_free(&top_a);
	list_free(&top_b);
}

static bool	cmd_correct_check(char *cmd)
{
	if (!cmd || *cmd == '\0')
		return (false);
	return ((!ft_strncmp("sa\n", cmd, 5))
		|| (!ft_strncmp("sb\n", cmd, 5))
		|| (!ft_strncmp("ss\n", cmd, 5))
		|| (!ft_strncmp("ra\n", cmd, 5))
		|| (!ft_strncmp("rb\n", cmd, 5))
		|| (!ft_strncmp("rr\n", cmd, 5))
		|| (!ft_strncmp("rra\n", cmd, 5))
		|| (!ft_strncmp("rrb\n", cmd, 5))
		|| (!ft_strncmp("rrr\n", cmd, 5))
		|| (!ft_strncmp("pa\n", cmd, 5))
		|| (!ft_strncmp("pb\n", cmd, 5)));
}

static bool	correct_cmd__exec(char *cmd, t_cdl_list **top_a, t_cdl_list **top_b)
{
	if (!cmd || *cmd == '\0')
		return (false);
	if (!ft_strncmp("sa\n", cmd, 5))
		sa(top_a, NOPRINT);
	else if (!ft_strncmp("sb\n", cmd, 5))
		sb(top_b, NOPRINT);
	else if (!ft_strncmp("ss\n", cmd, 5))
		ss(top_a, top_b, NOPRINT);
	else if (!ft_strncmp("ra\n", cmd, 5))
		ra(top_a, NOPRINT);
	else if (!ft_strncmp("rb\n", cmd, 5))
		rb(top_b, NOPRINT);
	else if (!ft_strncmp("rr\n", cmd, 5))
		rr(top_a, top_b, NOPRINT);
	else if (!ft_strncmp("rra\n", cmd, 5))
		rra(top_a, NOPRINT);
	else if (!ft_strncmp("rrb\n", cmd, 5))
		rrb(top_b, NOPRINT);
	else if (!ft_strncmp("rrr\n", cmd, 5))
		rrr(top_a, top_b, NOPRINT);
	else if (!ft_strncmp("pa\n", cmd, 5))
		pa(top_a, top_b, NOPRINT);
	else if (!ft_strncmp("pb\n", cmd, 5))
		pb(top_a, top_b, NOPRINT);
	return (cmd_correct_check(cmd));
}

static void	check_and_exec_cmd(char *cmd, t_cdl_list **top_a,
			t_cdl_list **top_b)
{
	if (!cmd || *cmd == '\0')
		return ;
	if (correct_cmd__exec(cmd, top_a, top_b))
		return ;
	else
	{
		msg(ERROR);
		list_free(top_a);
		list_free(top_b);
		exit(1);
	}
}

static bool	correct_cmds_sorted_stack(t_cdl_list **top_a, t_cdl_list **top_b)
{
	char	*cmd;

	cmd = get_next_line(STDIN_FILENO);
	if (is_sorted(*top_a) && cmd != NULL)
	{
		msg(KO);
		return (false);
	}
	while (cmd)
	{
		check_and_exec_cmd(cmd, top_a, top_b);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(*top_a) && list_len(*top_b) == 0)
		return (true);
	else
		return (false);
}
