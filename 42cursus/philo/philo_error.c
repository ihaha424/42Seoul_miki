/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:22:10 by dongmiki          #+#    #+#             */
/*   Updated: 2023/08/10 17:47:10 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(t_philo_program *info, int flag)
{
	free_malloc(info);
	if (flag == 0)
		ft_putstr_fd("Argument Error\n", 2);
	return (0);
}

void	free_malloc(t_philo_program *info)
{
	int	i;

	i = -1;
	if (info)
	{
		if (info->fork_index)
			free(info->fork_index);
		if (info->fork)
			free(info->fork);
		if (info->starve)
			free(info->starve);
		if (info->philo)
			free(info->philo);
		if (info)
			free(info);
	}
}
