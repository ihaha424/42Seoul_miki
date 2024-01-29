/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:31:01 by dongmiki          #+#    #+#             */
/*   Updated: 2023/06/17 14:55:40 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int flag, char *av)
{
	if (flag == 0 || flag == 3)
	{
		if (flag == 0)
			ft_putstr_fd("Error: command not found: ", 2);
		else
			ft_putstr_fd("Error: no such file or directory: ", 2);
		ft_putstr_fd(av, 2);
	}
	else if (flag == 1)
		perror("Error");
	else if (flag == 2)
		ft_putstr_fd("Error: arguments is fail", 2);
	else if (flag == 4)
	{
		ft_putstr_fd("Error: permission denied: ", 2);
		ft_putstr_fd(av, 2);
	}
	exit(EXIT_FAILURE);
}

char	*is_path(int i, char *cmd, char **paths)
{
	char	*path;
	char	*part_path;

	part_path = ft_strjoin(paths[i], "/");
	if (!part_path)
		return (NULL);
	path = ft_strjoin(part_path, cmd);
	free(part_path);
	if (!path)
		return (NULL);
	if (access(path, F_OK) == 0)
		return (path);
	free(path);
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		error(1, NULL);
	i = -1;
	while (paths[++i])
	{
		path = is_path(i, cmd, paths);
		if (!path)
			continue ;
		break ;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	if (path)
		return (path);
	return (NULL);
}

void	cmd_start(t_arg *arg, char **envp, int index, char **av)
{
	int		i;
	char	*path;
	char	**cmd;

	i = -1;
	cmd = ft_split(arg->cmd[index], ' ');
	if (!cmd)
		error(1, NULL);
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		free_malloc(arg, 1, av);
		error(0, av[index + 2]);
	}
	if (execve(path, cmd, envp) == -1)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		free_malloc(arg, 1, av);
		error(1, NULL);
	}
}

void	wait_all(void)
{
	pid_t	pid;
	int		temp;

	pid = 1;
	while (pid != -1)
		pid = waitpid(0, &temp, WNOHANG);
}
