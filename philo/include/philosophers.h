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

# include <limits.h>
# include <string.h> (memset)
# include <stdio.h> (printf)
# include <stdlib.h> (malloc, free)
# include <unistd.h> (write, usleep)
# include <sys/time.h> (gettimeofday)
# include <pthread.h> (pthread_create, pthread_detach, pthread_join, pthread_mutex_init)



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
pthread_join - to wait for a thread to terminate and extract its exit status
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

typedef struct s_args
{
	int	argc;
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;
}	t_args;

#endif
