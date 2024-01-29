/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:02:00 by dongmiki          #+#    #+#             */
/*   Updated: 2023/08/10 19:12:16 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_tread(t_philo_program *info, char *dead)
{
	printf("0 1 has taken a fork\n");
	usleep(ft_atoi(dead) * 1000);
	printf("%s 1 died\n", dead);
	return (error(info, 1));
}

static void	wait_thread_final(t_philo_program *info)
{
	int	temp;
	int	count;

	temp = -1;
	while (++temp < info->number_of_philo)
		count = pthread_join(info->philo[temp].thread, NULL);
}

void	wait_thread(t_philo_program *info)
{
	while (info->num_time_philo_eat > 0)
	{
		pthread_mutex_lock(&info->eat);
		pthread_mutex_lock(&info->die);
		if (info->eat_index == info->number_of_philo)
			info->die_flag = 1;
		if (info->die_flag == 1)
		{
			pthread_mutex_unlock(&info->die);
			pthread_mutex_unlock(&info->eat);
			break ;
		}
		pthread_mutex_unlock(&info->die);
		pthread_mutex_unlock(&info->eat);
	}
	wait_thread_final(info);
}

int	starve(t_philo *philo)
{
	int		flag;
	int		temp;

	flag = 1;
	if (philo->mytime == philo->last_eat_time)
		return (flag);
	temp = philo->left - 1;
	if (temp == -1)
		temp = philo->info->number_of_philo - 1;
	pthread_mutex_lock(&philo->info->starve[temp]);
	if (philo->info->philo[temp].last_eat_time < philo->last_eat_time)
		flag = 0;
	pthread_mutex_unlock(&philo->info->starve[temp]);
	pthread_mutex_lock(&philo->info->starve[philo->right]);
	if (philo->info->philo[philo->right].last_eat_time < philo->last_eat_time)
		flag = 0;
	pthread_mutex_unlock(&philo->info->starve[philo->right]);
	return (flag);
}
