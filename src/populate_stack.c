/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penchoivanov <penchoivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:51:31 by ipavlov           #+#    #+#             */
/*   Updated: 2025/02/12 13:52:54 by penchoivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_populate_stack(t_node **stack_a, char **temp_argv, int argc)
{
	free_stack(*stack_a);
	*stack_a = NULL;
	if (argc == 2)
		ft_arr_free(temp_argv);
	ft_error();
}

void	populate_stack(int argc, char *argv[], t_node **stack_a)
{
	t_node	*new_t_node;
	char	**temp_argv;
	int		i;
	int		j;

	i = 0;
	if (!split_or_pass_argv(argc, argv, &temp_argv, &i))
		ft_error();
	j = 1;
	while (temp_argv[i] != NULL)
	{
		new_t_node = create_t_node(ft_atoi(temp_argv[i]), j);
		if (new_t_node == NULL)
			free_populate_stack(stack_a, temp_argv, argc);
		add_t_node_back(new_t_node, stack_a);
		i++;
		j++;
	}
	if (argc == 2)
		ft_arr_free(temp_argv);
}
