/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:52:41 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/25 11:41:41 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	ft_char(va_list list_arg, size_t *nb_cara)
{
	char	lettre;

	lettre = (char)va_arg(list_arg, int);
	write(1, &lettre, 1);
	(*nb_cara)++;
}
