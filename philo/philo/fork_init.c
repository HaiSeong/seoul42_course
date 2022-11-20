/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:49 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/20 09:25:09 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*fork_init(int philo_num)
{
	pthread_mutex_t	*new;
	int				i;

	i = 0;
	new = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_num);
	if (new == NULL)
		return (NULL);
	while (i < philo_num)
	{
		pthread_mutex_init(&new[i], 0);
		i++;
	}
	return (new);
}

int	*fork_value_init(int philo_num)
{
	int	*new;
	int	i;

	i = 0;
	new = (int *)malloc(sizeof(int) * philo_num);
	if (new == NULL)
		return (NULL);
	while (i < philo_num)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
