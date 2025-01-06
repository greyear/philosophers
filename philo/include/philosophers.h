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
# include <string.h> //(memset)
# include <stdio.h> //(printf)
# include <stdlib.h> //(malloc, free)
# include <unistd.h> //(write, usleep)
# include <sys/time.h> //(gettimeofday)
# include <pthread.h> //(pthread_create, pthread_detach, pthread_join, pthread_mutex_init)

/*
int usleep(useconds_t usec);
usleep -  stops the execution of the calling thread for a specified number of microseconds
returns: 0 on success, or -1 on failure

int gettimeofday(struct timeval *tv, struct timezone *tz);
tv: pointer to a timeval structure to store the current time.
tz: pointer to a timezone structure (usually NULL).
gettimeofday - gets the current time and date.
returns: 0 on success, -1 on error

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
pthread_create - creates a new thread
thread: pointer to a pthread_t variable to hold the thread ID.
attr: pointer to a pthread_attr_t structure for thread attributes (or NULL).
start_routine: function to be executed by the thread.
arg: argument passed to the start routine.
returns: 0 on success, error code on failure

int pthread_detach(pthread_t thread);
pthread_detach detaches (turns off) a thread so that it can release resources automatically when it finishes execution
returns: 0 on success, error code on failure

int pthread_join(pthread_t thread, void **retval);
pthread_join - to wait for a thread to terminate (join it to the main) and extract its exit status
thread: thread to join (wait for).
retval: pointer to a variable where the exit status of the thread will be stored
returns: 0 on success, error code on failure

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
pthread_mutex_init initializes a mutex (mutual exclusion) lock
mutex: The mutex to initialize.
attr: Mutex attributes (or NULL).
returns: 0 on success, error code on failure

int pthread_mutex_destroy(pthread_mutex_t *mutex);
pthread_mutex_destroy destroys a mutex, releasing any resources it uses
mutex: The mutex to destroy.
returns: 0 on success, error code on failure

int pthread_mutex_lock(pthread_mutex_t *mutex);
pthread_mutex_lock locks a mutex, preventing other threads from accessing the shared resource
mutex: The mutex to lock.
returns: 0 on success, error code on failure

int pthread_mutex_unlock(pthread_mutex_t *mutex);
pthread_mutex_unlock unlocks a mutex, allowing other threads to access the shared resource
mutex: The mutex to unlock.
returns: 0 on success, error code on failure
*/

typedef struct s_res	t_res;

typedef struct s_args
{
	int				num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_must_eat;
}	t_args;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				meals_eaten;
	size_t			last_meal_time;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	t_args			*args;
	t_res			*res;
}	t_philo;

typedef struct s_res
{
	t_philo			*philos; //maybe **
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_t		monitor;
	//struct timeval	tv;
	t_args			*args;
	size_t			start;
}	t_res;

//Main
int		init_resourses(t_res *res);
int		create_threads(t_res *res);
int		join_threads(t_res *res);
int		thread_action(pthread_t *thread, void *(*routine)(void *),
			void *routine_arg, t_thread action);
int		mutex_action(pthread_mutex_t *mutex, t_mtx action);
void	*routine(void	*arg);
size_t	get_time(void);
int		wait_ms(size_t waiting_time);
void	message(t_philo *philo, t_oper oper);

//Utils
void	*ft_calloc(size_t count, size_t size);

//Validation
int		validation(int argc, char **argv, t_res *res);
int		ft_atoi(char *str, int *number);

//Errors
int		error_msg(int code);

//Cleaners
int		clean_resourses(t_res **res);

#endif
