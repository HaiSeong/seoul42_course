#ifndef PHILO_H
# define PHILO_H

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4
# define FORK 5

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_vars	t_vars;

typedef struct s_philo{
	int				number;
	long long		last_eat_time;
	int				eat_cnt;
	pthread_t		thread;
	pthread_mutex_t	*print;
	pthread_mutex_t	*deadcheck;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_vars	*vars;
}	t_philo;

typedef struct s_vars{
	t_philo			*philo_arr;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long long		time_of_start;
	int				philo_eat;
	int				philo_dead;
	pthread_mutex_t	print;
	pthread_mutex_t	*deadcheck;
	pthread_mutex_t	*forks;
}	t_vars;

int			init_vars(t_vars *vars, int argc, char *argv[]);
int			ft_error(char *str);
int			ft_atoi(const char *str);

long long	get_time(void);
void		delay(long long time_to_sleep);

int			init_philo(t_vars *vars);
void		*philo_func(void *data);

void		philo_print(t_philo *philo, int state);
void		philo_take_fork(t_philo *philo);
#endif
