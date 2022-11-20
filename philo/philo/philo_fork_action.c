/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:28 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/20 10:22:48 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	philo->left_fork_value++;
	if (is_all_alive(philo->info))
		print_fork(philo);
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	philo->right_fork_value++;
	if (is_all_alive(philo->info))
		print_fork(philo);
}

void	put_fork(t_philo *philo)
{
	philo->left_fork_value--;
	pthread_mutex_unlock(philo->left_fork);
	philo->right_fork_value--;
	pthread_mutex_unlock(philo->right_fork);
}
