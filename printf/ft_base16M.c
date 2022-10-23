/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base16M.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:25:44 by vpolojie          #+#    #+#             */
/*   Updated: 2022/04/05 20:06:35 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>

size_t	ft_base16m(unsigned int nbr, size_t nb_cara)
{
	int		reste[100];
	int		i;
	char	*base;

	base = "0123456789ABCDEF";
	i = 0;
	if (nbr < 0)
	{
		nbr = (unsigned int)nbr;
		ft_base16(nbr, nb_cara);
	}
	while (nbr > 0)
	{
		reste[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
	{
		write(1, &base[reste[i]], 1);
		nb_cara++;
	}
	return (nb_cara);
}
