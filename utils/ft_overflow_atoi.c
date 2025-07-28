/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overflow_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:24:24 by ipavlov           #+#    #+#             */
/*   Updated: 2025/01/05 12:10:35 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_overflow(long num, int neg, int *overflow)
{
	if (num > 2147483647 && neg == 1)
	{
		*overflow = 1;
		return (1);
	}
	if (num > 2147483648 && neg == -1)
	{
		*overflow = 1;
		return (1);
	}
	return (0);
}

long	ft_overflow_atoi(const char *nptr, int *overflow)
{
	long	i;
	int		neg;
	long	num;

	num = 0;
	neg = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0');
		if (check_overflow(num, neg, overflow))
			return (0);
		i++;
	}
	return (neg * num);
}
