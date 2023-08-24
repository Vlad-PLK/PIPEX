/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:53:38 by vpolojie          #+#    #+#             */
/*   Updated: 2022/03/28 12:50:30 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	while (i != start)
		i++;
	j = 0;
	if (start + len > (unsigned int)ft_strlen(s))
		len = (unsigned int)ft_strlen(s) - start;
	if ((unsigned int)ft_strlen(s) < start)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc((len +1) * sizeof(char));
	while (len--)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
/*int	main()
{
	char *s = ft_substr("tripouille", 0, 42000);
	printf("%s", s);
}*/
