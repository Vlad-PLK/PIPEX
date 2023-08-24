/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:00:41 by vpolojie          #+#    #+#             */
/*   Updated: 2023/08/24 12:06:30 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
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
	int		j;
	char	*path;
	char	**options;
	int		tmp_fd;
	int		out_fd;
	int		tab[2];
}t_data;

char	*ft_envp_path(char **envp);
char	*ft_find_path(char *arg, char *arg2, char **envp);
void	ft_close_redir(t_data *data, int argc);
char	*ft_strjoin_free(char *s1, char *s2);

#endif