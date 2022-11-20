/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:19 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/20 09:53:53 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_info *info, t_philo **philo, pthread_mutex_t *fork, \
int *fork_value)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		(*philo)[i].num = i + 1;
		(*philo)[i].life = 1;
		(*philo)[i].eat_count = 0;
		(*philo)[i].info = info;
		(*philo)[i].left_fork = \
		&fork[(info->philo_num + i - 1) % info->philo_num];
		(*philo)[i].right_fork = &fork[i];
		(*philo)[i].left_fork_value = &fork_value[(info->philo_num + i - 1) \
		% info->philo_num];
		(*philo)[i].right_fork_value = &fork_value[i];
		(*philo)[i].guard = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!((*philo)[i].guard))
		{
			while (--i >= 0)
				free((*philo)[i].guard);
			return (-1);
		}
		pthread_mutex_init((*philo)[i++].guard, 0);
	}
	return (0);
}
