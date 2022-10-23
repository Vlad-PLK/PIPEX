/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:25:54 by vpolojie          #+#    #+#             */
/*   Updated: 2022/03/24 12:33:44 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*ft_memset(void *s, int c, size_t n)
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
/*int	main()
{
	char s1[50] = "vlad";
	char s2[50] = "VLAD";

	printf("%s\n", memset(s1, 'z', 2*sizeof(char)));
	printf("%s", ft_memset(s2, 'z', 2*sizeof(char)));
}*/
