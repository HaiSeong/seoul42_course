/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:50:54 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/24 20:49:05 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_start(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	info->start_time = get_time();
	while (i < info->philo_num)
	{
		(*philo)[i].eat_time = get_time();
		pthread_create(&((*philo)[i].routine), \
			NULL, routine, &((*philo)[i]));
		i++;
	}
}

int	is_all_alive(t_info *info)
{
	pthread_mutex_lock(info->guard);
	if (info->all_alive == 0)
	{
		pthread_mutex_unlock(info->guard);
		return (0);
	}
	pthread_mutex_unlock(info->guard);
	return (1);
}

void	*routine(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *)philo_data;
	if (philo->num % 2 == 0)
		usleep(800);
	while (is_all_alive(philo->info))
	{
		take_left_fork(philo);
		take_right_fork(philo);
		eatting(philo);
		put_fork(philo);
		(philo->eat_count)++;
		if (philo->eat_count == philo->info->philo_must_eat)
		{
			pthread_mutex_lock(philo->guard);
			philo->life = 0;
			pthread_mutex_unlock(philo->guard);
		}
		sleeping(philo);
		if (is_all_alive(philo->info))
			printf("%lld %d is thinking\n", \
				relative_time(philo->info), philo->num);
	}
	return (NULL);
}
