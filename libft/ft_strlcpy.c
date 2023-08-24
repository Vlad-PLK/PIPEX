/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:41:53 by vpolojie          #+#    #+#             */
/*   Updated: 2022/03/25 11:56:54 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_len(const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{	
	unsigned int	i;
	unsigned int	y;

	i = 0;
	y = ft_len(src);
	if (!dest || !src)
		return (0);
	if (size > 0)
	{
		while (--size && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (y);
}
/*int	main()
{
	char src[] = "coucou";
	char dest[10]; memset(dest, 'A', 10);
	printf("%zu/n", ft_strlcpy(dest, src, -1));
	printf("%lu", strlcpy(dest, src, -1));
}*/
