/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:21:46 by vpolojie          #+#    #+#             */
/*   Updated: 2022/04/05 20:08:54 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

size_t	ft_check_type(va_list list_arg, char c, size_t nb_cara)
{
	if (c == 'c')
		ft_char(list_arg, &nb_cara);
	else if (c == 's')
		ft_string(list_arg, &nb_cara);
	else if (c == 'p')
		ft_addr(list_arg, &nb_cara);
	else if (c == 'd' || c == 'i')
		ft_nbrdec(list_arg, &nb_cara);
	else if (c == 'u')
		ft_nbrnsigne(list_arg, &nb_cara);
	else if (c == 'x')
		ft_nbrtohexa(list_arg, &nb_cara);
	else if (c == 'X')
		ft_nbrtohexamaj(list_arg, &nb_cara);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		nb_cara += 1;
	}
	return (nb_cara);
}
