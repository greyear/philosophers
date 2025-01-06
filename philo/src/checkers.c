
#include "../include/philosophers.h"

int all_ate_enough(t_res *res)
{
	int	i;

	i = 0;
	while (i < res->args->num)
	{
		if (res->philos[i].meals_eaten < res->args->meals_must_eat)
			return (0);
		i++;
	}
	return (1);
}

int	death_happened(t_philo	*philo) //or put res and check all philos
{
	size_t	now;

	now = get_time();
	if (now - philo->last_meal_time >= philo->res->args->time_to_die)
	{
		//condition of mutex?
		//flag to stop everything
		message(philo, DEATH);
		return (1);
	}
	return (0);
}