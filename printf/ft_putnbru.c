/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:04:22 by vpolojie          #+#    #+#             */
/*   Updated: 2022/04/05 20:10:44 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft/libft.h"

void	ft_putnbru(unsigned int nb, int fd, size_t *nb_cara)
{
	if (0 <= nb && nb <= 9)
	{
		ft_putchar_fd(nb + '0', fd);
		(*nb_cara)++;
	}
	else
	{
		ft_putnbru(nb / 10, fd, nb_cara);
		ft_putnbru(nb % 10, fd, nb_cara);
	}
}
