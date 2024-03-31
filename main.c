/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:20:49 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/31 22:31:01 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%ld ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

void	try(t_stack **b)
{
	rrb(b, SINGLE_OP);
	ft_print_stack(*b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		error_msg();
	else
		a = parse_args(argc, argv);
	check_duplicates(a);
	if (check_sorted(a) == 0)
	{
		if (stack_size(a) == 2)
			sa(a, SINGLE_OP);
		else if (stack_size(a) == 3)
			sort_3(&a);
		else
			sort(&a, &b);
		// {
		// 	while (stack_size(a) > 3)
		// 		pb(&a, &b);
		// 	ft_print_stack(a);
		// 	ft_print_stack(b);
		// 	try(&b);
		// 	ft_printf("after try\n");
		// 	ft_print_stack(b);
		// }
	}
}
