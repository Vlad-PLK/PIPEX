/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:47:17 by vpolojie          #+#    #+#             */
/*   Updated: 2022/04/05 20:55:32 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_check_type(va_list list_arg, char c, size_t nb_cara);
size_t	ft_base16(unsigned int nbr, size_t nb_cara);
size_t	ft_base16ul(unsigned long nbr, size_t nb_cara);
size_t	ft_base16m(unsigned int nbr, size_t nb_cara);
void	ft_char(va_list list_arg, size_t *nb_cara);
void	ft_string(va_list list_arg, size_t *nb_cara);
void	ft_addr(va_list list_arg, size_t *nb_cara);
void	ft_nbrdec(va_list list_arg, size_t *nb_cara);
void	ft_nbrnsigne(va_list list_arg, size_t *nb_cara);
void	ft_nbrtohexa(va_list list_arg, size_t *nb_cara);
void	ft_nbrtohexamaj(va_list list_arg, size_t *nb_cara);
void	ft_putnbru(unsigned int nb, int fd, size_t *nb_cara);
void	ft_putnbr_fd2(int nbr_dec, int fd, size_t *nb_cara);

#endif
