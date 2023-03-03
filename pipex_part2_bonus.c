/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_part2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:42:25 by vpolojie          #+#    #+#             */
/*   Updated: 2023/02/24 12:25:44 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
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

void	ft_first_process(char **argv, char **envp, t_data *data)
{
	data->options = ft_split(argv[2], ' ');
	data->tmp_fd = open(argv[1], O_RDONLY);
	if (data->tmp_fd == -1)
	{
		perror("open first process");
		exit(EXIT_FAILURE);
	}
	dup2(data->tmp_fd, STDIN_FILENO);
	dup2(data->tab[1], STDOUT_FILENO);
	close(data->tab[0]);
	data->path = ft_find_path(data->options[0], argv[2], envp);
	if (data->path == NULL)
	{
		write(2, "command 1 not found\n", 20);
		exit(EXIT_FAILURE);
	}
	execve(data->path, data->options, envp);
	perror("execve first child");
}

void	ft_last_process(char **argv, char **envp, t_data *data, int argc)
{
	data->options = ft_split(argv[argc - 2], ' ');
	data->out_fd = open(argv[argc -1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data->out_fd == -1)
	{
		perror("open last process");
		exit(EXIT_FAILURE);
	}
	dup2(data->out_fd, STDOUT_FILENO);
	dup2(data->tmp_fd, STDIN_FILENO);
	close(data->tab[0]);
	close(data->tab[1]);
	data->path = ft_find_path(data->options[0], argv[argc - 2], envp);
	if (data->path == NULL)
	{
		write(2, "last command not found\n", 23);
		exit(EXIT_FAILURE);
	}
	execve(data->path, data->options, envp);
	perror("execve parent");
}
