#include "philo.h"

void	philo_print(t_philo *philo, int state)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d ", get_time() - philo->vars->time_of_start, philo->number);
	if (state == EAT)
	{
		printf("is eating\n");
	}
	else if (state == SLEEP)
		printf("is sleeping\n");
	else if (state == THINK)
		printf("is thinking\n");
	else if (state == FORK)
		printf("has taken fork\n");
	else if (state == DEAD)
	{
		printf("died\n");
		return ;
	}
	pthread_mutex_unlock(philo->print);
}

void	philo_take_fork(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		philo_print(philo, FORK);
		pthread_mutex_lock(philo->right_fork);
		philo_print(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo_print(philo, FORK);
		pthread_mutex_lock(philo->left_fork);
		philo_print(philo, FORK);
	}
}
