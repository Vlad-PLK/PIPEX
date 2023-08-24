/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:37:04 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/25 11:43:41 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_atoi_part2(long int str0, int m)
{
	if (str0 > 2147483647 || str0 < -2147483646)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (m == 1)
		str0 = str0 * -1;
	return (str0);
}

int	ft_atoi(const char *str)
{
	int				i;
	long int		str0;
	int				m;

	str0 = 0;
	i = 0;
	m = 0;
	while ((0 <= str[i]) && (str[i] <= 32))
		i++;
	if ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i] == 45)
			m = 1;
		i++;
	}
	if ((str[i] == 45) || (str[i] == 43))
		return (str0);
	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		str0 = str0 * 10 + (str[i] - 48);
		i++;
	}
	return (ft_atoi_part2(str0, m));
}
