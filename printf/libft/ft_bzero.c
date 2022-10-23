/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:57:49 by vpolojie          #+#    #+#             */
/*   Updated: 2022/05/28 21:02:11 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*ft_memset_2(void *s, int c, size_t n)
{
	unsigned char	*a;

	a = s;
	while (n != 0)
	{
		*a = (unsigned char)c;
		a++;
		n--;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset_2(s, 0, n);
}
