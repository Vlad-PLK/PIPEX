/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:10 by vpolojie          #+#    #+#             */
/*   Updated: 2022/04/05 20:28:46 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	list_arg;
	size_t	nb_cara;

	va_start(list_arg, format);
	i = 0;
	nb_cara = 0;
	while (format[i] != '\0')
	{	
		nb_cara++;
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		if (format[i] == '%')
		{
			i++;
			nb_cara--;
			nb_cara = ft_check_type(list_arg, format[i], nb_cara);
		}
		i++;
	}
	return (nb_cara);
}
