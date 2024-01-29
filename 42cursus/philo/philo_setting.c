/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:33:22 by dongmiki          #+#    #+#             */
/*   Updated: 2023/08/10 17:49:39 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_each_philo_eat(t_philo_program *info, char **av, int ac)
{
	int	i;

	if (ac == 6)
	{
		i = -1;
		info->num_time_philo_eat = ft_atoi(av[5]);
		if (!info->num_time_philo_eat)
			return (0);
		info->eat_index = 0;
	}
	else
		info->num_time_philo_eat = -1;
	return (1);
}

static void	pointer_set_null(t_philo_program	*info)
{
	info->philo = NULL;
	info->fork = NULL;
	info->starve = NULL;
	info->fork_index = NULL;
}

int	setting_philo(t_philo_program	*info, int ac, char **av)
{
	pointer_set_null(info);
	info->number_of_philo = ft_atoi(av[1]);
	if (info->number_of_philo == 0)
		return (0);
	if (!set_each_philo_eat(info, av, ac))
		return (0);
	if (pthread_mutex_init(&(info->eat), NULL))
		return (0);
	if (!ft_atoi(av[2]) || !ft_atoi(av[3]) || !ft_atoi(av[4]))
		return (0);
	info->fork_index = (int *)malloc(sizeof(int) * info->number_of_philo);
	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* info->number_of_philo);
	info->starve = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* info->number_of_philo);
	if (!info->fork_index || !info->fork || !info->starve \
	||pthread_mutex_init(&(info->print), NULL) \
	|| pthread_mutex_init(&(info->die), NULL) \
	|| pthread_mutex_init(&(info->start_m), NULL))
		return (0);
	return (1);
}

static int	setting_philo_start(t_philo_program *info, char **av, int i)
{
	info->philo[i].id = i;
	info->philo[i].left = i;
	info->philo[i].right = (i + 1) % info->number_of_philo;
	info->philo[i].time_to_die = ft_atoi(av[2]);
	info->philo[i].time_to_eat = ft_atoi(av[3]);
	info->philo[i].time_to_sleep = ft_atoi(av[4]);
	info->philo[i].eat_count = 0;
	info->philo[i].info = info;
	return (1);
}

int	create_philo(t_philo_program *info, char **av)
{
	int	i;

	i = -1;
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philo);
	if (!info->philo)
		return (0);
	while (++i < info->number_of_philo)
		info->fork_index[i] = 0;
	i = -1;
	while (++i < info->number_of_philo)
	{
		if (!setting_philo_start(info, av, i))
			return (0);
		if (pthread_mutex_init(&(info->fork[i]), NULL))
			return (0);
		if (pthread_mutex_init(&(info->starve[i]), NULL))
			return (0);
		if (pthread_create(&(info->philo[i].thread), NULL, philo_action, \
		&(info->philo[i])))
			return (0);
	}
	return (1);
}
