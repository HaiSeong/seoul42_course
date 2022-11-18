#include "philo.h"

int	init_fork(t_vars *vars)
{
	int	i;

	i = 0;
	vars->forks = malloc(sizeof(pthread_mutex_t) * vars->num_of_philos);
	if (vars->forks == NULL)
		return (ft_error("System Error"));
	while (i < vars->num_of_philos)
	{
		pthread_mutex_init(&(vars->forks[i]), NULL);
		i++;
	}
	return (0);
}

int	init_eat_check(t_vars *vars)
{
	int	i;

	i = 0;
	vars->deadcheck = malloc(sizeof(pthread_mutex_t) * vars->num_of_philos);
	if (vars->deadcheck == NULL)
		return (ft_error("System Error"));
	while (i < vars->num_of_philos)
	{
		pthread_mutex_init(&(vars->deadcheck[i]), NULL);
		i++;
	}
	return (0);
}

int	make_philo(t_vars *vars)
{
	int	i;

	i = 0;
	vars->philo_arr = malloc(sizeof(t_philo) * vars->num_of_philos);
	if (vars->philo_arr == NULL)
		return (ft_error("System Error"));
	while (i < vars->num_of_philos)
	{	
		vars->philo_arr[i].number = i + 1;
		vars->philo_arr[i].last_eat_time = get_time();
		vars->philo_arr[i].eat_cnt = 0;
		vars->philo_arr[i].left_fork = &(vars->forks[i]);
		vars->philo_arr[i].right_fork = &(vars->forks[((i + 1) % vars->num_of_philos)]);
		vars->philo_arr[i].deadcheck = &(vars->deadcheck[i]);
		vars->philo_arr[i].print = &(vars->print);
		vars->philo_arr[i].vars = vars;
		pthread_create(&(vars->philo_arr[i].thread), NULL, philo_func, &(vars->philo_arr[i]));
		pthread_detach(vars->philo_arr[i].thread);
		i++;
	}
	return (0);
}

int	init_philo(t_vars *vars)
{
	pthread_mutex_init(&(vars->print), NULL);
	if (init_fork(vars))
		return (1);
	if (init_eat_check(vars))
	{
		free(vars->forks);
		return (1);
	}
	if (make_philo(vars))
	{
		free(vars->forks);
		free(vars->deadcheck);
		return (1);
	}
	return (0);
}
