/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:26:25 by ipavlov           #+#    #+#             */
/*   Updated: 2025/02/14 14:19:47 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_small_two(t_node **stack_a)
{
	if (is_list_organised(stack_a))
		return ;
	else
		sa(stack_a);
}

void	ft_one_two_three(t_node **stack_a, int first, int second, int third)
{
	if (first < second && second < third && first < third)
		return ;
	if (first < second && first < third)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (first > second && second > third)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (first > second && first < third)
		sa(stack_a);
	else if (first > second && first > third)
		ra(stack_a);
	else if (first < second && first > third)
		rra(stack_a);
}

void	ft_sort_small_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->x;
	second = (*stack_a)->next_node->x;
	third = (*stack_a)->next_node->next_node->x;
	ft_one_two_three(stack_a, first, second, third);
}

void	ft_sort_small_four(t_node **stack_a, t_node **stack_b)
{
	move_min_num_b(stack_a, stack_b);
	ft_sort_small_three(stack_a);
	pa(stack_a, stack_b);
}

void	ft_sort_small_five(t_node **stack_a, t_node **stack_b)
{
	move_min_num_b(stack_a, stack_b);
	sort_index(stack_a);
	move_min_num_b(stack_a, stack_b);
	ft_sort_small_three(stack_a);
	if ((*stack_b)->x < (*stack_b)->next_node->x)
		sa(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
