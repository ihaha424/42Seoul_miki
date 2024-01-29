/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_arg_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:47:56 by dongmiki          #+#    #+#             */
/*   Updated: 2023/06/24 14:08:35 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_arg	*free_malloc(t_arg *arg, int flag, char **av)
{
	int	i;

	i = 0;
	if (flag)
		free(arg->cmd);
	free(arg);
	if (flag > 1)
		error(3, av[flag - 1]);
	return (NULL);
}

t_arg	*arg_check(int ac, char **av)
{
	t_arg	*arg;
	int		i;

	i = 1;
	arg = (t_arg *)malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->infile = 0;
	if (!(ft_strncmp(av[1], "here_doc", 9) == 0))
		arg->infile = open(av[1], O_RDONLY);
	if (arg->infile < 0)
		error(3, av[1]);
	arg->cmd_count = -1;
	arg->cmd = (char **)malloc(sizeof(char *) * (ac - 3));
	if (!(arg->cmd))
		return (free_malloc(arg, 1, av));
	while (++(arg->cmd_count) > -1 && ++i < ac - 1)
		arg->cmd[i - 2] = av[i];
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		arg->outfile = open(av[i], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		arg->outfile = open(av[i], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->outfile < 0)
		error(4, av[i]);
	return (arg);
}
