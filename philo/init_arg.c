#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	sum;

	sum = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (sum * sign);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

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
			if (!ft_isdigit(argv[index][i]) && argv[index][i] != '+')
				ft_error("You have wrong char in args");
			i++;
		}
		index++;
	}
}

int init_vars(t_vars *vars, int argc, char *argv[])
{
	check_args(argc, argv);
	vars->num_of_philos = ft_atoi(argv[1]);
	vars->time_to_die = ft_atoi(argv[2]);
	vars->time_to_eat = ft_atoi(argv[3]);
	vars->time_to_sleep = ft_atoi(argv[4]);
	vars->must_eat = -1;
	if (argc == 6)
		vars->must_eat = ft_atoi(argv[5]);
	if (vars->num_of_philos <= 0 || vars->time_to_die <= 0
		|| vars->time_to_eat <= 0 || vars->time_to_sleep <= 0 || vars->must_eat <= 0)
		return ft_error("argument have to be positive");
	vars->time_of_start = get_time();
	vars->philo_eat = 0;
	return (0);
}
