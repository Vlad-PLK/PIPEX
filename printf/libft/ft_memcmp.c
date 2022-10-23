/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:48:07 by vpolojie          #+#    #+#             */
/*   Updated: 2022/03/25 10:39:54 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a1;
	const unsigned char	*a2;
	int					i;

	a1 = (const unsigned char *)s1;
	a2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if ((a1[i] - a2[i]) != 0)
			return (a1[i] - a2[i]);
		i++;
		n--;
	}
	if ((a1[i] == '\0') && (a2[i] != '\0'))
		return (a1[i] - a2[i]);
	else if ((a1[i] != '\0') && (a2[i] == '\0'))
		return ((a1[i] - a2[i]));
	return (0);
}
/*int	main()
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127,0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	printf("%d\n", ft_memcmp(s, s2, 0));
	printf("%d\n", memcmp(s, s2, 0));
}*/
