/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtohexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:23:07 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/25 11:42:06 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	ft_nbrtohexa(va_list list_arg, size_t *nb_cara)
{
	int	nbr_to_hexa;

	nbr_to_hexa = (int)va_arg(list_arg, int);
	if (nbr_to_hexa == 0)
	{
		ft_putchar_fd('0', 1);
		(*nb_cara)++;
	}
	(*nb_cara) = ft_base16(nbr_to_hexa, *nb_cara);
}
