
#include "../include/philosophers.h"


int thread_action(pthread_t *thread, void *(*routine)(void *),
	void *routine_arg, t_thread action)
{
	//проверка thread?
	if (action == CREATE)
	{
		if (pthread_create(thread, NULL, routine, routine_arg) != 0)
			return(error_msg(THRD_CRT));
	}
	if (action == JOIN)
	{
		if (pthread_join(*thread, NULL) != 0) //extra args(
			return (error_msg(THRD_JN));
	}
	return (0);
}

int mutex_action(pthread_mutex_t *mutex, t_mtx action)
{
	//проверка mutex?
	if (action == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			return(error_msg(MTX_INIT));
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