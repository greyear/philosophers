
#include "../include/philosophers.h"

static int	allocate_fields(t_res *res)
{
	res->philos = malloc(res->args->num * sizeof(t_philo));
	if (!res->philos)
		return (error_msg(MLLC));
	res->forks = malloc(res->args->num * sizeof(pthread_mutex_t));
	if (!res->forks)
	{
		free(res->philos);
		return (error_msg(MLLC));
	}
	return (0);
}

static int	init_mutex_fields(t_res *res)
{
	int	i;

	i = 0;
	while (i < res->args->num)
	{
		if (mutex_action(&(res->forks[i]), INIT) != 0)
			return (1);
		i++;
	}
	if (mutex_action(&(res->print), INIT) != 0)
		return (1);
	//another mutexes...
	return (0);
}

static void	init_philo(t_res *res)
{
	int	i;

	i = 0;
	while (i < res->args->num)
	{
		res->philos[i].id = i + 1;
		res->philos[i].meals_eaten = 0;
		res->philos[i].fork_l = &(res->forks[i]);
		res->philos[i].fork_r = &(res->forks[(i + 1) % res->args->num]);
		//add time of last meal
		//add everything else
		i++;
	}
}

/*typedef struct s_res
{
	pthread_mutex_t	*forks;
	t_philo			*philos; //maybe **
	pthread_mutex_t	print;
	pthread_t		monitor;
	struct timeval	tv;
	t_args			*args;
}	t_res;*/

int	init_resourses(t_res *res)
{
	if (allocate_fields(res) != 0)
		return (1);
	if (init_mutex_fields(res) != 0)
		return (1);
	//others
	init_philo(res);
	return (0);
}