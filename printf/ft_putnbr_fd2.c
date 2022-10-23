/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:15:14 by vpolojie          #+#    #+#             */
/*   Updated: 2022/04/05 20:10:34 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft/libft.h"

void	ft_putnbr_fd2(int nb, int fd, size_t *nb_cara)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd2(21474, fd, nb_cara);
		ft_putnbr_fd2(83648, fd, nb_cara);
		(*nb_cara)++;
	}
	else if (0 <= nb && nb <= 9)
	{
		ft_putchar_fd(nb + '0', fd);
		(*nb_cara)++;
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd2(nb * (-1), fd, nb_cara);
		(*nb_cara)++;
	}
	else
	{
		ft_putnbr_fd2(nb / 10, fd, nb_cara);
		ft_putnbr_fd2(nb % 10, fd, nb_cara);
	}
}
