/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:04:33 by vpolojie          #+#    #+#             */
/*   Updated: 2023/08/24 12:05:54 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../printf/ft_printf.h"
#include "../libft/libft.h"
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

char	*ft_strjoin_free(char *s1, char *s2)
{	
	char			*str;
	int				i;
	int				k;

	k = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		str[i] = s2[k];
		k++;
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
