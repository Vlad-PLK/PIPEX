/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_part2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:42:25 by vpolojie          #+#    #+#             */
/*   Updated: 2022/10/24 10:48:00 by vpolojie         ###   ########.fr       */
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
	int		fd_in;

	data->options = ft_split(argv[2], ' ');
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(fd_in, STDIN_FILENO);
	dup2(data->pipetab[1], STDOUT_FILENO);
	close(fd_in);
	close(data->pipetab[0]);
	data->path = ft_find_path(data->options[0], argv[2], envp);
	if (data->path == NULL)
	{
		write(2, "command not found\n", 18);
		exit(EXIT_FAILURE);
	}
	execve(data->path, data->options, envp);
	perror("execve child");
}

void	ft_close_pipes(t_data *data)
{
	data->i = 0;
	while (data->i != (data->nb_pipes * 2))
	{
		close(data->pipetab[data->i]);
		data->i++;
	}
}

void	ft_last_process(char **argv, char **envp, t_data *data, int argc)
{
	int		fd_exit;

	data->options = ft_split(argv[argc - 2], ' ');
	fd_exit = open(argv[argc -1], O_CREAT | O_WRONLY | O_TRUNC);
	if (fd_exit == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(fd_exit, STDOUT_FILENO);
	dup2(data->pipetab[data->pipe_index - 2], STDIN_FILENO);
	close(fd_exit);
	ft_close_pipes(data);
	data->path = ft_find_path(data->options[0], argv[argc - 2], envp);
	if (data->path == NULL)
	{
		write(2, "command not found\n", 18);
		exit(EXIT_FAILURE);
	}
	execve(data->path, data->options, envp);
	perror("execve parent");
}
