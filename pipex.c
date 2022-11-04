/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:19:33 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/04 11:13:41 by vpolojie         ###   ########.fr       */
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

void	ft_child_process(char **argv, char **envp, t_data *data)
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

void	ft_parent_process(char **argv, char **envp, t_data *data)
{
	int		fd_exit;

	data->options = ft_split(argv[3], ' ');
	fd_exit = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_exit == -1)
	{
		perror("open2");
		exit(EXIT_FAILURE);
	}
	dup2(fd_exit, STDOUT_FILENO);
	dup2(data->pipetab[0], STDIN_FILENO);
	close(fd_exit);
	close(data->pipetab[1]);
	data->path = ft_find_path(data->options[0], argv[3], envp);
	if (data->path == NULL)
	{
		write(2, "command not found\n", 18);
		exit(EXIT_FAILURE);
	}
	execve(data->path, data->options, envp);
	perror("execve parent");
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	pid_t	pid2;
	t_data	data;

	if (argc == 5)
	{
		if (pipe(data.pipetab) == -1)
			perror("pipe");
		pid = fork();
		if (pid == -1)
			perror("first fork");
		else if (pid == 0)
			ft_child_process(argv, envp, &data);
		else if (pid > 0)
		{
			pid2 = fork();
			if (pid2 == -1)
				perror("second fork");
			else if (pid2 == 0)
				ft_parent_process(argv, envp, &data);
			ft_pipex_end(pid, pid2, &data);
		}
	}
	else
		ft_printf("INCORRECT NUMBER OF ARGUMENTS MUST BE 4\n");
}
