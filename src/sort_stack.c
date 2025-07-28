/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penchoivanov <penchoivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:26:31 by ipavlov           #+#    #+#             */
/*   Updated: 2025/01/14 23:47:44 by penchoivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	t_node_length;

	t_node_length = len_t_node(stack_a);
	if (stack_a == NULL)
		ft_error();
	else if ((*stack_a)->next_node == NULL)
		ft_exit();
	if (t_node_length == 2)
		ft_sort_small_two(stack_a);
	else if (t_node_length == 3)
		ft_sort_small_three(stack_a);
	else if (t_node_length == 4)
		ft_sort_small_four(stack_a, stack_b);
	else if (t_node_length == 5)
		ft_sort_small_five(stack_a, stack_b);
	else if (t_node_length <= 100)
		ft_quick_sort(stack_a, stack_b, t_node_length);
	else if (t_node_length >= 101)
		ft_redix_sort(stack_a, stack_b, t_node_length);
}
