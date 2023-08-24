/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 07:51:11 by vpolojie          #+#    #+#             */
/*   Updated: 2023/08/24 12:05:53 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include "../libft/libft.h"
#include "pipex_bonus.h"

void	ft_create_data(t_data *data, int argc)
{
	if (argc < 5)
	{
		ft_printf("INCORRECT NUMBER OF ARGUMENTS\n");
		exit(EXIT_FAILURE);
	}
	data->j = 2;
}

void	ft_infile(t_data *data, char **argv)
{
	data->tmp_fd = open(argv[1], O_RDONLY);
	if (data->tmp_fd == -1)
	{
		perror("wrong infile\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_outfile(t_data *data, int argc, char **argv)
{
	data->out_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (data->out_fd == -1)
	{
		perror("wrong outfile\n");
		exit(EXIT_FAILURE);
	}
	dup2(data->out_fd, STDOUT_FILENO);
}

void	ft_execute_cmd(t_data *data, int argc, char **argv, char **envp)
{
	data->options = ft_split(argv[data->j], ' ');
	if (data->j == 2)
		ft_infile(data, argv);
	dup2(data->tmp_fd, STDIN_FILENO);
	if (data->j == argc - 2)
		ft_outfile(data, argc, argv);
	else
		dup2(data->tab[1], STDOUT_FILENO);
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
	perror("execution failed");
}

int	main(int argc, char **argv, char **envp)
{
	int		status;
	pid_t	pid;
	t_data	data;

	ft_create_data(&data, argc);
	while (data.j != argc - 1)
	{
		if (pipe(data.tab) == -1)
			perror("pipe error\n");
		pid = fork();
		if (pid == -1)
			perror("fork error\n");
		else if (pid == 0)
			ft_execute_cmd(&data, argc, argv, envp);
		else
		{
			waitpid(pid, &status, 0);
			ft_close_redir(&data, argc);
			data.j++;
		}
	}
}
