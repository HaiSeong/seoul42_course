#include "philo.h"

int	philo_eat(t_philo *philo)
{
	philo_take_fork(philo);
	pthread_mutex_lock(philo->deadcheck);
	philo->eat_cnt++;
	philo_print(philo, EAT);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(philo->deadcheck);
	delay(philo->vars->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	philo_print(philo, SLEEP);
	delay(philo->vars->time_to_sleep);
	return (0);
}

int	philo_think(t_philo *philo)
{
	philo_print(philo, THINK);
	usleep(200);
	return (0);
}

void	*philo_func(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->vars->philo_dead == 0 && philo->vars->philo_eat == 0)
	{
		philo_eat(philo);
		if (philo->vars->philo_dead == 1)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	return (0);
}
