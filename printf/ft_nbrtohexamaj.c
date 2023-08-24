/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtohexamaj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:27:02 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/25 11:42:13 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	ft_nbrtohexamaj(va_list list_arg, size_t *nb_cara)
{
	int	nbr_to_hexa;

	nbr_to_hexa = (int)va_arg(list_arg, int);
	if (nbr_to_hexa == 0)
	{
		ft_putchar_fd('0', 1);
		(*nb_cara)++;
	}
	(*nb_cara) = ft_base16m(nbr_to_hexa, *nb_cara);
}
