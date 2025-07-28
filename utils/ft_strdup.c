/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penchoivanov <penchoivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:45:59 by ipavlov           #+#    #+#             */
/*   Updated: 2024/12/20 10:58:51 by penchoivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/push_swap.h"

char	*ft_strdup(const char *s)
{
	int			lenstr;
	size_t		i;
	char		*cpy_str;

	lenstr = ft_strlen(s);
	cpy_str = (char *)malloc(lenstr + 1 * sizeof(char));
	if (cpy_str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		cpy_str[i] = s[i];
		i++;
	}
	cpy_str[i] = '\0';
	return (cpy_str);
}
