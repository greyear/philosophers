/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:55:10 by azinchen          #+#    #+#             */
/*   Updated: 2024/12/30 14:55:12 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	allocate_fields(t_res *res)
{
	//malloc?
	res->philos = ft_calloc(res->args->num, sizeof(t_philo));
	if (!res->philos)
	{
		free(res->args);
		return (error_msg(MLLC));
	}
	res->forks = ft_calloc(res->args->num, sizeof(pthread_mutex_t));
	if (!res->forks)
	{
		free(res->args);
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
		res->philos[i].last_meal_time = res->start; //?
		res->philos[i].fork_l = &(res->forks[i]);
		res->philos[i].fork_r = &(res->forks[(i + 1) % res->args->num]);
		res->philos[i].res = res;
		i++;
	}
}

int	init_resourses(t_res *res)
{
	if (allocate_fields(res) != 0)
		return (1);
	if (init_mutex_fields(res) != 0)
		return (1);
	//others
	res->start = get_time(); //not here?
	init_philo(res);
	return (0);
}
