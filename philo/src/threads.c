/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:55:49 by azinchen          #+#    #+#             */
/*   Updated: 2024/12/30 14:55:51 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"


/*typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	size_t			meals_eaten;
	size_t			last_meal_time;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	t_args			*args;
	t_res			*res;
}	t_philo;*/

int	create_threads(t_res *res)
{
	size_t	i;

	i = 0;
	while (i < res->args->num)
	{
		if (thread_action(&res->philos[i].thread, &routine,
				(void *)&res->philos[i], CREATE) != 0)
			{
				printf("--------- thread which failed to create is %zu\n", i);
				//always 9180 or 9178
				printf("Attempting to create thread for philosopher ID: %d\n", res->philos[i].id);
				printf("Attempting to create thread for philosopher meals_eaten: %zu\n", res->philos[i].meals_eaten);
				printf("Attempting to create thread for philosopher last_meal_time: %zu\n", res->philos[i].last_meal_time);
				printf("Thread pointer address: %p\n", (void *)&res->philos[i].thread);
				printf("Routine function address: %p\n", (void *)routine);
				printf("Philosopher struct address: %p\n", (void *)&res->philos[i]);
				return (1);
			}
		i++;
	}
	return (0);
}

int	join_threads(t_res *res)
{
	size_t	i;

	i = 0;
	//printf("------------------ %zu args->num\n", res->args->num);
	while (i < res->args->num)
	{
		if (thread_action(&res->philos[i].thread, &routine,
				(void *)&res->philos[i], JOIN) != 0)
			return (1);
		i++;
	}
	return (0);
}
