/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:24:20 by dongmiki          #+#    #+#             */
/*   Updated: 2023/06/17 15:19:49 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_arg *arg, char **envp, char **av)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
		error(1, NULL);
	pid1 = fork();
	if (pid1 == -1)
		error(1, NULL);
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(arg->infile, STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		cmd_start(arg, envp, 0, av);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}

void	parent_process(t_arg *arg, char **envp, char **av)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
		error(1, NULL);
	pid1 = fork();
	if (pid1 == -1)
		error(1, NULL);
	if (pid1 == 0)
	{
		dup2(arg->outfile, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		cmd_start(arg, envp, 1, av);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}

int	main(int ac, char *av[], char **envp)
{	
	t_arg	*arg;

	if (ac != 5)
		error(2, NULL);
	arg = arg_check(ac, av);
	if (!arg)
		error(2, NULL);
	child_process(arg, envp, av);
	parent_process(arg, envp, av);
	wait_all();
}
