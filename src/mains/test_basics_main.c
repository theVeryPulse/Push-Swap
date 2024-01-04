// #include "push_swap.h"

// /* Test  */
// void	test_print_list(t_cdl_list *top, char *message_line)
// {
// 	if (message_line)
// 		ft_putendl_fd(message_line, STDOUT_FILENO);
// 	if (!top)
// 		return ;
// 	int node_count = list_len(top);
// 	for (int i = 0; i < node_count; i++)
// 	{
// 		ft_printf("\t%d\n", top->value);
// 		top = top->next;
// 	}
// }

// /* Test: 2 1 3 6 5 8
//    sa >
//    pb, pb, pb >
//    ra, rb (rr) >
//    rra, rrb (rrr) >
//    sa >
//    pa pa pa*/
// int	main(int argc, char **argv)
// {
// 	char		**str_ary;
// 	int			i;
// 	t_cdl_list	*top_a;
// 	t_cdl_list	*top_b;

// 	if (argc != 2 || is_invalid_input(argv[1]))
// 		return (0);
// 	str_ary = ft_split(argv[1], ' ');
// 	top_a = NULL;
// 	top_b = NULL;
// 	i = 0;
// 	while (str_ary[i] != NULL)
// 		list_append(&top_a, ft_atoi(str_ary[i++]));

// 	test_print_list(top_a, "A___"); ft_printf("sorted: %d\n", is_sorted(top_a));
// 	test_print_list(top_b, "B___");

// 	/* sa */
// 	sa(&top_a);
// 	test_print_list(top_a, "A___"); ft_printf("sorted: %d\n", is_sorted(top_a));
// 	test_print_list(top_b, "B___");

// 	/* pb, pb, pb */
// 	for (i = 0; i < 3; i++)
// 		pb(&top_a, &top_b);
// 	test_print_list(top_a, "A___"); ft_printf("sorted: %d\n", is_sorted(top_a));
// 	test_print_list(top_b, "B___");

// 	/* ra, rb (rr) */
// 	// ra(&top_a); rb(&top_b);
// 	rr(&top_a, &top_b);
// 	test_print_list(top_a, "A___"); ft_printf("sorted: %d\n", is_sorted(top_a));
// 	test_print_list(top_b, "B___");

// 	/* rra, rrb (rrr) */
// 	// rra(&top_a); rrb(&top_b);
// 	rrr(&top_a, &top_b);
// 	test_print_list(top_a, "A___"); ft_printf("sorted: %d\n", is_sorted(top_a));
// 	test_print_list(top_b, "B___");

// 	/* sa */
// 	sa(&top_a);
// 	test_print_list(top_a, "A___"); ft_printf("sorted: %d\n", is_sorted(top_a));
// 	test_print_list(top_b, "B___");

// 	for (i = 0; i < 3; i++)
// 		pa(&top_a, &top_b);
// 	test_print_list(top_a, "A___"); ft_printf("sorted: %d\n", is_sorted(top_a));
// 	test_print_list(top_b, "B___");
// }