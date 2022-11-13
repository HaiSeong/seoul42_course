/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:58:10 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/13 19:57:57 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, t_vars *vars, int id)
{
	philo->cnt = 0;
	philo->vars = vars;
	philo->last_eat = get_time(philo->vars);
	philo->id = id;
	philo->status = THINK;
	philo->left_fork = (id + vars->philo_number - 1) % vars->philo_number;
	philo->right_fork = id;
}

void	*rootine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->vars->is_someone_dead && philo->status != DONE)
	{
		if (philo->status == THINK)
			make_philo_eat(philo);
		else if (philo->status == EAT)
			make_philo_sleep(philo);
		else if (philo->status == SLEEP)
			make_philo_think(philo);
	}
	return NULL;
}

void make_philo_thread(t_philo *philos, t_vars *vars)
{
	int	id;

	id = 0;
	while (id < vars->philo_number)
	{
		init_philo(&philos[id], vars, id);
		if (pthread_create(&philos[id].thread_id, NULL, rootine, (void *)&philos[id]))
			ft_error_free("System problem", vars);
	}
	
}
