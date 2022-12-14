/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:53:43 by vpolojie          #+#    #+#             */
/*   Updated: 2022/07/24 18:15:04 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc1(size_t n, size_t size)
{
	unsigned char	*a;
	unsigned long	i;

	i = 0;
	a = (unsigned char *)malloc(n * size);
	if (!(a))
		return (0);
	while (i != (n * size))
	{
		a[i] = 0;
		i++;
	}
	return (a);
}
