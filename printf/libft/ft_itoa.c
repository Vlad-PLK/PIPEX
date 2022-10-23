/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:42:03 by vpolojie          #+#    #+#             */
/*   Updated: 2022/04/05 11:32:27 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_nbn(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	ft_putnbr(int nb, int *i, char *str)
{
	if (nb == -2147483648)
	{
		str[0] = '-';
		(*i)++;
		ft_putnbr(21474, i, str);
		ft_putnbr(83648, i, str);
	}
	else if (0 <= nb && nb <= 9)
		str[(*i)++] = nb + '0';
	else if (nb < 0)
	{
		str[0] = '-';
		(*i)++;
		ft_putnbr(nb *(-1), i, str);
	}
	else
	{
		ft_putnbr(nb / 10, i, str);
		ft_putnbr(nb % 10, i, str);
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	if (n < 0)
		str = malloc((ft_nbn(n) + 2) * sizeof(char));
	else
		str = malloc((ft_nbn(n) + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	ft_putnbr(n, &i, str);
	str[i] = '\0';
	return (str);
}
/*int	main()
{
	printf("%s", ft_itoa(42));
}*/
