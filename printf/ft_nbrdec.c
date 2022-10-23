/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:14:32 by vpolojie          #+#    #+#             */
/*   Updated: 2022/04/05 20:09:13 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"

void	ft_nbrdec(va_list list_arg, size_t *nb_cara)
{
	int	nbr_dec;

	nbr_dec = (int)va_arg(list_arg, int);
	ft_putnbr_fd2(nbr_dec, 1, nb_cara);
}
