/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:03:53 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/13 16:39:56 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void check_args(int argc, char *argv[])
{
	int index;
	int i;

	if (argc != 5 && argc != 6)
		ft_error("You need more args");
	index = 1;
	while (index < argc)
	{
		i = 0;
		while (argv[index][i] != '\0')
		{
			if (!ft_isspace(argv[index][i]) && !ft_isdigit(argv[index][i]) && argv[index][i] != '+')
				ft_error("You have wrong char in args");
			i++;
		}
		index++;
	}
}

void init_vars(t_vars *vars, int argc, char *argv[])
{
	check_args(argc, argv);
	vars->philo_number = ft_atoi(argv[1]);
	vars->time_to_die = ft_atoi(argv[2]);
	vars->time_to_eat = ft_atoi(argv[3]);
	vars->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		vars->must_eat = ft_atoi(argv[5]);
		if (vars->must_eat < 0)
			ft_error("Negative argument");
	}
	if (vars->philo_number <= 0 || vars->time_to_die <= 0
		|| vars->time_to_eat <= 0 || vars->time_to_sleep <= 0)
			ft_error("Negative argument");
}