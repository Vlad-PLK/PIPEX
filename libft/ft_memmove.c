/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:20:03 by vpolojie          #+#    #+#             */
/*   Updated: 2022/03/26 12:48:30 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (!ptr && !ptr2)
		return (0);
	if (ptr2 < ptr)
		while (++i <= n)
			ptr[n - i] = ptr2[n - i];
	else
		while (n-- > 0)
			*(ptr++) = *(ptr2++);
	return (dest);
}
/*int	main()
{
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	printf("%s\n", ft_memmove(sResult +1, sResult, 2));
	printf("%s\n", memmove(sResult +1, sResult, 2));
}*/
