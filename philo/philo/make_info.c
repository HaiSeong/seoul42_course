/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:46 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/25 19:31:55 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(char *str)
{
	long long	number;
	int			i;

	i = 0;
	number = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	while (str[i])
	{
		number = number * 10 + (str[i] - '0');
		if (number > 2147483647 || !(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	if (i == 0 || number <= 0)
		return (-1);
	return (number);
}

static int	argv_check(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

void	*exception_rootine(void *data)
{
	long long	*time;

	time = (long long *)data;
	printf("%d %d has taken a fork\n", 0, 1);
	usleep(*time * 1000);
	printf("%lld %d died\n", *time, 1);
	return (0);
}

static int	exception_case(long long time)
{
	pthread_t	one;

	pthread_create(&one, NULL, exception_rootine, &time);
	pthread_join(one, NULL);
	return (0);
}

int	make_info(t_info *info, int ac, char *argv[])
{
	if ((ac != 5 && ac != 6) || argv_check(argv) < 0)
		return (-1);
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->all_alive = 1;
	info->philo_must_eat = -1;
	if (ac == 6)
		info->philo_must_eat = ft_atoi(argv[5]);
	if (info->philo_num == 1)
		return (exception_case(info->time_to_die));
	info->guard = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!(info->guard))
		return (-1);
	pthread_mutex_init(info->guard, 0);
	info->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!(info->print))
	{
		free (info->guard);
		return (-1);
	}
	pthread_mutex_init(info->print, 0);
	return (0);
}
