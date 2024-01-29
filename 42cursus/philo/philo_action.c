/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:54:25 by dongmiki          #+#    #+#             */
/*   Updated: 2023/08/10 20:08:32 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;
	long			temp;

	gettimeofday(&time, NULL);
	temp = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (temp);
}

int	print_status(t_philo *philo, char *str)
{
	long	temp;

	pthread_mutex_lock(&philo->info->print);
	pthread_mutex_lock(&philo->info->die);
	if (philo->info->die_flag == 1)
	{
		pthread_mutex_unlock(&philo->info->die);
		pthread_mutex_unlock(&philo->info->print);
		return (0);
	}
	pthread_mutex_unlock(&philo->info->die);
	temp = get_time();
	printf("%ld %d %s\n", temp - philo->mytime, ((philo->id) + 1), str);
	pthread_mutex_unlock(&philo->info->print);
	return (1);
}

int	wait_time(t_philo *philo, long time)
{
	long	start;
	long	now;
	int		flag;

	flag = 1;
	start = philo->id;
	start = get_time();
	while (died(philo) && flag)
	{
		now = get_time();
		if (now - start >= time)
		{
			flag = 0;
			break ;
		}
		usleep(100);
	}
	if (flag)
		return (0);
	return (1);
}

static void	wait_start(t_philo	*philo)
{
	pthread_mutex_lock(&philo->info->start_m);
	philo->mytime = philo->info->whole_time;
	pthread_mutex_unlock(&philo->info->start_m);
}

void	*philo_action(void *arg)
{
	t_philo	*philo;

	philo = arg;
	wait_start(philo);
	if (philo->id % 2 == 1)
		usleep(1000);
	philo->last_eat_time = philo->mytime;
	while (died(philo))
	{
		usleep(100);
		if (!(starve(philo)))
			continue ;
		if (!(taken_a_fork(philo)))
			continue ;
		if (!eating(philo))
			break ;
		if (!sleeping(philo))
			break ;
		if (!thinking(philo))
			break ;
	}
	return (0);
}
