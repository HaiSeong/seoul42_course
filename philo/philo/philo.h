/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:04 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/20 10:22:13 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_info
{
	long long		start_time;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_must_eat;
	int				all_alive;
	pthread_mutex_t	*guard;
	pthread_mutex_t	*print;
}					t_info;

typedef struct s_philo
{
	int				num;
	long long		eat_time;
	int				eat_count;
	int				life;
	t_info			*info;
	int				*left_fork_value;
	int				*right_fork_value;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*guard;
	pthread_t		routine;
}					t_philo;

pthread_mutex_t	*fork_init(int philo_num);
int				*fork_value_init(int philo_num);

void			memory_free(t_philo *philo, t_info info, pthread_mutex_t *fork);

int				make_info(t_info *info, int ac, char *argv[]);

void			monitoring(t_info *info, t_philo **philo);

void			print_eating(t_philo *philo);
void			print_sleeping(t_philo *philo);
void			print_fork(t_philo *philo);

void			eatting(t_philo *philo);
void			sleeping(t_philo *philo);

void			take_left_fork(t_philo *philo);
void			take_right_fork(t_philo *philo);
void			put_fork(t_philo *philo);

int				philo_init(t_info *info, t_philo **philo, \
				pthread_mutex_t *fork, int *fork_value);

void			routine_start(t_philo **philo, t_info *info);
int				is_all_alive(t_info *info);
void			*routine(void *philo_data);

int				ft_error(char *str);
int				ft_error_free(char *str, t_info *info);
long long		get_time(void);
long long		relative_time(t_info *info);

#endif