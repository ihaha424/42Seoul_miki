/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:12:05 by dongmiki          #+#    #+#             */
/*   Updated: 2023/08/10 17:20:47 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo_program	t_philo_program;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				left;
	int				right;
	int				eat_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			last_eat_time;
	long			mytime;
	t_philo_program	*info;
}	t_philo;

typedef struct s_philo_program
{
	t_philo			*philo;
	int				number_of_philo;
	int				num_time_philo_eat;
	int				*fork_index;
	int				eat_index;
	int				die_flag;
	int				start;
	long			whole_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*starve;
	pthread_mutex_t	print;
	pthread_mutex_t	die;
	pthread_mutex_t	eat;
	pthread_mutex_t	start_m;
}	t_philo_program;

int				main(int ac, char **av);
int				ft_atoi(const char *str);
int				taken_a_fork(t_philo *philo);
int				died(t_philo *philo);
int				eating(t_philo *philo);
int				sleeping(t_philo *philo);
int				thinking(t_philo *philo);
int				wait_time(t_philo *philo, long time);
int				print_status(t_philo *philo, char *str);
int				error(t_philo_program *info, int flag);
int				starve(t_philo *philo);
int				create_philo(t_philo_program *philo, char **av);
int				setting_philo(t_philo_program	*info, int ac, char **av);
int				one_tread(t_philo_program *info, char *dead);
long			get_time(void);
void			wait_thread(t_philo_program *info);
void			ft_putstr_fd(char *s, int fd);
void			*philo_action(void *info);
void			free_malloc(t_philo_program *info);
size_t			ft_strlen(const char *str);
#endif