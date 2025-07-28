/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penchoivanov <penchoivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:26:19 by ipavlov           #+#    #+#             */
/*   Updated: 2025/01/14 23:27:38 by penchoivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_list_organised(t_node **stack)
{
	t_node	*temp_stack;

	temp_stack = *stack;
	while (temp_stack != NULL && temp_stack->next_node != NULL)
	{
		if (temp_stack->x > temp_stack->next_node->x)
			return (0);
		temp_stack = temp_stack->next_node;
	}
	return (1);
}

int	find_min_num(t_node **stack)
{
	t_node	*temp_stack;
	int		index;
	int		min_value;

	index = (*stack)->index;
	min_value = (*stack)->x;
	temp_stack = *stack;
	while (temp_stack != NULL)
	{
		if (temp_stack->x < min_value)
		{
			min_value = temp_stack->x;
			index = temp_stack->index;
		}
		temp_stack = temp_stack->next_node;
	}
	return (index);
}

void	move_min_num_b(t_node **stack_a, t_node **stack_b)
{
	int	min_num;

	min_num = find_min_num(stack_a);
	if (min_num == 1)
		pb(stack_a, stack_b);
	else if (min_num == 2)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (min_num >= 3)
	{
		while ((*stack_a)->index != min_num)
		{
			rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
}

void	sort_index(t_node **stack_a)
{
	t_node	*temp_stack;
	int		i;

	temp_stack = *stack_a;
	i = 1;
	while (temp_stack != NULL)
	{
		temp_stack->index = i;
		temp_stack = temp_stack->next_node;
		i++;
	}
}

int	find_max_num(t_node **stack)
{
	t_node	*temp_stack;
	int		max_value;

	max_value = (*stack)->x;
	temp_stack = *stack;
	while (temp_stack != NULL)
	{
		if (temp_stack->x > max_value)
			max_value = temp_stack->x;
		temp_stack = temp_stack->next_node;
	}
	return (max_value);
}
