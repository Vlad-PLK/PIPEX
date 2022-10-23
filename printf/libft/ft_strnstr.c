/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:12:32 by vpolojie          #+#    #+#             */
/*   Updated: 2022/03/25 12:24:15 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	if (*little == '\0' || little == 0 || big == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < n)
	{
		if (big[i] == little[0])
		{	
			j = 0;
			while (little[j] && big[i + j] && i + j < n
				&& big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
/*int	main()
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char * empty = (char*)"";

	printf("%s\n", ft_strnstr(haystack, "abcd", 9));
	printf("%s", strnstr(haystack, "abcd", 9));

}*/
