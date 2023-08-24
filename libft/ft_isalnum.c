/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:04:48 by vpolojie          #+#    #+#             */
/*   Updated: 2022/05/28 21:01:44 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isalpha_2(int c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_isdigit_2(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	else
		return (0);
}	

int	ft_isalnum(int c)
{
	if ((ft_isalpha_2(c) == 1 || ft_isdigit_2(c) == 1))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
