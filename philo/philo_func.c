#include "philo.h"

void	philo_take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->print);
		printf("%lld %d has taken fork\n", get_time() - philo->vars->time_of_start, philo->id);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->print);
		printf("%lld %d has taken fork\n", get_time() - philo->vars->time_of_start, philo->id);
		pthread_mutex_unlock(philo->print);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->print);
		printf("%lld %d has taken fork\n", get_time() - philo->vars->time_of_start, philo->id);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->print);
		printf("%lld %d has taken fork\n", get_time() - philo->vars->time_of_start, philo->id);
		pthread_mutex_unlock(philo->print);
	}
}

int	philo_eat(t_philo *philo)
{
	philo_take_fork(philo);
	pthread_mutex_lock(philo->deadcheck);
	philo->eat_cnt++;
	pthread_mutex_lock(philo->print);
	printf("%lld %d is eating\n", get_time() - philo->vars->time_of_start, philo->id);
	pthread_mutex_unlock(philo->print);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(philo->deadcheck);
	delay(philo->vars->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d is sleeping\n", get_time() - philo->vars->time_of_start, philo->id);
	pthread_mutex_unlock(philo->print);
	delay(philo->vars->time_to_sleep);
	return (0);
}

int	philo_think(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d is thinking\n", get_time() - philo->vars->time_of_start, philo->id);
	pthread_mutex_unlock(philo->print);
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
