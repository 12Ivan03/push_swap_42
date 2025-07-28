/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:26:36 by ipavlov           #+#    #+#             */
/*   Updated: 2025/02/14 14:20:42 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (-1);
	check_argv(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	populate_stack(argc, argv, &stack_a);
	if (is_list_organised(&stack_a) == 1)
	{
		free_stack(stack_a);
		ft_exit();
	}
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
