/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:45:17 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/13 19:56:43 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include "libft/libft.h"

# define THINK 0
# define EAT 1
# define SLEEP 2
# define DONE 3

typedef struct s_vars
{
	int				philo_number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				is_someone_dead;
	int				finish_number;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}	t_vars;

typedef struct s_philo
{
	int			id;
	int			status;
	int			cnt;
	int			left_fork;
	int			right_fork;
	long long	last_eat;
	pthread_t	thread_id;
	t_vars		*vars;
}	t_philo;

void	ft_error(char *msg);
void	ft_error_free(char *msg, t_vars *vars);
long long	milli_sec(struct timeval time);
int	get_time(t_vars *vars);

void init_vars(t_vars *vars, int argc, char *argv[]);


void	init_philo(t_philo *philo, t_vars *vars, int id);
void	*rootine(void *data);
void make_philo_thread(t_philo *philos, t_vars *vars);

void	make_philo_eat(t_philo *philo);
void	make_philo_sleep(t_philo *philo);
void	make_philo_think(t_philo *philo);

#endif
