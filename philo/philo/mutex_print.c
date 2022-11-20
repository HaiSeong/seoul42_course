/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:15:20 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/20 10:24:42 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->info->print);
	printf("%lld %d is eating\n", relative_time(philo->info), philo->num);
	pthread_mutex_unlock(philo->info->print);
}

void	print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->info->print);
	printf("%lld %d is sleeping\n", relative_time(philo->info), philo->num);
	pthread_mutex_unlock(philo->info->print);
}

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->info->print);
	printf("%lld %d has taken a fork\n", \
		get_time() - philo->info->start_time, philo->num);
	pthread_mutex_unlock(philo->info->print);
}
