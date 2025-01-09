/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:54:43 by azinchen          #+#    #+#             */
/*   Updated: 2024/12/30 14:54:48 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	thread_action(pthread_t *thread, void *(*routine)(void *),
	void *routine_arg, t_thread action)
{
	if (action == CREATE)
	{
		if (pthread_create(thread, NULL, routine, routine_arg) != 0)
			return (error_msg(THRD_CRT));
	}
	if (action == JOIN)
	{
		if (pthread_join(*thread, NULL) != 0)
			return (error_msg(THRD_JN));
	}
	return (0);
}

int	mutex_action(pthread_mutex_t *mutex, t_mtx action)
{
	if (action == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			return (error_msg(MTX_INIT));
	}
	if (action == DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			return (error_msg(MTX_DSTR));
	}
	if (action == LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			return (error_msg(MTX_LCK));
	}
	if (action == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			return (error_msg(MTX_UNLCK));
	}
	return (0);
}
