/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:27:20 by ipavlov           #+#    #+#             */
/*   Updated: 2025/01/13 18:24:00 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*return_penultimate_t_node(t_node **stack)
{
	t_node	*extract_t_node;

	extract_t_node = *stack;
	while (extract_t_node->next_node->next_node != NULL)
		extract_t_node = extract_t_node->next_node;
	return (extract_t_node);
}

void	reverse_rotate(t_node **stack)
{
	t_node	*penultimate_t_node;
	t_node	*last_t_node;

	if (*stack == NULL || (*stack)->next_node == NULL)
		ft_exit();
	if ((*stack)->next_node->next_node == NULL)
	{
		swap(stack);
		return ;
	}
	penultimate_t_node = return_penultimate_t_node(stack);
	last_t_node = penultimate_t_node->next_node;
	penultimate_t_node->next_node = NULL;
	last_t_node->next_node = *stack;
	*stack = last_t_node;
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
