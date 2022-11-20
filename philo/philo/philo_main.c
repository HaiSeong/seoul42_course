/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:15 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/20 10:20:10 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	fork_value_malloc_error(t_info info)
{
	free(info.print);
	return (ft_error_free("fork_init error", &info));
}

static int	fork_malloc_error(t_info info, int *fork_value)
{
	free(fork_value);
	free(info.print);
	return (ft_error_free("fork_init error", &info));
}

static int	philo_init_malloc_error(t_info info, int *fork_value, \
pthread_mutex_t *fork, t_philo *philo)
{
	free(philo);
	free(fork);
	free(fork_value);
	free(info.print);
	return (ft_error_free("philo_init error", &info));
}

int	main(int argc, char *argv[])
{
	pthread_mutex_t	*fork;
	int				*fork_value;
	t_info			info;
	t_philo			*philo;

	if (make_info(&info, argc, argv) < 0)
		return (ft_error("make_info error"));
	if (info.philo_num <= 1)
		return (0);
	fork_value = fork_value_init(info.philo_num);
	if (fork_value == NULL)
		fork_value_malloc_error(info);
	fork = fork_init(info.philo_num);
	if (fork == NULL)
		fork_malloc_error(info, fork_value);
	philo = (t_philo *)malloc(sizeof(t_philo) * info.philo_num);
	if (philo_init(&info, &philo, fork, fork_value) < 0)
		philo_init_malloc_error(info, fork_value, fork, philo);
	routine_start(&philo, &info);
	monitoring(&info, &philo);
	memory_free(philo, info, fork);
}
