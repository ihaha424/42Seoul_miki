/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:59:41 by dongmiki          #+#    #+#             */
/*   Updated: 2023/08/14 16:20:47 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo_program	*info;

	if (!(ac == 5 || ac == 6))
		return (error(NULL, 0) + 1);
	info = (t_philo_program *)malloc(sizeof(t_philo_program));
	if (!info)
		return (0);
	if (!setting_philo(info, ac, av))
		return (error(info, 0) + 1);
	if (info->number_of_philo == 1)
		return (one_tread(info, av[2]));
	info->die_flag = 0;
	info->start = 0;
	pthread_mutex_lock(&info->start_m);
	if (!create_philo(info, av))
		return (error(info, 0) + 1);
	info->start = 1;
	info->whole_time = get_time();
	pthread_mutex_unlock(&info->start_m);
	wait_thread(info);
	free_malloc(info);
	return (0);
}
