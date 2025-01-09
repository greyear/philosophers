/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:46:48 by azinchen          #+#    #+#             */
/*   Updated: 2024/12/23 19:33:07 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "constants.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_res	t_res;

typedef struct s_args
{
	size_t			num;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			meals_must_eat;
}	t_args;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	size_t			meals_eaten;
	size_t			last_meal_time;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	t_args			*args;
	t_res			*res;
}	t_philo;

typedef struct s_res
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	size_t			num_full;
	int				flag_finish;
	pthread_mutex_t	print;
	t_args			*args;
	size_t			start;
}	t_res;

//Main
int		init_resourses(t_res *res);
int		create_threads(t_res *res);
int		join_threads(t_res *res, size_t limit);
int		thread_action(pthread_t *thread, void *(*routine)(void *),
			void *routine_arg, t_thread action);
int		mutex_action(pthread_mutex_t *mutex, t_mtx action);
void	*routine(void *arg);
void	check_for_finish(t_res *res);
size_t	get_time(void);
int		wait_ms(size_t waiting_time, t_res *res);
int		message(t_philo *philo, t_oper oper);
int		message_lock(t_philo *philo, t_oper oper);

//Utils
void	*ft_calloc(size_t count, size_t size);

//Validation
int		validation(int argc, char **argv, t_res *res);
int		ft_atoi(char *str, size_t *number);

//Errors
int		error_msg(int code);

//Cleaners
int		clean_destroy(t_res **res);
int		clean(t_res **res);
void	free_fields(t_res *res);
int		destroy_all_mutex_fields(t_res *res, size_t limit);
int		destroy_forks_mutex_fields(t_res *res, size_t limit);

#endif
