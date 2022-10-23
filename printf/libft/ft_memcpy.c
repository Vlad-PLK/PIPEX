/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:07:54 by vpolojie          #+#    #+#             */
/*   Updated: 2022/03/23 18:05:23 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*a;
	const char	*b;

	a = dest;
	b = src;
	while (n != 0)
	{
		*a = *b;
		a++;
		b++;
		n--;
	}
	return (dest);
}
