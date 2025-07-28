/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:27:08 by ipavlov           #+#    #+#             */
/*   Updated: 2025/01/13 18:24:00 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_node **stack_one, t_node **stack_two)
{
	t_node	*temp_holder;

	if (*stack_one == NULL)
		ft_exit();
	temp_holder = *stack_one;
	*stack_one = (*stack_one)->next_node;
	temp_holder->next_node = *stack_two;
	*stack_two = temp_holder;
}

void	pa(t_node **stack_a, t_node **stack_b) // top->b to top->a
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_node **stack_a, t_node **stack_b) // top->a to top->b
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
