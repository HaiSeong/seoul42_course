/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:37:52 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/13 19:58:52 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_error(char *msg)
{
	printf("Error : %s\n", msg);
	exit(1);
}

void ft_error_free(char *msg, t_vars *vars)
{
	ft_error(msg);
	free(vars->fork);
	vars->fork = NULL;
	exit(1);
}

long long	milli_sec(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	get_time(t_vars *vars)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((int)(milli_sec(now) - vars->start_time));
}
