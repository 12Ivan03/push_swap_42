/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack_src.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:06:06 by ipavlov           #+#    #+#             */
/*   Updated: 2025/01/14 13:23:12 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*create_t_node(int value, int j)
{
	t_node	*new_t_node;

	new_t_node = (t_node *)malloc(sizeof(t_node));
	if (new_t_node == NULL)
		return (NULL);
	new_t_node->x = value;
	new_t_node->index = j;
	new_t_node->next_node = NULL;
	return (new_t_node);
}

void	add_t_node_back(t_node *temp_t_node, t_node **stack_a)
{
	t_node	*current_t_node;

	if (*stack_a == NULL)
	{
		*stack_a = temp_t_node;
		return ;
	}
	else
		current_t_node = *stack_a;
	while (current_t_node->next_node != NULL)
	{
		current_t_node = current_t_node->next_node;
	}
	current_t_node->next_node = temp_t_node;
}

int	len_t_node(t_node **stack)
{
	int		i;
	t_node	*temp_stack;

	temp_stack = *stack;
	i = 1;
	while (temp_stack->next_node != NULL)
	{
		temp_stack = temp_stack->next_node;
		i++;
	}
	return (i);
}
