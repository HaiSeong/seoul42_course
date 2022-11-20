/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:34 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/20 10:23:30 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat_time_check(long long starttime, t_philo *philo)
{
	if (get_time() - starttime >= philo->info->time_to_eat)
	{
		return (0);
	}
	else
		return (1);
}

void	eatting(t_philo *philo)
{	
	pthread_mutex_lock(philo->guard);
	philo->eat_time = get_time();
	pthread_mutex_unlock(philo->guard);
	if (is_all_alive(philo->info))
	{
		print_eating(philo);
		while (eat_time_check(philo->eat_time, philo))
			usleep(100);
	}
}

static int	sleep_time_check(long long start, t_philo *philo)
{
	if (get_time() - start >= philo->info->time_to_sleep)
		return (0);
	else
		return (1);
}

void	sleeping(t_philo *philo)
{
	long long	sleep_start;

	if (is_all_alive(philo->info))
	{
		sleep_start = get_time();
		print_sleeping(philo);
		while (sleep_time_check(sleep_start, philo))
			usleep(100);
	}
	else
		return ;
}
