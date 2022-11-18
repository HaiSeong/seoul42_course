#include "philo.h"

int	check_eat(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->num_of_philos && vars->must_eat != -1 && \
	vars->philo_arr[i].eat_cnt >= vars->must_eat)
		i++;
	if (i == vars->num_of_philos)
		vars->philo_eat = 1;
	return (0);
}

int	check_dead(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->num_of_philos && (vars->philo_dead == 0))
	{
		pthread_mutex_lock(&(vars->deadcheck[i]));
		if (get_time() - vars->philo_arr[i].last_eat_time \
		> vars->time_to_die)
		{
			philo_print(&(vars->philo_arr[i]), DEAD);
			vars->philo_dead = 1;
		}
		pthread_mutex_unlock(&(vars->deadcheck[i]));
		i++;
	}
	return (0);
}

int	check_philo(t_vars *vars)
{
	while (1)
	{
		check_dead(vars);
		if (vars->philo_dead == 1)
			break ;
		check_eat(vars);
		if (vars->philo_eat == 1)
		{
			pthread_mutex_lock(&(vars->print));
			printf("All philosophers are done eating.\n");
			break ;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{	
	t_vars	vars;

	if (argc < 5 || argc > 6)
		return (ft_error("argument\n"));
	if (init_vars(&vars, argc, argv) != 0)
		return (1);
	if (init_philo(&vars) != 0)
		return (1);
	check_philo(&vars);
	return (0);
}
