/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:39:40 by vpolojie          #+#    #+#             */
/*   Updated: 2022/04/05 11:47:42 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (d > size)
		d = size;
	if (d == size || size == 0)
		return (s + d);
	if (s < size - d)
	{
		ft_memcpy(dst + d, src, s + 1);
	}
	else
	{
		ft_memcpy(dst + d, src, size - d - 1);
		dst[size -1] = '\0';
	}
	return (d + s);
}

/*int	main()
{
	char dest[30]; memset(dest, 0, 30);
	char * src = (char *)"AAAAAAAAA";
	dest[0] = 'B';
	printf("%zu\n", ft_strlcat(dest, src, 6));
	printf("%lu\n", strlcat(dest, src, 6));
}*/
