/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:37:03 by ipavlov           #+#    #+#             */
/*   Updated: 2025/02/14 10:20:37 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	asign_index(int *arr, t_node **stack_a, int t_node_length)
{
	t_node	*temp;
	int		i;

	temp = *stack_a;
	i = 0;
	while (temp != NULL)
	{
		while (i < t_node_length)
		{
			if (temp->x == arr[i])
				temp->index = i;
			i++;
		}
		i = 0;
		temp = temp->next_node;
	}
}

int	max_num(t_node **stack_a)
{
	t_node	*temp_a;
	int		max_index;

	temp_a = *stack_a;
	max_index = temp_a->index;
	while (temp_a != NULL)
	{
		if (temp_a->index > max_index)
			max_index = temp_a->index;
		temp_a = temp_a->next_node;
	}
	return (max_index);
}

int	ft_max_bit(int num)
{
	int	max_bit;

	max_bit = 0;
	while (num > 0)
	{
		num = num >> 1;
		max_bit++;
	}
	return (max_bit);
}

void	ft_redix(t_node **stack_a, t_node **stack_b, int t_node_length)
{
	int		num;
	int		max_bit;
	int		i;
	int		k;

	num = max_num(stack_a);
	max_bit = ft_max_bit(num);
	k = 0;
	while (k < max_bit)
	{
		i = 0;
		while (i < t_node_length)
		{
			if ((((*stack_a)->index >> k) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			i++;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		k++;
	}
}

void	ft_redix_sort(t_node **stack_a, t_node **stack_b, int t_node_length)
{
	int	*arr;

	arr = create_sort_arr(stack_a, t_node_length);
	asign_index(arr, stack_a, t_node_length);
	ft_redix(stack_a, stack_b, t_node_length);
	free(arr);
}
