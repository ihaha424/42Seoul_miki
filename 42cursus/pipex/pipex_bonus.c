/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:48:57 by dongmiki          #+#    #+#             */
/*   Updated: 2023/09/08 16:24:50 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	put_and_gnl(char **line, int fd)
{
	ft_putstr_fd(*line, fd);
	free(*line);
	write(1, "heredoc> ", 9);
	*line = get_next_line(0);
}

void	here_doc(t_arg *arg)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		error(1, NULL);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		while (line)
		{
			if (ft_strncmp(line, arg->cmd[0], ft_strlen(arg->cmd[0])) == 0)
				exit(EXIT_SUCCESS);
			put_and_gnl(&line, fd[1]);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	child_process_bonus(t_arg *arg, char **envp, int i, char **av)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error(1, NULL);
	pid = fork();
	if (pid == -1)
		error(1, NULL);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		cmd_start(arg, envp, i, av);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
}

void	final_process(t_arg *arg, char **envp, int i, char **av)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error(1, NULL);
	pid = fork();
	if (pid == -1)
		error(1, NULL);
	if (pid == 0)
	{
		dup2(arg->outfile, STDOUT_FILENO);
		close(arg->outfile);
		close(fd[1]);
		close(fd[0]);
		cmd_start(arg, envp, i, av);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(arg->outfile);
	wait_all();
}

int	main(int ac, char *av[], char **envp)
{	
	int		index;
	t_arg	*arg;

	if (ac < 5)
		error(2, NULL);
	arg = arg_check(ac, av);
	if (!arg)
		error(2, NULL);
	index = 0;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		if (ac < 6)
			error(2, NULL);
		here_doc(arg);
		index++;
	}
	else
	{
		dup2(arg->infile, STDIN_FILENO);
		close(arg->infile);
	}
	while (index < ac - 4)
		child_process_bonus(arg, envp, index++, av);
	final_process(arg, envp, index++, av);
	return (EXIT_SUCCESS);
}
