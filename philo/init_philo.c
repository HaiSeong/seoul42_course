#include "philo.h"

int	init_fork(t_vars *vars)
{
	int	i;

	i = 0;
	vars->forks = malloc(sizeof(pthread_mutex_t) * vars->num_of_philos);
	if (vars->forks == NULL)
		return (ft_error("Error: Forks Malloc Failure\n"));
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
		return (ft_error("Deadcheck Malloc Failure\n"));
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
	vars->philo_args = malloc(sizeof(t_philo) * vars->num_of_philos);
	if (vars->philo_args == NULL)
		return (ft_error("Philo Array Malloc Failure\n"));
	while (i < vars->num_of_philos)
	{	
		vars->philo_args[i].number = i + 1;
		vars->philo_args[i].last_eat_time = get_time();
		vars->philo_args[i].eat_cnt = 0;
		vars->philo_args[i].print = &(vars->print);
		vars->philo_args[i].deadcheck = &(vars->deadcheck[i]);
		vars->philo_args[i].left_fork = &(vars->forks[i]);
		vars->philo_args[i].right_fork = &(vars->forks[((i + 1) % vars->num_of_philos)]);
		vars->philo_args[i].vars = vars;
		pthread_create(&(vars->philo_args[i].thread), NULL, philo_func, &(vars->philo_args[i]));
		pthread_detach(vars->philo_args[i].thread);
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
		return (1);
	if (make_philo(vars))
		return (1);
	return (0);
}
