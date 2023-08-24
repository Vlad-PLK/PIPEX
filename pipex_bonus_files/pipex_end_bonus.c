/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_end_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:42:25 by vpolojie          #+#    #+#             */
/*   Updated: 2023/08/24 12:05:52 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include "../libft/libft.h"
#include "pipex_bonus.h"

char	*ft_envp_path(char **envp)
{
	char	*envp_path;
	int		i;

	i = 0;
	while (envp[i])
	{
		envp_path = ft_strnstr(envp[i], "PATH=", 5);
		if (envp_path)
			break ;
		i++;
	}
	envp_path = ft_substr(envp_path, 5, ft_strlen(envp_path));
	return (envp_path);
}

char	*ft_find_path(char *arg, char *arg2, char **envp)
{
	int		i;
	char	*envp_path;
	char	**all_paths;

	envp_path = ft_envp_path(envp);
	all_paths = ft_split(envp_path, ':');
	free(envp_path);
	i = 0;
	if (ft_strncmp((const char *)arg2, "/bin", ft_strlen(arg2)) == 0)
		return (NULL);
	if (ft_strncmp((const char *)arg2, "/bin/", ft_strlen(arg2)) == 0)
		return (NULL);
	if (access(arg2, F_OK | X_OK) == 0)
		return (arg2);
	while (all_paths[i])
	{
		all_paths[i] = ft_strjoin_free(all_paths[i], "/");
		all_paths[i] = ft_strjoin_free(all_paths[i], arg);
		if (access(all_paths[i], F_OK | X_OK) == 0)
			return (all_paths[i]);
		free(all_paths[i]);
		i++;
	}
	free(all_paths);
	return (NULL);
}

void	ft_close_redir(t_data *data, int argc)
{
	close(data->tmp_fd);
	if (data->j != argc - 1)
	{
		data->tmp_fd = dup(data->tab[0]);
		close(data->tab[0]);
		close(data->tab[1]);
	}
	else
		close(data->out_fd);
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
