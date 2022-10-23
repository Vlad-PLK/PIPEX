/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:09:29 by vpolojie          #+#    #+#             */
/*   Updated: 2022/10/18 13:54:12 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include "printf/ft_printf.h"
# include "printf/libft/libft.h"
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_data
{
	int		pipetab[2];
	int		status;
	char	*path;
	char	**options;
}t_data;

void	ft_pipex_end(int pid, int pid2, t_data *data);

#endif