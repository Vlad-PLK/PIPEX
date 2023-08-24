/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:09:29 by vpolojie          #+#    #+#             */
/*   Updated: 2023/08/24 12:06:34 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
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
char	*ft_strjoin_free(char *s1, char *s2);

#endif