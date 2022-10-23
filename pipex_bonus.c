/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 07:51:11 by vpolojie          #+#    #+#             */
/*   Updated: 2022/10/23 15:32:00 by vpolojie         ###   ########.fr       */
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

void	ft_first_process(char **argv, char **envp, t_data *data, int *pipetab)
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
	dup2(pipetab[1], STDOUT_FILENO);
	close(fd_in);
	close(pipetab[0]);
	data->path = ft_find_path(data->options[0], argv[2], envp);
	if (data->path == NULL)
	{
		write(2, "command not found\n", 18);
		exit(EXIT_FAILURE);
	}
	dprintf(2, "first process executed\n");
	execve(data->path, data->options, envp);
	perror("execve child");
}

void	ft_last_process(char **argv, char **envp, t_data *data, int *pipetab, int argc, int k)
{
	int		fd_exit;
	int		i;

	i = 0;
	data->options = ft_split(argv[argc - 2], ' ');
	fd_exit = open(argv[argc -1], O_CREAT | O_WRONLY);
	if (fd_exit == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(fd_exit, STDOUT_FILENO);
	dup2(pipetab[k - 2], STDIN_FILENO);
	close(fd_exit);
	while (i != k - 1)
	{
		close(pipetab[i]);
		i++;
	}
	data->path = ft_find_path(data->options[0], argv[argc - 2], envp);
	if (data->path == NULL)
	{
		write(2, "command not found\n", 18);
		exit(EXIT_FAILURE);
	}
	dprintf(2, "last process executed\n");
	execve(data->path, data->options, envp);
	perror("execve parent");
}

int	main(int argc, char **argv, char **envp)
{
	int		nb_pipes;
	int		*pipetab;
	int		i;
	int		j;
	int		pipe_index;
	int		status;
	pid_t	pid;
	pid_t	pid2;
	t_data	data;

	// creating all needed pipes//
	// nb_pipes = argc - ./pipex - file1 - file2 - 1 to have all needed pipes
	nb_pipes = ((argc - 3) - 1);
	i = nb_pipes;
	j = 0;
	pipetab = (int *)malloc(sizeof(int) * (nb_pipes * 2));
	while (i != 0)
	{
		if (pipe(pipetab + j) == -1)
			perror("pipe error");
		j += 2;
		i--;
	}
	// first fork with the first process
	pid = fork();
	if (pid == -1)
		perror("fork error");
	else if (pid == 0)
		ft_first_process(argv, envp, &data, pipetab);
	else if (pid > 0)
	{
		// main while loop with all children
		pipe_index = 2;
		j = 3;
		while (j != argc -1)
		{
			pid2 = fork();
			if (pid2 == -1)
				perror("fork error");
			else if (pid2 == 0)
			{
				if (j == (argc -2))
				{
					ft_last_process(argv, envp, &data, pipetab, argc, pipe_index);
					break ;
				}
				else if (j != (argc -2))
				{

					data.options = ft_split(argv[j], ' ');
					dup2(pipetab[pipe_index - 2], STDIN_FILENO);
					dup2(pipetab[pipe_index + 1], STDOUT_FILENO);
					close(pipetab[pipe_index -2]);
					close(pipetab[pipe_index +1]);
					i = 0;
					while (i != (pipe_index +1))
					{
						close(pipetab[i]);
						i++;
					}
					data.path = ft_find_path(data.options[0], argv[j], envp);
					if (data.path == NULL)
					{
						write(2, "command not found\n", 18);
						exit(EXIT_FAILURE);
					}
					dprintf(2, "%d process executed\n", j);
					execve(data.path, data.options, envp);
					perror("execve parent");
				}
			}
			i = 0;
			while (i != (pipe_index +1))
			{
				close(pipetab[i]);
				i++;
			}
			waitpid(pid, &status, 0);
			waitpid(pid2, &status, 0);
			j++;
			pipe_index = pipe_index + 2;
		}
		waitpid(pid, &status, 0);
		waitpid(pid2, &status, 0);
	}
	return (0);
}
