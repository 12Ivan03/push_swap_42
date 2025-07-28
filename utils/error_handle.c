/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penchoivanov <penchoivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:57:09 by ipavlov           #+#    #+#             */
/*   Updated: 2025/02/12 13:43:59 by penchoivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_exit(void)
{
	exit(1);
}

void	ft_error(void)
{
	ft_putendl_fd("Error", 1);
	ft_exit();
}

void	free_stack(t_node *stack)
{
	t_node	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next_node;
		free(temp);
	}
}
