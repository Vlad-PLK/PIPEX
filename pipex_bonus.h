/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:00:41 by vpolojie          #+#    #+#             */
/*   Updated: 2022/10/24 10:44:33 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
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
	int		i;
	int		j;
	int		pipe_index;
	int		nb_pipes;
	int		*pipetab;
	char	*path;
	char	**options;
}t_data;

char	*ft_envp_path(char **envp);
char	*ft_find_path(char *arg, char *arg2, char **envp);
void	ft_first_process(char **argv, char **envp, t_data *data);
void	ft_close_pipes(t_data *data);
void	ft_last_process(char **argv, char **envp, t_data *data, int argc);

#endif