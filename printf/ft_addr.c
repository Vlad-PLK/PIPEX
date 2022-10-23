/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:09:04 by vpolojie          #+#    #+#             */
/*   Updated: 2022/04/05 20:46:18 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"

void	ft_addr(va_list list_arg, size_t *nb_cara)
{
	unsigned long	addr;

	addr = (unsigned long)va_arg(list_arg, unsigned long);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	if ((void *)addr == NULL)
	{
		ft_putchar_fd('0', 1);
		(*nb_cara)++;
	}
	(*nb_cara) = ft_base16ul(addr, *nb_cara) + 2;
}
