/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penchoivanov <penchoivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:53:00 by ipavlov           #+#    #+#             */
/*   Updated: 2025/02/12 14:07:57 by penchoivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid(char *temp_argv, char **entire_argv, int i)
{
	if (!ft_all_num(temp_argv))
		return (0);
	if (!ft_is_overflow(temp_argv))
		return (0);
	if (!ft_is_duplicate(temp_argv, entire_argv, i))
		return (0);
	return (1);
}

void	check_argv(int argc, char *argv[])
{
	char	**temp_argv;
	int		i;

	i = 0;
	if (!split_or_pass_argv(argc, argv, &temp_argv, &i))
		ft_error();
	while (temp_argv[i] != NULL)
	{
		if (!is_valid(temp_argv[i], temp_argv, i))
		{
			if (argc == 2)
				ft_arr_free(temp_argv);
			ft_error();
		}
		i++;
	}
	if (argc == 2)
		ft_arr_free(temp_argv);
}
