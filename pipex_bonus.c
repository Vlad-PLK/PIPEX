/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 07:51:11 by vpolojie          #+#    #+#             */
/*   Updated: 2023/02/24 13:14:45 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
#include "pipex_bonus.h"

void	ft_create_pipetab(t_data *data, int argc)
{
	if (argc < 5)
	{
		ft_printf("INCORRECT NUMBER OF ARGUMENTS\n");
		exit(EXIT_FAILURE);
	}
	data->nb_pipes = ((argc - 3) - 1);
	data->i = data->nb_pipes;
	data->j = 0;
	data->pipe_index = 2;
	data->j = 3;
}

void	ft_pipex_bonus_end(t_data *data, int status)
{
	int	i;

	close(data->tab[0]);
	close(data->tab[1]);
	close(data->tmp_fd);
	i = 0;
	while (i != data->nb_pipes + 1)
	{
		wait(&status);
		i++;
	}
}

void	ft_exec_processe(t_data *data, char **argv, char **envp)
{
	data->options = ft_split(argv[data->j], ' ');
	dup2(data->tab[1], STDOUT_FILENO);
	dup2(data->tmp_fd, STDIN_FILENO);
	close(data->tab[0]);
	data->path = ft_find_path(data->options[0], argv[data->j], envp);
	if (data->path == NULL)
	{
		write(2, "command", 9);
		ft_putnbr_fd(data->j -1, 2);
		write(2, " not found\n", 11);
		exit(EXIT_FAILURE);
	}
	execve(data->path, data->options, envp);
	perror("execve parent");
}

void	ft_loop_processes(t_data *data, int argc, char **argv, char **envp)
{
	if (data->j == (argc -2))
	{
		data->j++;
		ft_last_process(argv, envp, data, argc);
	}
	else if (data->j != (argc -2))
		ft_exec_processe(data, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		status;
	pid_t	pid;
	pid_t	pid2;
	t_data	data;

	ft_create_pipetab(&data, argc);
	if (pipe(data.tab) == -1)
		perror("pipe error\n");
	pid = fork();
	if (pid == -1)
		perror("fork error");
	else if (pid == 0)
		ft_first_process(argv, envp, &data);
	waitpid(pid, &status, 0);
	close(data.tab[1]);
	data.tmp_fd = data.tab[0];
	while (data.j != argc -1)
	{
		if (pipe(data.tab) == -1)
			perror("pipe error\n");
		pid2 = fork();
		if (pid2 == -1)
			perror("fork error");
		else if (pid2 == 0)
			ft_loop_processes(&data, argc, argv, envp);
		else
		{
			waitpid(pid2, &status, 0);
			close(data.tab[1]);
			dup2(data.tab[0], data.tmp_fd);
			close(data.tab[0]);
			data.j++;
		}
	}
	close(data.tmp_fd);
	close(data.out_fd);
}
