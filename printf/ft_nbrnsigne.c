/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrnsigne.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:19:41 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/25 11:42:01 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	ft_nbrnsigne(va_list list_arg, size_t *nb_cara)
{
	unsigned int	nbr_nsigne;

	nbr_nsigne = (unsigned int)va_arg(list_arg, unsigned int);
	ft_putnbru(nbr_nsigne, 1, nb_cara);
}
