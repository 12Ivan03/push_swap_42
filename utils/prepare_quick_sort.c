/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_quick_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penchoivanov <penchoivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:29:24 by ipavlov           #+#    #+#             */
/*   Updated: 2025/02/12 14:26:12 by penchoivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_arr(int *array, int t_node_length)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < t_node_length - 1)
	{
		while (j < t_node_length - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	*create_sort_arr(t_node **stack_a, int t_node_length)
{
	int		i;
	int		*array;
	t_node	*temp;

	temp = *stack_a;
	array = (int *)malloc(t_node_length * sizeof(int));
	if (array == NULL)
	{
		free_stack(*stack_a);
		*stack_a = NULL;
		ft_error();
	}
	i = 0;
	while (temp != NULL)
	{
		array[i] = temp->x;
		temp = temp->next_node;
		i++;
	}
	sort_arr(array, t_node_length);
	return (array);
}

int	choose_pivot(int t_node_length)
{
	int	pivot;

	pivot = 0;
	if (t_node_length >= 31 && t_node_length <= 100)
		pivot = t_node_length / 4;
	else
		pivot = t_node_length / 2;
	return (pivot);
}

void	start_sort(t_node **stack_a, t_node **stack_b, int pivot_num)
{
	t_node	*temp_list;
	int		i;
	int		initial_length;

	initial_length = len_t_node(stack_a);
	i = 0;
	while (i < initial_length)
	{
		temp_list = *stack_a;
		if (temp_list->x <= pivot_num)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

void	prepare_quick_sort(t_node **stack_a, \
				t_node **stack_b, int t_node_length)
{
	int	*arr;
	int	pivot_num;
	int	pivot_point;
	int	remaining_length;
	int	moveing_pivot_point;

	arr = create_sort_arr(stack_a, t_node_length);
	remaining_length = t_node_length;
	moveing_pivot_point = 0;
	while (remaining_length > 5)
	{
		pivot_point = choose_pivot(remaining_length);
		moveing_pivot_point += pivot_point;
		pivot_num = arr[moveing_pivot_point];
		start_sort(stack_a, stack_b, pivot_num);
		remaining_length -= pivot_point;
	}
	sort_stack(stack_a, stack_b);
	free(arr);
}
