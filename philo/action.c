/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:39:02 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/13 20:24:34 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_print(t_philo philo, char *str)
{
	pthread_mutex_lock(&philo.vars->print);
	if (philo.vars->is_someone_dead > 0)
	{
		pthread_mutex_unlock(&philo.vars->print);
		return ;
	}
	printf("%d %d %s\n", get_time(philo.vars), philo.id + 1, str);
	pthread_mutex_unlock(&philo.vars->print);
}

void	make_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->fork[philo->left_fork]);
	print_print(*philo, "has taken a fork");
	pthread_mutex_lock(&philo->vars->fork[philo->right_fork]);
	print_print(*philo, "has taken a fork");
	philo->cnt++;
	philo->last_eat = get_time(philo->vars);
	print_print(*philo, "is eating");
	philo->status = EAT;
	if (philo->cnt == philo->vars->must_eat)
	{
		pthread_mutex_unlock(&philo->vars->fork[philo->left_fork]);
		pthread_mutex_unlock(&philo->vars->fork[philo->right_fork]);
		philo->status = DONE;
	}
}

void	make_philo_sleep(t_philo *philo)
{
	while ((get_time(philo->vars) - philo->last_eat) < philo->vars->time_to_eat)
	{
		if (philo->vars->is_someone_dead > 0)
		{
			pthread_mutex_unlock(&philo->vars->fork[philo->left_fork]);
			pthread_mutex_unlock(&philo->vars->fork[philo->right_fork]);
			return ;
		}
		usleep(100);
	}
	pthread_mutex_unlock(&philo->vars->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->vars->fork[philo->right_fork]);
	print_print(*philo, "is sleeping");
	philo->status = SLEEP;
}

void	make_philo_think(t_philo *philo)
{
	while ((get_time(philo->vars) - philo->last_eat)
		< (philo->vars->time_to_eat + philo->vars->time_to_sleep))
	{
		if (philo->vars->is_someone_dead > 0)
			return ;
		usleep(100);
	}
	print_print(*philo, "is thinking");
	philo->status = THINK;
}
