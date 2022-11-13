/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:37:58 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/13 19:54:52 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int argc, char *argv[])
{
	t_vars vars;
	t_philo *philos;


	init_vars(&vars, argc, argv);


	philos = (t_philo *)malloc(sizeof(t_philo) * vars.philo_number);

	make_philo_thread(philos, &vars);
		
}