/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:04:33 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/05 21:35:15 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
#include "pipex.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_pipex_end(int pid, int pid2, t_data *data)
{
	close(data->pipetab[0]);
	close(data->pipetab[1]);
	waitpid(pid, &data->status, 0);
	waitpid(pid2, &data->status, 0);
}
