/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:12 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/20 09:26:16 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	printf("%s\n", str);
	return (0);
}

int	ft_error_free(char *str, t_info *info)
{
	free(info->guard);
	return (ft_error(str));
}

long long	get_time(void)
{
	struct timeval	time;
	long long		now_time;

	gettimeofday(&time, 0);
	now_time = time.tv_usec / 1000 + time.tv_sec * 1000;
	return (now_time);
}

long long	relative_time(t_info *info)
{
	return (get_time() - info->start_time);
}
