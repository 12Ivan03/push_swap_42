/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_src.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penchoivanov <penchoivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:03:56 by ipavlov           #+#    #+#             */
/*   Updated: 2025/02/12 13:59:33 by penchoivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	split_or_pass_argv(int argc, char **argv, char ***temp_argv, int *i)
{
	if (argc == 2)
	{
		*temp_argv = ft_split(argv[1], ' ');
		if (*temp_argv == NULL || *temp_argv[0] == NULL)
		{
			ft_arr_free(*temp_argv);
			return (0);
		}
	}
	else
	{
		*temp_argv = argv;
		*i = 1;
	}
	return (1);
}

int	ft_all_num(char *temp_argv)
{
	int	i;

	if (temp_argv[0] == '\0')
		return (0);
	i = 0;
	if (temp_argv[0] == '-')
		i = 1;
	while (temp_argv[i])
	{
		if (!ft_isnum(temp_argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_overflow(char *temp_argv)
{
	long	temp;
	int		overflow;

	overflow = 0;
	temp = ft_overflow_atoi(temp_argv, &overflow);
	if (temp == 0 && overflow == 1)
		return (0);
	return (1);
}

int	ft_is_duplicate(char *temp_argv, char **entire_argv, int i)
{
	int		j;
	int		overflow;
	long	current_num;
	long	compare_num;

	overflow = 0;
	current_num = ft_overflow_atoi(temp_argv, &overflow);
	j = i + 1;
	while (entire_argv[j] != NULL)
	{
		compare_num = ft_overflow_atoi(entire_argv[j], &overflow);
		if (overflow >= 1)
			return (0);
		if (current_num == compare_num)
			return (0);
		j++;
	}
	return (1);
}

void	ft_arr_free(char **temp_argv)
{
	int	i;

	i = 0;
	while (temp_argv[i] != NULL)
	{
		free(temp_argv[i]);
		i++;
	}
	free(temp_argv);
	temp_argv = NULL;
}
