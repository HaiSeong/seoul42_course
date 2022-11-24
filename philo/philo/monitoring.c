/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:38 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/24 20:49:09 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_someone_die(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(philo->guard);
	if (philo->life)
	{
		if (get_time() - philo->eat_time >= philo->info->time_to_die)
		{
			pthread_mutex_lock(info->guard);
			info->all_alive = 0;
			pthread_mutex_lock(info->print);
			printf("%lld %d died\n", relative_time(philo->info), philo->num);
			pthread_mutex_unlock(info->guard);
		}
	}
	pthread_mutex_unlock(philo->guard);
}

void	monitoring(t_info *info, t_philo **philo)
{
	int		i;
	int		cnt;
	t_philo	*temp;

	temp = *philo;
	while (is_all_alive(info))
	{
		i = 0;
		cnt = 0;
		while (i < info->philo_num && is_all_alive(info))
		{
			check_someone_die(&temp[i], info);
			pthread_mutex_lock(temp[i].guard);
			if (temp[i].life == 0)
				cnt++;
			pthread_mutex_unlock(temp[i].guard);
			i++;
		}
		if (cnt == info->philo_num)
		{
			pthread_mutex_lock(info->guard);
			info->all_alive = 0;
			pthread_mutex_unlock(info->guard);
		}
	}
}
