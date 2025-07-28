/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penchoivanov <penchoivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:22:55 by ipavlov           #+#    #+#             */
/*   Updated: 2025/01/16 19:09:56 by penchoivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_small_position(t_node **stack_b, int next_small_num)
{
	t_node	*temp_b;
	int		position;

	temp_b = *stack_b;
	position = 1;
	while (temp_b)
	{
		if (temp_b->x == next_small_num)
			return (position);
		temp_b = temp_b->next_node;
		position++;
	}
	return (0);
}

int	which_half(t_node **stack_b, int index_next_num)
{
	int	len_stack_b;

	len_stack_b = len_t_node(stack_b);
	if (len_stack_b / 2 >= index_next_num)
		return (0);
	else
		return (1);
}

void	extract_num(t_node **stack_b, int index_next_num, int next_small_num)
{
	int	which_way;

	which_way = which_half(stack_b, index_next_num);
	if (which_way == 0)
	{
		while ((*stack_b)->x != next_small_num)
			rb(stack_b);
	}
	else
	{
		while ((*stack_b)->x != next_small_num)
			rrb(stack_b);
	}
}

void	ft_quick_sort(t_node **stack_a, t_node **stack_b, int t_node_length)
{
	int	next_small_num;
	int	index_next_num;

	prepare_quick_sort(stack_a, stack_b, t_node_length);
	while (*stack_b != NULL)
	{
		next_small_num = find_max_num(stack_b);
		index_next_num = find_small_position(stack_b, next_small_num);
		extract_num(stack_b, index_next_num, next_small_num);
		pa(stack_a, stack_b);
	}
}
