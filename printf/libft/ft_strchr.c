/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:03:32 by vpolojie          #+#    #+#             */
/*   Updated: 2022/03/25 11:18:15 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;
	char			*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0' || c == '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			return (&str[i]);
		}
		else
			i++;
	}
	return (0);
}
/*int	main()
{
	char s[] = "tripouille";
	printf("%s\n", ft_strchr(s, 't' + 256));
	printf("%s", strchr(s, 't' + 256));
}*/
