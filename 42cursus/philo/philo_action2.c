/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:14:45 by dongmiki          #+#    #+#             */
/*   Updated: 2023/08/10 20:03:49 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	taken_a_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->left]);
	pthread_mutex_lock(&philo->info->fork[philo->right]);
	if (!philo->info->fork_index[philo->left] \
	&& !philo->info->fork_index[philo->right])
	{
		philo->info->fork_index[philo->left] = 1;
		philo->info->fork_index[philo->right] = 1;
		pthread_mutex_unlock(&philo->info->fork[philo->right]);
		pthread_mutex_unlock(&philo->info->fork[philo->left]);
		if (!print_status(philo, "has taken a fork"))
			return (0);
		if (!print_status(philo, "has taken a fork"))
			return (0);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->fork[philo->right]);
	pthread_mutex_unlock(&philo->info->fork[philo->left]);
	return (0);
}

int	eating(t_philo *philo)
{
	if (!print_status(philo, "is eating"))
		return (0);
	philo->eat_count++;
	pthread_mutex_lock(&philo->info->starve[philo->id]);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->info->starve[philo->id]);
	pthread_mutex_lock(&philo->info->eat);
	if (philo->info->num_time_philo_eat > 0 && \
	philo->eat_count == philo->info->num_time_philo_eat)
	{
		philo->info->eat_index++;
	}
	pthread_mutex_unlock(&philo->info->eat);
	if (!wait_time(philo, philo->time_to_eat))
		return (0);
	pthread_mutex_lock(&philo->info->fork[philo->left]);
	pthread_mutex_lock(&philo->info->fork[philo->right]);
	philo->info->fork_index[philo->left] = 0;
	philo->info->fork_index[philo->right] = 0;
	pthread_mutex_unlock(&philo->info->fork[philo->right]);
	pthread_mutex_unlock(&philo->info->fork[philo->left]);
	return (1);
}

int	sleeping(t_philo *philo)
{
	if (!print_status(philo, "is sleeping"))
		return (0);
	if (!wait_time(philo, philo->time_to_sleep))
		return (0);
	return (1);
}

int	thinking(t_philo *philo)
{
	if (!print_status(philo, "is thinking"))
		return (0);
	return (1);
}

int	died(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->die);
	if (philo->info->die_flag == 1)
	{
		pthread_mutex_unlock(&philo->info->die);
		return (0);
	}
	if (get_time() - philo->last_eat_time >= (long)(philo->time_to_die))
	{
		philo->info->die_flag = 1;
		pthread_mutex_unlock(&philo->info->die);
		pthread_mutex_lock(&philo->info->print);
		printf("%ld %d %s\n", get_time() - philo->mytime, ((philo->id) + 1) \
		, "died");
		pthread_mutex_unlock(&philo->info->print);
		return (0);
	}
	pthread_mutex_unlock(&philo->info->die);
	return (1);
}
