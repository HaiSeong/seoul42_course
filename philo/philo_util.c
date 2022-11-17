#include "philo.h"

int	ft_error(char *str)
{
	printf("Error : %s\n", str);
	return 1;
}

long long	get_time(void)
{
	struct timeval	time;
	long long		ms;

	if (gettimeofday(&time, NULL) != 0)
		return (1);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

void	delay(long long time_to_sleep)
{
	long long	target_time;

	target_time = get_time() + time_to_sleep;
	while (target_time > get_time())
		usleep(100);
}
